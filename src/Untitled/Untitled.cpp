#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <istream>


#include <gl/gl.h>

#include "Untitled.h"
#include "Gamepad.h"

Gamepad MyGamepad = Gamepad(1);

void GetGamepadInput()
{
	MyGamepad.Update(); // Update the gamepad

	if (MyGamepad.GetButtonDown(XButtons.DPad_Right))
	{
		if (game.getMenuState())
			OnKeyDown('h', 0, 0);
	}
	if (MyGamepad.GetButtonDown(XButtons.DPad_Left))
	{
		if (game.getMenuState())
			OnKeyDown('h', 0, 0);
	}

	if (MyGamepad.GetButtonDown(XButtons.Back))
	{
		if (game.getMenuState())
			OnKeyDown(27, 0, 0);
	}

	if (MyGamepad.GetButtonDown(XButtons.Start))
	{
		if (!game.getMenuState())
			OnKeyDown(27, 0, 0);
		else
			OnKeyDown('n', 0, 0);
	}

	// Update the gamepad for next frame
	MyGamepad.RefreshState();
}
//ikona, poprawne czyszczenie po opengl. sad

std::vector <vec3> trees; // vector posiadaj?cy kordy drzew.

int main(int argc, char* argv[])
{
	srand(time(NULL));
	glutInit(&argc, argv);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 360);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Untitled I");
	glutDisplayFunc(OnRender);
	glutReshapeFunc(OnReshape);
	glutKeyboardFunc(OnKeyPress);
	glutKeyboardUpFunc(OnKeyUp);
	glutTimerFunc(17, OnTimer, 0);
	glutTimerFunc(1000, Time, 0);
	glutTimerFunc(100, RotateTime, 0);


#pragma region Oswietlenie
	const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_position[] = { 50.0f, 50.0f, 50.0f, 0.0f };
	const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	const GLfloat mat_specular[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	const GLfloat mat_shininess[] = { 100.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
#pragma endregion 

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_NORMALIZE);

	engine = irrklang::createIrrKlangDevice();
	//inicjalizacja danych do rozpocz?cia gry
	data.Load();
	draw.init(data);
	Sky.Load(45);
	game.init();

	glutMainLoop();

	return 0;
}


// Tablica przechowuj?ca stan klawiszy w formie flag, indeksowana wg kodów ASCII.
bool keystate[256];

// Obs?uga zdarzenia, gdy zostanie wci?ni?ty klawisz - zdarzenie nieoodporne na repetycj? klawiszy.
void OnKeyPress(unsigned char key, int x, int y) {
	printf("KeyPress: %c\n", key);
	if (!keystate[key]) {
		OnKeyDown(key, x, y); // Emulacja zdarzenia zwi?zanego z pojedynczym wci?ni?ciem klawisza
	}
	keystate[key] = true;
}

// Obs?uga naszego w?asnego zdarzenia, gdy zostanie po raz pierwszy wci?ni?ty klawisz - zdarzenie odporne na repetycj?.
void OnKeyDown(unsigned char key, int x, int y) {
	if (key == 27) {
		MyGamepad.Rumble(0, 0);
		if (game.getMenuState()) // je?eli w menu exit, je?eli nie w menu to uruchamiamy menu.
		{
			glDeleteLists(Mountain, 0);
			glDeleteLists(Floor, 0);
			glDeleteLists(Fence, 0);
			glDeleteLists(FenceBracket, 0);
			//			engine->drop();
			glutLeaveMainLoop();
		}
		else
		{
			engine->stopAllSounds();
			if (game.getPlaying())
				game.setPlaying();
			player.setMenuPos();
			game.setMenuState();
			glutTimerFunc(100, RotateTime, 0);
		}
	}
	if (key == 'n' || key == 'N') { // New Game. je?eli czas chodzi? to go zatrzymujemy.
		if (game.getCountDown())
			game.setCountDown();
		game.setMenuState();
		game.setGameStatus(Questions);	//zmieniamy statusy w grze. na pytania
		if (!game.getMove()) //umo?liwiamy poruszanie si? graczowi
			game.setMove();
		player.init(); // inicjalizujemy informacje o graczu do podstawowych
		engine->stopAllSounds();
		engine->play2D("Resources/game.mp3", true);
		game.reset(); // resetujemy status gry i czas
	}
	if (key == 'h' || key == 'H') {  // zmiana poziomów trudno?ci.
		switch (player.getMaxLevel())
		{
		case 6:
			player.setMaxLevel(8);
			break;
		case 8:
			player.setMaxLevel(12);
			break;
		case 12:
			player.setMaxLevel(16);
			break;
		case 16:
			player.setMaxLevel(6);
			break;
		default:;
		}
	}

#pragma region Develop utils
	//Noclip do poruszania si? po mapie bez hitboxów
	/*
	if (key == 'c' || key == 'C') {
	game.setNoclip();// Noclip = !Noclip;
	}
	*/

	//Funkcja zapisuj?ca aktualny stan vectora z drzewami do pliku.
	/*
	if (key == 'p' || key == 'P') {
	std::stringstream outputFileName;
	std::string FileName;
	outputFileName << "trees";
	outputFileName >> FileName;
	std::ofstream outputFile(FileName + ".txt");
	if (!outputFile.is_open())
	throw std::exception("Can't write to file");
	for (int i = 0; i < trees.size(); i++) {
	outputFile << trees[i].x << " ; " << trees[i].z << std::endl;
	}
	}
	*/

	//Funckja dodaj?ca x,z, do vectora drzew.
	/*
	if (key == 't' || key == 'T') {
	vec3 tmp;
	tmp.x = player.getPosX();
	tmp.y = 2.0f;
	tmp.z = player.getPosZ();
	trees.push_back(tmp);
	}
	*/
#pragma endregion 
}

// Obs?uga zdarzenia puszczenia klawisza.
void OnKeyUp(unsigned char key, int x, int y) {
	printf("KeyUp: %c\n", key);
	keystate[key] = false;
}

// Aktualizacja stanu gry - wywo?ywana za po?rednictwem zdarzenia-timera.
void OnTimer(int id) {
	GetGamepadInput();
	MyGamepad.Update(); // Update the gamepad

	if (angle < 360.0f)	angle += 0.1f;
	else angle = 0.0f;
	if (!game.getMenuState())
	{
		if (game.getMove()) {


			if (keystate['w'] || keystate['W'] || !MyGamepad.LStick_InDeadzone()) {
				if (data.Height[(int)(player.getPosZ() + player.getDirZ()*player.GetSpeed())][(int)(player.getPosX() + player.getDirX()*player.GetSpeed())] == 't')
				{
					//inicjalizacja czasu po wej?ciu w pierwszs? bramk? ( je?eli nie chodzi? to ma go uruchomi?)
					if (!game.getCountDown())
						game.setCountDown();

					game.setRenderNewLevel(); // renderujemy nowy poziom poniewa? gracz odpowiedzia? poprawnie
					player.setLevel(player.getLevel() + 1); // dodajemy poziom i przemieszczamy gracza na ?rodek mapy.
					player.setPosX(38.0f);
					player.setPosY(16.75f);
					player.setPosZ(38.0f);
					std::cout << "Poprawna odpowiedz !\n";
					game.setGameStatus(Correct);
					if (player.getLevel() != player.getMaxLevel())
						glutTimerFunc(1000, GameUpdate, 0);
					if (player.getLevel() == player.getMaxLevel()) // je?eli gracz osi?gnie maxymalny poziom to ko?czymy gr?.
					{
						game.setCountDown();            // zatrzymujemy czas
						game.setGameStatus(Won);        // status gry na wygrany
						game.setMove();					// gracz nie mo?e chodzi?.
						std::cout << "Wygrales!";		// logi w consoli.
						std::cout << "Czas gry: " << game.getHour() << ":" << game.getMin() << ":" << game.getSec() << "\n";
					}

				}
				// == f z?a odpowiedz
				else if (data.Height[(int)(player.getPosZ() + player.getDirZ()*player.GetSpeed())][(int)(player.getPosX() + player.getDirX()*player.GetSpeed())] == 'f')
				{

					//inicjalizacja czasu po wej?ciu w pierwszs? bramk?
					if (!game.getCountDown())
						game.setCountDown();

					//ustawienie danych dla gracza.
					player.setHealth(player.getHealth() - 1); //?ycie -1 i teleporujemy na ?rodek ekranu.
					player.setPosX(38.0f);
					player.setPosY(16.75f);
					player.setPosZ(38.0f);
					std::cout << "Bledna odpowiedz !\n";
					MyGamepad.Rumble(0.3f, 0.3f);
					game.setGameStatus(Wrong);
					if (player.getLevel() != player.getMaxLevel() && player.getHealth() > 0)
						glutTimerFunc(1000, GameUpdate, 0);
					if (player.getHealth() <= 0) // je?eli ?ycie gracza b?dzie <=0 to ko?czymy gr? 
					{
						std::cout << "GAME OVER!";
						game.setCountDown();            // zatrzymujemy czas
						game.setGameStatus(Lose);
						MyGamepad.Rumble(0.3f, 0.3f);
						game.setMove();
					}
				}
				//w ko?cu je?eli vector poruszania si? gracza wskazuj? na mo?liw? pozycj? w tablicy wtedy poruszamy si?. inaczej pomijamy ten krok (gracz stoi w miejscu).
				if (MyGamepad.Connected())
				{
					if (data.Height[(int)(player.getPosZ() + player.getDirZ()*player.GetSpeed())][(int)(player.getPosX() + player.getDirX()*player.GetSpeed())] == '1' || game.getNoclip())
					{
						player.setPosX(player.getPosX() + player.getDirX()*player.GetSpeed() *0.5* MyGamepad.LeftStick_Y());
						//	player.setPosY(player.getPosY() + player.getDirY()*player.GetSpeed());
						player.setPosZ(player.getPosZ() + player.getDirZ()*player.GetSpeed() *0.5* MyGamepad.LeftStick_Y());
					}

				}
				else
				{
					if (data.Height[(int)(player.getPosZ() + player.getDirZ()*player.GetSpeed())][(int)(player.getPosX() + player.getDirX()*player.GetSpeed())] == '1' || game.getNoclip())
					{
						player.setPosX(player.getPosX() + player.getDirX()*player.GetSpeed());
						//	player.setPosY(player.getPosY() + player.getDirY()*player.GetSpeed());
						player.setPosZ(player.getPosZ() + player.getDirZ()*player.GetSpeed());
					}
				}
			}

			if (keystate['s'] || keystate['S']) {//|| MyGamepad.LeftStick_X() < 0.2 && MyGamepad.LeftStick_Y() < -0.9) {
				if (data.Height[(int)(player.getPosZ() - player.getDirZ()*player.GetSpeed())][(int)(player.getPosX() - player.getDirX()*player.GetSpeed())] == '1' || game.getNoclip())
				{
					player.setPosX(player.getPosX() - player.getDirX()*player.GetSpeed());
					//player.setPosY(player.getPosY() - player.getDirY()*player.GetSpeed());
					player.setPosZ(player.getPosZ() - player.getDirZ()*player.GetSpeed());
				}
			}

			int speedo = 1;
			/// Left Right
			if (data.Height[(int)(player.getPosZ() + player.getDirZ()*player.GetSpeed()) - 1][(int)(player.getPosX() + player.getDirX()*player.GetSpeed()) - 1] == '1' || game.getNoclip())
				if (!MyGamepad.LStick_InDeadzone()) {//|| MyGamepad.LeftStick_X() > 0.7 && MyGamepad.LeftStick_X() < 1 && MyGamepad.LeftStick_Y() < 0.44 && MyGamepad.LeftStick_Y() >-0.73 ) {
					if (player.getDirX()>0.9 && player.getDirZ()<0.1)
					{
						player.setPosZ(player.getPosZ() + player.getDirX()*player.GetSpeed()* speedo * MyGamepad.LeftStick_X());
						player.setPosX(player.getPosX() + player.getDirZ()*player.GetSpeed() * speedo * MyGamepad.LeftStick_X());
					}
					else
					{
						if (player.getDirX()<-0.9 && player.getDirZ()<0.1)
						{
							player.setPosZ(player.getPosZ() + player.getDirX()*player.GetSpeed()*speedo * MyGamepad.LeftStick_X());
							player.setPosX(player.getPosX() + player.getDirZ()*player.GetSpeed() * speedo * MyGamepad.LeftStick_X());
						}
						else
						{
							player.setPosZ(player.getPosZ() + player.getDirX()*player.GetSpeed() * speedo * -MyGamepad.LeftStick_X());
							player.setPosX(player.getPosX() + player.getDirZ()*player.GetSpeed() * speedo * -MyGamepad.LeftStick_X());
						}
					}

				}

			if (keystate['d'] || keystate['D'] || MyGamepad.RightStick_X() > 0.9) {
				float phi = atan2(player.getDirZ(), player.getDirX());
				player.setDirX(cos(phi += .03f));
				player.setDirZ(sin(phi += .03f));
			}
			if (keystate['a'] || keystate['A'] || MyGamepad.RightStick_X() < -0.9) {
				float phi = atan2(player.getDirZ(), player.getDirX());
				player.setDirX(cos(phi -= .03f));
				player.setDirZ(sin(phi -= .03f));
			}

#pragma region Develop utils
			/*
			if (keystate['e']) {
			player.setPosY(player.getPosY() - 0.5f);
			}
			if (keystate['q']) {
			player.setPosY(player.getPosY() + 0.5f);
			}
			if (keystate['z'] || !MyGamepad.RStick_InDeadzone()) {
			player.setDirY(player.getDirY() + MyGamepad.RightStick_Y() / 20);
			}
			*/
#pragma endregion 
		}
	}
	MyGamepad.RefreshState();
	// Chcemy, by ta funkcja wywolala sie ponownie za 17ms.
	glutTimerFunc(17, OnTimer, 0);
}

// Aktualizacja timera do obliczania d?ugo?ci rozgrywki.
void Time(int id)
{

	if (game.getCountDown())
	{
		game.set_sec(game.getSec() + 1);
		if (game.getSec() == 60)  // 60 sec == 1min etc.
		{
			game.set_min(game.getMin() + 1);
			game.set_sec(0);
		}
		if (game.getMin() == 60)
		{
			game.set_hour(game.getHour() + 1);
			game.set_min(0);
		}
	}
	glutTimerFunc(1000, Time, 0); // co 1 sec.
}

void GameUpdate(int id)
{
	game.setGameStatus(Questions);
	MyGamepad.Rumble(0, 0);
	engine->stopAllSounds();
	engine->play2D("Resources/game.mp3", true);
	game.setPlaying();
}

// Aktualizacja obrotu kamery w menu.
void RotateTime(int id)
{
	//skopiowana funkcja z poruszania gracza.
	float phi = atan2(player.getDirZ(), player.getDirX());
	player.setDirX(cos(phi += .001f));
	player.setDirZ(sin(phi += .001f));
	if (game.getMenuState())
		glutTimerFunc(10, RotateTime, 0); // p?ynniejsza rotacja kamery.
};

void OnRender() {
	//G?ówne renderowanie!

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Ustawienie kamery na podstawie jej stanu przechowywanego w zmiennej player.
	gluLookAt(
		player.getPosX(), player.getPosY(), player.getPosZ(), // Pozycja kamery
		player.getPosX() + player.getDirX(), player.getPosY() + player.getDirY(), player.getPosZ() + player.getDirZ(), // Punkt na ktory patrzy kamera (pozycja + kierunek)
		0.0f, 1.0f, 0.0f // Wektor wyznaczajacy pion
		);

	//g?ówna funkcja renderuj?ca gr?.
	game.render();

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();

}//END OnRender();

void OnReshape(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(60.0f, (float)width / height, .01f, 100.0f);
}