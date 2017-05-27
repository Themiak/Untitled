#include "stdafx.h"
#include "Game.h"
#include "sstream"
#include "ctime"

Game::Game()
{

}

Game::~Game()
{
}
void Game::makeBridge(char direction)
{
#pragma region  Czyszczenie hitboxów
	player.setLastBridge(direction);
	for (int i = 0; i < 75; i++) {
		for (int j = 0; j < 75; j++) {
			data.Height[i][j] = HitBox[i][j]; // tak na prawdê powinno byæ odwrotnie.
		}
	}
#pragma endregion 

#pragma region Sprawdzanie poprawnej odpowiedzi w pytaniu i zadeklarowaniu jej w hitboxach
	int CorrectAnswer = 0;
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			if (player.Questions[player.getLevel() - 1].A.correct == true)
				CorrectAnswer = 21;
			break;
		case 1:
			if (player.Questions[player.getLevel() - 1].B.correct == true)
				CorrectAnswer = 31;
			break;
		case 2:
			if (player.Questions[player.getLevel() - 1].C.correct == true)
				CorrectAnswer = 41;
			break;
		case 3:
			if (player.Questions[player.getLevel() - 1].D.correct == true)
				CorrectAnswer = 51;
			break;
		default:;
		}
	}
#pragma endregion 

#pragma region  Rysowanie mostów w odpowiednich miejscach NSWE
	glPushMatrix();
	switch (direction)
	{
	case 'N':
#pragma region  Ustawienie hitboxów i mostow "N"
		for (int k = 20; k < 60;)
		{
			for (int i = 0; i <= 13; i++)
			{
				for (int j = 1; j < 5; j++)
				{
					if (i==13)
					{
						data.Height[i][k-1] = '0';
						data.Height[i][k] = '0';
						data.Height[i][k+5] = '0';
						data.Height[i][k+6] = '0';
					}else if (i == 0)
						if (k + 1 >= CorrectAnswer && k + 1 <= CorrectAnswer + 3)
							data.Height[i][k + j] = 't';
						else
							data.Height[i][k + j] = 'f';
					else
						data.Height[i][k + j] = '1';
				}
			}
			k += 10;
		}

#pragma endregion 
		glTranslatef(0, 0, 0.5);
		break;
	case 'E':
		glRotatef(-90, 0.0f, 1.0f, 0.0f);
		glTranslatef(4, 0, -39.0);
#pragma region  Ustawienie hitboxów i mostow "E"
		for (int k = 20; k < 60;)
		{
			for (int i = 74; i >= 61; i--)
			{
				for (int j = 1; j < 5; j++)
				{
					if (i == 61)
					{
						data.Height[k-1][i] = '0';
						data.Height[k][i] = '0';
						data.Height[k + 5][i] = '0';
						data.Height[k + 6][i] = '0';
					}else if (i == 74)
						if (k + 1 >= CorrectAnswer && k + 1 <= CorrectAnswer + 3)
							data.Height[k + j][i] = 't';
						else
							data.Height[k + j][i] = 'f';
					else
						data.Height[k + j][i] = '1';
				}
			}
			k += 10;
		}
#pragma endregion 
		break;
	case 'S':
		glRotatef(-180, 0.0f, 1.0f, 0.0f);
		glTranslatef(-36, 0, -42.5);
#pragma region  Ustawienie hitboxów i mostow "S"
		switch (CorrectAnswer) {
		case 21:
			CorrectAnswer = 51;
			break;
		case 31:
			CorrectAnswer = 41;
			break;
		case 41:
			CorrectAnswer = 31;
			break;
		case 51:
			CorrectAnswer = 21;
			break;
		default:;
		}
		for (int k = 20; k < 60;)
		{
			for (int i = 74; i >= 61; i--)
			{
				for (int j = 1; j < 5; j++)
				{
					if (i == 61)
					{
						data.Height[i][k-1] = '0';
						data.Height[i][k] = '0';
						data.Height[i][k + 5] = '0';
						data.Height[i][k + 6] = '0';
					}else if (i == 74)
						if (k + 1 >= CorrectAnswer && k + 1 <= CorrectAnswer + 3)
							data.Height[i][k + j] = 't';
						else
							data.Height[i][k + j] = 'f';
					else
						data.Height[i][k + j] = '1';
				}
			}
			k += 10;
		}
#pragma endregion 
		break;
	case 'W':
		glRotatef(-270, 0.0f, 1.0f, 0.0f);
		glTranslatef(-40.0f, 0.0f, -3.0f);
#pragma region  Ustawienie hitboxów i mostów "W"
		switch (CorrectAnswer) {
		case 21:
			CorrectAnswer = 51;
			break;
		case 31:
			CorrectAnswer = 41;
			break;
		case 41:
			CorrectAnswer = 31;
			break;
		case 51:
			CorrectAnswer = 21;
			break;
		default:;
		}
		for (int k = 20; k < 60;)
		{
			for (int i = 0; i <= 13; i++)
			{
				for (int j = 1; j < 5; j++)
				{
					if (i == 13)
					{
						data.Height[k-1][i] = '0';
						data.Height[k][i] = '0';
						data.Height[k + 5][i] = '0';
						data.Height[k + 6][i] = '0';
					}else if (i == 0)
						if (k + 1 >= CorrectAnswer && k + 1 <= CorrectAnswer + 3)
							data.Height[k + j][i] = 't';
						else
							data.Height[k + j][i] = 'f';
					else
						data.Height[k + j][i] = '1';
				}
			}
			k += 10;
		}
#pragma endregion 
		break;
	default:;
	}
	for (int i = 0; i < 4; i++)
	{
		glPushMatrix();
		switch (i)
		{
		case 0:
			draw.drawbridge(data.GetID(IMG_A));
			break;
		case 1:
			draw.drawbridge(data.GetID(IMG_B));
			break;
		case 2:
			draw.drawbridge(data.GetID(IMG_C));
			break;
		case 3:
			draw.drawbridge(data.GetID(IMG_D));
			break;
		default:;
		};
		glPopMatrix();
		glTranslatef(10, 0, 0);
	}
#pragma endregion 

#pragma region  Rysowanie teleportów w odpowiednich miejscach NSWE
	switch (direction)
	{
	case 'N': // DONE
		glTranslatef(-40.0, 0, -0.5);
		break;
	case 'E': // DONE
		glTranslatef(-40.0, 0, 0.5);
		break;
	case 'S': //DONE
		glRotatef(-90, 0.0f, 1.0f, 0.0f);
		glRotatef(-90, 0.0f, 1.0f, 0.0f);
		glTranslatef(4, 0, 33);
		break;
	case 'W':
		glTranslatef(-40.0f, 0.0f, 0.5f);
		break;
	default:;
	}
	for (int i = 0; i < 4; i++)
	{
		glPushMatrix();
		glTranslatef(3.25, -2, -23);
		glRotatef(angle, 0, 0, 1);
		draw.drawTeleport();
		glPopMatrix();
		glTranslatef(10, 0, 0);
	}
	glPopMatrix();
#pragma endregion 

}
void Game::setNoclip()
{ Noclip = !Noclip; }
void Game::setCountDown()
{ CountDown = !CountDown; }
bool Game::getCountDown()
{ return CountDown; }
bool Game::getNoclip()
{ return Noclip; }
int Game::getHour() const
{ return hour;}
void Game::set_hour(int hour)
{this->hour = hour;}
int Game::getMin() const
{
	return min;
}
void Game::set_min(int min)
{
	this->min = min;
}
int Game::getSec() const
{
	return sec;
}
void Game::set_sec(int sec)
{
	this->sec = sec;
}
void Game::setRenderNewLevel()
{ renderNewLevel = !renderNewLevel; }
bool Game::getMenuState()
{ return menu; }
void Game::setMenuState()
{ menu = !menu; }
void Game::setGameStatus(GameStatus a)
{ status = a; }
GameStatus Game::getGameStatus()
{ return status; }
bool Game::getMove()
{ return Move; }
void Game::setMove()
{ Move = !Move; }
void Game::reset()
{
	status = Questions;
	hour = 0;
	min = 0;
	sec = 0;
	shuffle();
}
void Game::newLevel()
{
	srand(time(NULL));
	if (!renderNewLevel)
		makeBridge(player.getlastBridge());
	else
	{
		auto a = rand() % 4;
		switch (a)
		{
		case 0:
			makeBridge('N');
			player.setDirX(0);
			player.setDirZ(-1);
			break;
		case 1:
			makeBridge('S');
			player.setDirX(-0);
			player.setDirZ(1);
			break;
		case 2:
			makeBridge('E');
			player.setDirX(1);
			player.setDirZ(0);
			break;
		case 3:
			makeBridge('W');
			player.setDirX(-1);
			player.setDirZ(0);
			break;
		default:;
		}
		renderNewLevel = false;
	}
};
void Game::init()
{
	if (menu)
	{
		player.setDirX(0.24369f);
		player.setDirY(-0.35f);
		player.setDirZ(0.97f);
		player.setPosY(25.0f);
	}
	status = Questions;

	//ustawienie czasu na 0, nie dzia³a³o poprzez u¿ycie listy inicjalizacyjnej.
	hour = 0;
	min = 0;
	sec = 0;
	int a;

	//Ustawienie randomowych pytañ dla gracza.
	for (int i = 0; i < player.getMaxLevel();)
	{
		a = rand() % data.ammoutOfQuestions;
		if (!data.UsedQuestions[a])
		{
			player.Questions.push_back(data.Questions[a]);
			data.UsedQuestions[a] = true;
			i++;
		}
	}
	//inicjalizacja tablicy pustej bez mostów aby mo¿na by³o odtworzyæ j¹ póŸniej przy zmianie mostów
	for (int i = 0; i < 75; i++) {
		for (int j = 0; j < 75; j++) {
			HitBox[i][j] = data.Height[i][j];
		}
	}
}
void Game::shuffle()
{
	data.resetQuestions();
	player.Questions.clear();
	player.Reset();
	int a;
	for (int i = 0; i < player.getMaxLevel();)
	{
		a = rand() % data.ammoutOfQuestions;
		if (!data.UsedQuestions[a])
		{
			player.Questions.push_back(data.Questions[a]);
			data.UsedQuestions[a] = true;
			i++;
		}
	}
}
void Game::render()
{
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	Sky.Draw(data.GetID(IMG_SKY), player.getPosX(), player.getPosY(), player.getPosZ());
	glEnable(GL_DEPTH_TEST);

	// W³¹czamy teksturowanie
	glEnable(GL_TEXTURE_2D);

	// Ustawienie sposobu teksturowania - GL_MODULATE sprawia, ¿e œwiat³o ma wp³yw na teksturê; GL_DECAL i GL_REPLACE rysuj¹ teksturê tak jak jest
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	// Ustawienie materia³u
	float m_amb[] = { 2.0f, 2.0f, 2.0f, 2.0f };
	float m_dif[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float m_spe[] = { 2.0f, 2.0f, 2.0f, 2.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, m_spe);

	if (menu)
	{
		glPushMatrix();
		glTranslatef(40, -2, 40);
		glCallList(Floor);
		glPopMatrix();
	glEnable(GL_LIGHTING);
		glPushMatrix();
		glCallList(Mountain);
		glPopMatrix();

		glEnable(GL_LIGHTING);
		glTranslatef(20, 18, 16.5);

		makeBridge('N');
		makeBridge('S');
		makeBridge('W');
		makeBridge('E');

		DrawMENU();
	}
	else
	{
		glPushMatrix();
		glTranslatef(40, -2, 40);
		glCallList(Floor);
		glPopMatrix();

		glPushMatrix();
		glCallList(Mountain);
		glPopMatrix();

		glEnable(GL_LIGHTING);
		glTranslatef(20, 18, 16.5);

		newLevel();

		DrawGUI();
	}
}
void Game::DrawGUI()
{
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 32, 32, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_CULL_FACE);

	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);

	int x = 40;
	int y = 56;
	std::stringstream a;
	/*if (playing == false)
	{
		playing = !playing;
		engine->setSoundVolume(0.5);
		engine->play2D("Resources/game.mp3", true);
	}*/
		switch(status)
		{
		case Questions:
#pragma region Questions
			//if (playing)
			//{
			//	playing = !playing;
			//	engine->setSoundVolume(0.1);
			//	engine->play2D("Resources/game.mp3", true);
			//}
			glColor3f(0.0f, 0.0f, 0.0f);
			a << "Poziom: " << player.getLevel() << "/" << player.getMaxLevel();
			draw.drawText(x, y, a.str());
			a.str("");
			y -= 7;
			a << "Czas: " << hour << ":" << min << ":" << sec;
			draw.drawText(x, y, a.str());

			x = -62;
			y = 56;
			a.str("");
			a << "Zycie: " << player.getHealth();
			draw.drawText(x, y, a.str());
/*
			y -= 20;
			a.str("");
			a << "Dir X :" << player.getDirX() << " Dir Y :" << player.getDirY() << " Dir Z :" <<player.getDirZ();
			draw.drawText(x, y, a.str());
			y -= 8;
			a.str("");
			a << "Pos X :" << player.getPosX() << " Pos Y :" << player.getPosY() << " Pos Z :" <<player.getPosZ();
			draw.drawText(x, y, a.str());
*/



			x = -35;
			y = 58;
			a.str("");
			a << player.Questions[player.getLevel() - 1].question;
			draw.drawText(x, y, a.str());
			y = y - 7;
			a.str("");
			a << "A) " << player.Questions[player.getLevel() - 1].A.answerABCD;
			draw.drawText(x, y, a.str());
			x = 0;
			a.str("");
			a << "B) " << player.Questions[player.getLevel() - 1].B.answerABCD;
			draw.drawText(x, y, a.str());
			x = -35;
			y = y - 7;
			a.str("");
			a << "C) " << player.Questions[player.getLevel() - 1].C.answerABCD;
			draw.drawText(x, y, a.str());
			x = 0;
			a.str("");
			a << "D) " << player.Questions[player.getLevel() - 1].D.answerABCD;
			draw.drawText(x, y, a.str());
			glColor3f(255.0f, 255.0f, 255.0f);

			glTranslatef(-0.6f, 2.65f, 0.0f);
			glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_HEALTH));
			for (int i = 0; i < player.getHealth(); i++)
			{
				glTranslatef(1.0f, 0.0f, 0.0f);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex2f(0.9f, 0.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex2f(0.9f, 1.5f);
				glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 1.5f);
				glEnd();

			}
			break;
#pragma endregion 
		case Won:
			if (playing)
			{
				engine->stopAllSounds();
				playing = !playing;
				engine->setSoundVolume(0.5);
				engine->play2D("Resources/VictoryMusic.mp3",true);
			}
			glPushMatrix();
			glTranslatef(7, 7, 0);
			glCallList(win);
			x = -16;
			y = -32;
			glColor3f(0, 0, 0);
			a << "Twoj czas to:  " << hour << ":" << min << ":" << sec;
			draw.drawText(x, y, a.str(),1);
			glColor3f(255, 255, 255);
			glPopMatrix();
			break;
		case Lose:
			glPushMatrix();
			glTranslatef(7, 7, 0);
			glCallList(lose);
			x = -16;
			y = -32;
			if (playing)
			{
				engine->stopAllSounds();
				playing = !playing;
				engine->play2D("Resources/Night_Sounds.mp3", true);
			}
			glColor3f(0, 0, 0);
			a << "Twoj czas to: " << hour << ":" << min << ":" << sec;
			draw.drawText(x, y, a.str(), 1);
			glColor3f(255, 255, 255);
			glPopMatrix();
			break;
		case Correct:
			if (playing)
			{
				playing = false;
				engine->stopAllSounds();
				engine->play2D("Resources/correct.mp3");
			}
			glPushMatrix();
			glTranslatef(7, 7, 0);
			glCallList(correct);
			glPopMatrix();
			break;
		case Wrong:
			if (playing)
			{
				playing = false;
				engine->stopAllSounds();
				engine->play2D("Resources/wrong.mp3");
			}
			glPushMatrix();
			glTranslatef(7, 7, 0);
			glCallList(wrong);
			glPopMatrix();
			break;
		default:;
		}

	glDisable(GL_BLEND);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
}
void Game::DrawMENU()
{
	if (!playing)
	{
		playing = !playing;
		engine->setSoundVolume(0.5);
		engine->play2D("Resources/menu.mp3", true);
	}
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 32, 32, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_CULL_FACE);

	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);

	

	glTranslatef(9, 2.0f, 0.0f);
	glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_LOGO));
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(14.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(14.0f, 7.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 7.0f);
	glEnd();
	glPopMatrix();
	glTranslatef(2.5f, 7.0f, 0.0f);
	switch (player.getMaxLevel())
	{
	case 6:
		glCallList(MenuEasy);
		break;
	case 8:
		glCallList(MenuNormal);
		break;
	case 12:
		glCallList(MenuHard);
		break;
	case 16:
		glCallList(MenuVeryHard);
		break;
	default:;
	}

		
	glDisable(GL_BLEND);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
}