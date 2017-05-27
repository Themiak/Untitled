#include "stdafx.h"
#include "Draw.h"

#pragma region Tablice do drzew.
bool treeLayer1[5][5] = { { 0,1,1,1,1 },
{ 1,0,0,0,1 },
{ 1,0,0,0,1 },
{ 1,0,0,0,1 },
{ 0,1,1,1,0 } };
bool treeLayer2[5][5] = { { 0,1,1,1,0 },
{ 1,0,0,0,1 },
{ 1,0,0,0,1 },
{ 1,1,0,1,1 },
{ 0,1,1,1,0 } };
bool treeLayer3[5][5] = { { 0,0,0,0,0 },
{ 0,1,1,1,0 },
{ 0,1,0,1,0 },
{ 0,0,1,0,0 },
{ 0,0,0,0,0 } };
bool treeLayer4[5][5] = { { 0,0,0,0,0 },
{ 0,0,1,0,0 },
{ 0,1,1,1,0 },
{ 0,0,1,0,0 },
{ 0,0,0,0,0 } };


bool tree2Layer0[3][3] = { { 0,1,0 },
						   { 1,0,1 },
						   { 0,1,0 } };
bool tree2Layer1[3][3] = { { 0,0,0 },
{ 0,1,0 },
{ 0,0,0 } };

bool tree3Layer0[5][5] = { { 0,0,0,0,0 },
						   { 0,0,1,0,0 },
						   { 0,1,1,1,0 },
						   { 0,0,1,0,0 },
						   { 0,0,0,0,0 } };
bool tree3Layer1[5][5] = { { 0,1,1,1,0 },
						   { 1,1,1,1,1 },
						   { 1,1,0,1,1 },
						   { 1,1,1,1,0 },
						   { 0,1,1,1,0 } };
bool tree3Layer2[5][5] = { { 0,0,0,0,0 },
						   { 0,0,0,0,0 },
						   { 0,0,1,0,0 },
						   { 0,0,0,0,0 },
						   { 0,0,0,0,0 } };
#pragma endregion

Draw::~Draw()
{
}
void Draw::init(Data data)
{
#pragma region  Tworzenie display listy dla podlogi
	Floor = glGenLists(1);

	glNewList(Floor, GL_COMPILE);
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_FLOOR));
		glBegin(GL_QUADS);

		glTexCoord2f(0.0, 0.0);
		glVertex3f(-90, 1.0, 90);

		glTexCoord2f(1.0, 0.0);
		glVertex3f(90, 1.0, 90);

		glTexCoord2f(1.0, 1.0);
		glVertex3f(90, 1.0, -90);

		glTexCoord2f(0.0, 1.0);
		glVertex3f(-90, 1.0, -90);

		glEnd();
	glPopMatrix();
	glPushMatrix();

	glEnable(GL_LIGHTING);
		glTranslatef(-40, 0, -40);
		for (auto a : trees)
		{
			glPushMatrix();
			glTranslatef(a.x, -5, a.z);
			drawTree(data.GetID(IMG_LOG_SPRUCE), data.GetID(IMG_LEAVES_SPRUCE));
			glPopMatrix();
		}
	glDisable(GL_LIGHTING);
	glPopMatrix();

	glEndList();
#pragma endregion


	MenuEasy = glGenLists(1);

	glNewList(MenuEasy, GL_COMPILE);
	glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_MENU_EASY));
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(9.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(9.0f, 18.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 18.0f);
	glEnd();
	glPopMatrix();

	glEndList();

	MenuNormal = glGenLists(1);

	glNewList(MenuNormal, GL_COMPILE);
	glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_MENU_NORMAL));
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(9.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(9.0f, 18.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 18.0f);
	glEnd();
	glPopMatrix();

	glEndList();

	MenuHard = glGenLists(1);

	glNewList(MenuHard, GL_COMPILE);
	glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_MENU_HARD));
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(9.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(9.0f, 18.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 18.0f);
	glEnd();
	glPopMatrix();

	glEndList();

	MenuVeryHard = glGenLists(1);

	glNewList(MenuVeryHard, GL_COMPILE);
	glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_MENU_VERY_HARD));
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(9.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(9.0f, 18.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 18.0f);
	glEnd();
	glPopMatrix();

	glEndList();

	win = glGenLists(1);

	glNewList(win, GL_COMPILE);

	glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_WIN));
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(18.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(18.0f, 9.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 9.0f);
	glEnd();
	glPopMatrix();

	glEndList();

	lose = glGenLists(1);

	glNewList(lose, GL_COMPILE);
	glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_LOSE));
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(18.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(18.0f, 9.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 9.0f);
	glEnd();
	glPopMatrix();

	glEndList();

	correct = glGenLists(1);

	glNewList(correct, GL_COMPILE);
	glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_CORRECT));
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(18.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(18.0f, 9.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 9.0f);
	glEnd();
	glPopMatrix();

	glEndList();

	wrong = glGenLists(1);

	glNewList(wrong, GL_COMPILE);
	glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_WRONG));
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(18.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(18.0f, 9.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 9.0f);
	glEnd();
	glPopMatrix();

	glEndList();

#pragma region  Tworzenie display listy dla góry
	Mountain = glGenLists(1);
	glNewList(Mountain, GL_COMPILE);
	glPushMatrix();

	glPushMatrix();
#pragma region Rysowanie poziomu 0.
	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 40; j++) {
			if (data.Level0[i][j] == '1')
			{
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_SIDE));
				glBegin(GL_QUADS);		// Draw The Cube Using quads
										//front
				glTexCoord2f(0.0, 1.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(-1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(1.0, 1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(-1.0, 1.0, 1.0);

				glEnd();
				// top
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_TOP));
				glBegin(GL_QUADS);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0, 1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0, 1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, 1.0, -1.0);

				glEnd();

				// back	
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_SIDE));
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 1.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(-1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(1.0, 1.0, -1.0);

				// bottom
				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0, -1.0, 1.0);
				// left
				glTexCoord2f(0.0, 1.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, 1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, 1.0, -1.0);
				// right
				glTexCoord2f(0.0, 1.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, 1.0, 1.0);

				glEnd();			// End Drawing The Cub
			}
			if (data.Level0[i][j] == '2')
			{
				glDisable(GL_CULL_FACE);
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_DIRT));
				glBegin(GL_QUADS);		// Draw The Cube Using quads
										//front
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, 1.0);
				// top
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, 1.0, 1.0);

				// back
				glNormal3f(0.0f, 0.0f, -1.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);

				// bottom
				glNormal3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				// left
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(-1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				// right
				glNormal3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(1.0, 1.0, 1.0);
				glEnd();			// End Drawing The Cube	
			}
			glTranslatef(2, 0, 0);
		}
		glTranslatef(-80, 0, 2);
	}
#pragma endregion
	glPopMatrix();

	glTranslatef(0, 2, 0);

	glPushMatrix();
#pragma region Rysowanie poziomu 1.
	glTranslatef(-4, 0, 0);
	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 40; j++) {
			if (data.Level1[i][j] == '1')
			{
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_SIDE));
				glBegin(GL_QUADS);		// Draw The Cube Using quads
										//front
				glTexCoord2f(0.0, 1.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(-1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(1.0, 1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(-1.0, 1.0, 1.0);

				glEnd();
				// top
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_TOP));
				glBegin(GL_QUADS);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0, 1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0, 1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, 1.0, -1.0);

				glEnd();

				// back	
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_SIDE));
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 1.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(-1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(1.0, 1.0, -1.0);

				// bottom
				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0, -1.0, 1.0);
				// left
				glTexCoord2f(0.0, 1.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, 1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, 1.0, -1.0);
				// right
				glTexCoord2f(0.0, 1.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, 1.0, 1.0);

				glEnd();			// End Drawing The Cub
			}
			if (data.Level1[i][j] == '2')
			{
				glDisable(GL_CULL_FACE);
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_DIRT));
				glBegin(GL_QUADS);		// Draw The Cube Using quads
										//front
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, 1.0);
				// top
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, 1.0, 1.0);

				// back
				glNormal3f(0.0f, 0.0f, -1.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);

				// bottom
				glNormal3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				// left
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(-1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				// right
				glNormal3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(1.0, 1.0, 1.0);
				glEnd();			// End Drawing The Cube	
			}
			glTranslatef(2, 0, 0);
		}
		glTranslatef(-80, 0, 2);
	}
#pragma endregion
	glPopMatrix();

	glTranslatef(0, 2, 0);

	glPushMatrix();
#pragma region Rysowanie pozomu 2.
	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 40; j++) {
			if (data.Level2[i][j] == '1')
			{
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_SIDE));
				glBegin(GL_QUADS);		// Draw The Cube Using quads
										//front
				glTexCoord2f(0.0, 1.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(-1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(1.0, 1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(-1.0, 1.0, 1.0);

				glEnd();
				// top
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_TOP));
				glBegin(GL_QUADS);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0, 1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0, 1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, 1.0, -1.0);

				glEnd();

				// back	
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_SIDE));
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 1.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(-1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(1.0, 1.0, -1.0);

				// bottom
				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0, -1.0, 1.0);
				// left
				glTexCoord2f(0.0, 1.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, 1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, 1.0, -1.0);
				// right
				glTexCoord2f(0.0, 1.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, 1.0, 1.0);

				glEnd();			// End Drawing The Cub
			}
			if (data.Level2[i][j] == '2')
			{
				glDisable(GL_CULL_FACE);
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_DIRT));
				glBegin(GL_QUADS);		// Draw The Cube Using quads
										//front
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, 1.0);
				// top
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, 1.0, 1.0);

				// back
				glNormal3f(0.0f, 0.0f, -1.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);

				// bottom
				glNormal3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				// left
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(-1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				// right
				glNormal3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(1.0, 1.0, 1.0);
				glEnd();			// End Drawing The Cube	
			}
			glTranslatef(2, 0, 0);
		}
		glTranslatef(-80, 0, 2);
	}
#pragma endregion
	glPopMatrix();

	glTranslatef(0, 2, 0);

	glPushMatrix();
#pragma region Rysowanie poziomu 3.
	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 40; j++) {
			if (data.Level3[i][j] == '1')
			{
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_SIDE));
				glBegin(GL_QUADS);		// Draw The Cube Using quads
										//front
				glTexCoord2f(0.0, 1.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(-1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(1.0, 1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(-1.0, 1.0, 1.0);

				glEnd();
				// top
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_TOP));
				glBegin(GL_QUADS);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0, 1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0, 1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, 1.0, -1.0);

				glEnd();

				// back	
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_SIDE));
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 1.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(-1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(1.0, 1.0, -1.0);

				// bottom
				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0, -1.0, 1.0);
				// left
				glTexCoord2f(0.0, 1.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, 1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, 1.0, -1.0);
				// right
				glTexCoord2f(0.0, 1.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, 1.0, 1.0);

				glEnd();			// End Drawing The Cub
			}
			if (data.Level3[i][j] == '2')
			{
				glDisable(GL_CULL_FACE);
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_DIRT));
				glBegin(GL_QUADS);		// Draw The Cube Using quads
										//front
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, 1.0);
				// top
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, 1.0, 1.0);

				// back
				glNormal3f(0.0f, 0.0f, -1.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);

				// bottom
				glNormal3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				// left
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(-1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				// right
				glNormal3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(1.0, 1.0, 1.0);
				glEnd();			// End Drawing The Cube	
			}
			glTranslatef(2, 0, 0);
		}
		glTranslatef(-80, 0, 2);
	}
#pragma endregion
	glPopMatrix();

	glTranslatef(0, 2, 0);

	glPushMatrix();
#pragma region Rysowanie poziomu 4.
	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 40; j++) {
			if (data.Level4[i][j] == '1')
			{
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_SIDE));
				glBegin(GL_QUADS);		// Draw The Cube Using quads
										//front
				glTexCoord2f(0.0, 1.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(-1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(1.0, 1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(-1.0, 1.0, 1.0);

				glEnd();
				// top
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_TOP));
				glBegin(GL_QUADS);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0, 1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0, 1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, 1.0, -1.0);

				glEnd();

				// back	
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_SIDE));
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 1.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(-1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(1.0, 1.0, -1.0);

				// bottom
				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0, -1.0, 1.0);
				// left
				glTexCoord2f(0.0, 1.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, 1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, 1.0, -1.0);
				// right
				glTexCoord2f(0.0, 1.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, 1.0, 1.0);

				glEnd();			// End Drawing The Cub
			}
			if (data.Level4[i][j] == '2')
			{
				glDisable(GL_CULL_FACE);
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_DIRT));
				glBegin(GL_QUADS);		// Draw The Cube Using quads
										//front
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, 1.0);
				// top
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, 1.0, 1.0);

				// back
				glNormal3f(0.0f, 0.0f, -1.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);

				// bottom
				glNormal3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				// left
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(-1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				// right
				glNormal3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(1.0, 1.0, 1.0);
				glEnd();			// End Drawing The Cube	
			}
			glTranslatef(2, 0, 0);
		}
		glTranslatef(-80, 0, 2);
	}
#pragma endregion
	glPopMatrix();

	glTranslatef(0, 2, 0);

	glPushMatrix();
#pragma region Rysowanie poziomu 5.
	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 40; j++) {
			if (data.Level5[i][j] == '1')
			{
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_SIDE));
				glBegin(GL_QUADS);		// Draw The Cube Using quads
										//front
				glTexCoord2f(0.0, 1.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(-1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(1.0, 1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(-1.0, 1.0, 1.0);

				glEnd();
				// top
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_TOP));
				glBegin(GL_QUADS);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0, 1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0, 1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, 1.0, -1.0);

				glEnd();

				// back	
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_SIDE));
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 1.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(-1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(1.0, 1.0, -1.0);

				// bottom
				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0, -1.0, 1.0);
				// left
				glTexCoord2f(0.0, 1.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, 1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, 1.0, -1.0);
				// right
				glTexCoord2f(0.0, 1.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, 1.0, 1.0);

				glEnd();			// End Drawing The Cub
			}
			if (data.Level5[i][j] == '2')
			{
				glDisable(GL_CULL_FACE);
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_DIRT));
				glBegin(GL_QUADS);		// Draw The Cube Using quads
										//front
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, 1.0);
				// top
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, 1.0, 1.0);

				// back
				glNormal3f(0.0f, 0.0f, -1.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);

				// bottom
				glNormal3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				// left
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(-1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				// right
				glNormal3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(1.0, 1.0, 1.0);
				glEnd();			// End Drawing The Cube	
			}
			glTranslatef(2, 0, 0);
		}
		glTranslatef(-80, 0, 2);
	}
#pragma endregion
	glPopMatrix();

	glTranslatef(0, 2, 0);

	glPushMatrix();
#pragma region Rysowanie poziomu 6.
	glDisable(GL_LIGHTING);
	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 40; j++) {
			if (data.Level6[i][j] == '1')
			{
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_SIDE));
				glBegin(GL_QUADS);		// Draw The Cube Using quads
										//front
				glTexCoord2f(0.0, 1.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(-1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(1.0, 1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(-1.0, 1.0, 1.0);

				glEnd();
				// top
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_TOP));
				glBegin(GL_QUADS);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0, 1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0, 1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, 1.0, -1.0);

				glEnd();

				// back	
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_GRASS_SIDE));
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 1.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(-1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(1.0, 1.0, -1.0);

				// bottom
				glTexCoord2f(0.0, 1.0);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glVertex3f(-1.0, -1.0, 1.0);
				// left
				glTexCoord2f(0.0, 1.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, 1.0, 1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(-1.0, 1.0, -1.0);
				// right
				glTexCoord2f(0.0, 1.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, -1.0, 1.0);

				glTexCoord2f(1.0, 1.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, -1.0, -1.0);

				glTexCoord2f(1.0, 0.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, 1.0, -1.0);

				glTexCoord2f(0.0, 0.0);
				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0, 1.0, 1.0);

				glEnd();			// End Drawing The Cub
			}
			if (data.Level6[i][j] == '2')
			{
				glDisable(GL_CULL_FACE);
				glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_DIRT));
				glBegin(GL_QUADS);		// Draw The Cube Using quads
										//front
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, 1.0);
				// top
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, 1.0, 1.0);

				// back
				glNormal3f(0.0f, 0.0f, -1.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);

				// bottom
				glNormal3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				// left
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(-1.0, 1.0, 1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
				// right
				glNormal3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
				glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
				glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);
				glTexCoord2f(0.0, 1.0);	glVertex3f(1.0, 1.0, 1.0);
				glEnd();			// End Drawing The Cube	
			}
			glTranslatef(2, 0, 0);
		}
		glTranslatef(-80, 0, 2);
	}
	glEnable(GL_LIGHTING);
#pragma endregion

	glPopMatrix();

	glPopMatrix();
	glEndList();
#pragma endregion

#pragma region Tworzenie display listy dla fence braketów
	FenceBracket = glGenLists(1);
	glNewList(FenceBracket, GL_COMPILE);
	glDisable(GL_CULL_FACE);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_PLANKS_OAK));
	glTranslatef(0.0f, 5.0f, -8.0f);


	glBegin(GL_QUADS);		// Draw The Cube Using quads

							//front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 0.5);	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 0.5);	glVertex3f(-1.0, 1.0, 1.0);
	// top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
	glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);
	glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, 1.0, 1.0);

	// back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
	glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
	glTexCoord2f(1.0, 0.5);	glVertex3f(-1.0, 1.0, -1.0);
	glTexCoord2f(0.0, 0.5);	glVertex3f(1.0, 1.0, -1.0);

	// bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
	glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
	// left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
	glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 0.5);	glVertex3f(-1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 0.5);	glVertex3f(-1.0, 1.0, -1.0);
	// right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
	glTexCoord2f(1.0, 0.5);	glVertex3f(1.0, 1.0, -1.0);
	glTexCoord2f(0.0, 0.5);	glVertex3f(1.0, 1.0, 1.0);
	glEnd();			// End Drawing The Cube
	glPopMatrix();
	glEnable(GL_CULL_FACE);
	glEndList();
#pragma endregion 

#pragma region Tworzenie display listy dla p³otu
	Fence = glGenLists(1);

	glNewList(Fence, GL_COMPILE);
	glPushMatrix();
	glTranslatef(0.0f, -9.0f, 0.0f);
	//rysowanie pierwszego pa³¹ka
	glPushMatrix();
	glScalef(0.3f, 1.0f, 0.3f);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 4.6f, 4.5f);
	//rysowanie przegródki
	glPushMatrix();
	glScalef(0.1f, 0.2f, 1.0f);
	glCallList(FenceBracket);
	glPopMatrix();

	glTranslatef(0.0f, -0.7f, 0.0f); // -1.5 w dó³ aby by³ poni¿ej pierwszego.

									 //rysowanie przegródki
	glPushMatrix();
	glScalef(0.1f, 0.2f, 1.0f);
	glCallList(FenceBracket);
	glPopMatrix();

	glPopMatrix();
	//rysowanie ostatniego pa³¹ka
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -2.0f);
	glScalef(0.3f, 1.0f, 0.3f);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glPopMatrix();
	glPopMatrix();
	glEndList();
#pragma endregion 
}
void Draw::drawCube(GLuint AllTexture)
{
	glDisable(GL_CULL_FACE);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, AllTexture);
	glTranslatef(0.0f, 5.0f, -8.0f);

	glBegin(GL_QUADS);		// Draw The Cube Using quads

							//front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, 1.0);
	// top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
	glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);
	glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, 1.0, 1.0);

	// back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
	glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
	glTexCoord2f(1.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
	glTexCoord2f(0.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);

	// bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
	glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
	// left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0, 0.0);	glVertex3f(-1.0, -1.0, -1.0);
	glTexCoord2f(1.0, 0.0);	glVertex3f(-1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 1.0);	glVertex3f(-1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 1.0);	glVertex3f(-1.0, 1.0, -1.0);
	// right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0, 0.0);	glVertex3f(1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 0.0);	glVertex3f(1.0, -1.0, -1.0);
	glTexCoord2f(1.0, 1.0);	glVertex3f(1.0, 1.0, -1.0);
	glTexCoord2f(0.0, 1.0);	glVertex3f(1.0, 1.0, 1.0);
	glEnd();			// End Drawing The Cube
	glPopMatrix();
	glEnable(GL_CULL_FACE);
}
void Draw::drawCube(GLuint Top, GLuint Side)
{
	glDisable(GL_CULL_FACE);
	glPushMatrix();

	glTranslatef(0.0f, 5.0f, -8.0f);

	glBindTexture(GL_TEXTURE_2D, Side);
	glBegin(GL_QUADS);		// Draw The Cube Using quads
							//front
	glTexCoord2f(0.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0, -1.0, 1.0);

	glTexCoord2f(1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, -1.0, 1.0);

	glTexCoord2f(1.0, 0.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, 1.0, 1.0);

	glTexCoord2f(0.0, 0.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0, 1.0, 1.0);

	glEnd();
	// top
	glBindTexture(GL_TEXTURE_2D, Top);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0, 1.0, 1.0);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 1.0, 1.0);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0, 1.0, -1.0);

	glEnd();

	// back	
	glBindTexture(GL_TEXTURE_2D, Side);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(1.0, -1.0, -1.0);

	glTexCoord2f(1.0, 1.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.0, -1.0, -1.0);

	glTexCoord2f(1.0, 0.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.0, 1.0, -1.0);

	glTexCoord2f(0.0, 0.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(1.0, 1.0, -1.0);

	// bottom
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0, -1.0, -1.0);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, -1.0, 1.0);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0, -1.0, 1.0);
	// left
	glTexCoord2f(0.0, 1.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0, -1.0, -1.0);

	glTexCoord2f(1.0, 1.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0, -1.0, 1.0);

	glTexCoord2f(1.0, 0.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0, 1.0, 1.0);

	glTexCoord2f(0.0, 0.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0, 1.0, -1.0);
	// right
	glTexCoord2f(0.0, 1.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0, -1.0, 1.0);

	glTexCoord2f(1.0, 1.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0, -1.0, -1.0);

	glTexCoord2f(1.0, 0.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0, 1.0, -1.0);

	glTexCoord2f(0.0, 0.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0, 1.0, 1.0);

	glEnd();			// End Drawing The Cube
	glPopMatrix();
	glEnable(GL_CULL_FACE);

}
void Draw::drawCube(GLuint Front, GLuint Else, int i)
{
	glDisable(GL_CULL_FACE);
	glPushMatrix();

	glTranslatef(0.0f, 5.0f, -8.0f);

	glBindTexture(GL_TEXTURE_2D, Front);
	glBegin(GL_QUADS);		// Draw The Cube Using quads
							//front
	glTexCoord2f(0.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0, -1.0, 1.0);

	glTexCoord2f(1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, -1.0, 1.0);

	glTexCoord2f(1.0, 0.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, 1.0, 1.0);

	glTexCoord2f(0.0, 0.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0, 1.0, 1.0);

	glEnd();
	// top
	glBindTexture(GL_TEXTURE_2D, Else);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0, 1.0, 1.0);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 1.0, 1.0);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0, 1.0, -1.0);

	glEnd();

	// back	
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(1.0, -1.0, -1.0);

	glTexCoord2f(1.0, 1.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.0, -1.0, -1.0);

	glTexCoord2f(1.0, 0.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.0, 1.0, -1.0);

	glTexCoord2f(0.0, 0.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(1.0, 1.0, -1.0);

	// bottom
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0, -1.0, -1.0);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, -1.0, 1.0);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0, -1.0, 1.0);
	// left
	glTexCoord2f(0.0, 1.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0, -1.0, -1.0);

	glTexCoord2f(1.0, 1.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0, -1.0, 1.0);

	glTexCoord2f(1.0, 0.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0, 1.0, 1.0);

	glTexCoord2f(0.0, 0.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0, 1.0, -1.0);
	// right
	glTexCoord2f(0.0, 1.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0, -1.0, 1.0);

	glTexCoord2f(1.0, 1.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0, -1.0, -1.0);

	glTexCoord2f(1.0, 0.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0, 1.0, -1.0);

	glTexCoord2f(0.0, 0.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0, 1.0, 1.0);

	glEnd();			// End Drawing The Cube
	glPopMatrix();
	glEnable(GL_CULL_FACE);

}
void Draw::drawTree(GLuint log, GLuint leaves, int a)
{
	switch (a) {
	case 0:
#pragma region Tree0
		drawCube(log);
		glTranslatef(0, 2, 0);
		drawCube(log);
		glTranslatef(-4, 2, -4);
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (treeLayer1[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (treeLayer2[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (treeLayer3[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (treeLayer4[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, -2 * 5, 0); // czyszczenie ¿eby nie przeszkadzaæ innym przedmiotom
		break;
#pragma endregion 
	case 1:
#pragma region tree1
		for (int i = 0; i < 7;i++)
		{
			drawCube(log);
			glTranslatef(0, 2, 0);
		}
		glTranslatef(-2, 0, -2);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (tree2Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 3, 0, 2);
		}
		glTranslatef(0, 2, -2 * 3);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (tree2Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 3, 0, 2);
		}
		glTranslatef(0, 2, -2 * 3);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (tree2Layer1[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 3, 0, 2);
		}
		break;
#pragma endregion 
	case 2:
#pragma region tree2
		for (int i = 0; i < 2; i++)
		{
			drawCube(log);
			glTranslatef(0, 2, 0);
		}
		glTranslatef(-4, 0, -4);
		//0
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//1
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer1[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//0
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//2
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer2[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//0
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//2
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer2[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		break;
#pragma endregion 
	case 3:
#pragma region tree3
		for (int i = 0; i < 2; i++)
		{
			drawCube(log);
			glTranslatef(0, 2, 0);
		}
		glTranslatef(-4, 0, -4);
		//0
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//1
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer1[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//0
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//1
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer1[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//0
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//2
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer2[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//0
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		break;
#pragma endregion 
	default:;
	}
}
void Draw::drawTree(GLuint log, GLuint leaves)
{
	switch (rand()%4) {
	case 0:
#pragma region Tree0
		drawCube(log);
		glTranslatef(0, 2, 0);
		drawCube(log);
		glTranslatef(-4, 2, -4);
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (treeLayer1[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (treeLayer2[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (treeLayer3[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (treeLayer4[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, -2 * 5, 0); // czyszczenie ¿eby nie przeszkadzaæ innym przedmiotom
		break;
#pragma endregion 
	case 1:
#pragma region tree1
		for (int i = 0; i < 7; i++)
		{
			drawCube(log);
			glTranslatef(0, 2, 0);
		}
		glTranslatef(-2, 0, -2);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (tree2Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 3, 0, 2);
		}
		glTranslatef(0, 2, -2 * 3);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (tree2Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 3, 0, 2);
		}
		glTranslatef(0, 2, -2 * 3);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (tree2Layer1[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 3, 0, 2);
		}
		break;
#pragma endregion 
	case 2:
#pragma region tree2
		for (int i = 0; i < 2; i++)
		{
			drawCube(log);
			glTranslatef(0, 2, 0);
		}
		glTranslatef(-4, 0, -4);
		//0
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//1
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer1[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//0
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//2
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer2[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//0
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//2
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer2[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		break;
#pragma endregion 
	case 3:
#pragma region tree3
		for (int i = 0; i < 2; i++)
		{
			drawCube(log);
			glTranslatef(0, 2, 0);
		}
		glTranslatef(-4, 0, -4);
		//0
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//1
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer1[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//0
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//1
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer1[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//0
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//2
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer2[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		//0
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tree3Layer0[i][j] == true)
					drawCube(leaves);
				glTranslatef(2, 0, 0);
			}
			glTranslatef(-2 * 5, 0, 2);
		}
		glTranslatef(0, 2, -2 * 5);
		break;
#pragma endregion 
	default:;
	}
}
void Draw::drawTeleport()
{
	glDisable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glBindTexture(GL_TEXTURE_2D, data.GetID(IMG_TELEPORT));
	glBegin(GL_QUADS);		// Draw The Cube Using quads
							//front
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-6.0, -6.0, 6.0);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(6.0, -6.0, 6.0);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(6.0, 6.0, 6.0);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(-6.0, 6.0, 6.0);

	glEnd();
	glEnable(GL_LIGHTING);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);
};
void Draw::drawbridge(GLuint ABCD)
{
	glPushMatrix();
	glCallList(Fence);
	glTranslatef(0, 0, -2);
	glCallList(Fence);
	glTranslatef(0, 0, -2);
	glCallList(Fence);
	glTranslatef(0, -2, 0);
	for (int i = 0; i < 8; i++)
	{
		glCallList(Fence);
		glTranslatef(0, 0, -2);
	}
	glTranslatef(0, 2, 2);
	glCallList(Fence);
	glTranslatef(0, 0, -2);
	glCallList(Fence);
	glTranslatef(0, 0, -2);
	glCallList(Fence);
	glPopMatrix();
	glTranslatef(6, 0, -0.5);
	glPushMatrix();
	glTranslatef(-6, -6, -0.7);
	glScalef(0.8, 0.6, 0.1);
	drawCube(ABCD, data.GetID(IMG_PLANKS_OAK), 0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0, 0.5);
	glCallList(Fence);
	glTranslatef(0, 0, -2);
	glCallList(Fence);
	glTranslatef(0, 0, -2);
	glCallList(Fence);
	glTranslatef(0, -2, 0);
	for (int i = 0; i < 8; i++)
	{
		glCallList(Fence);
		glTranslatef(0, 0, -2);
	}
	glTranslatef(0, 2, 2);
	glCallList(Fence);
	glTranslatef(0, 0, -2);
	glCallList(Fence);
	glTranslatef(0, 0, -2);
	glCallList(Fence);
	glPopMatrix();
	glTranslatef(-4, -11, 3.5);
	glPushMatrix();
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glTranslatef(0, -1, -2);

	glPushMatrix();
	glScalef(1, 0.5, 1);
	glTranslatef(0, 6, 0);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 0.5, 1);
	glTranslatef(0, 6, -2);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glTranslatef(0, -2, -6);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glTranslatef(0, 2, -4);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glTranslatef(0, 0, -4);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glScalef(1, 2, 1);
	glTranslatef(0, -2, -2);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glTranslatef(0, 0, -2);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glPopMatrix();

	glPopMatrix();
	glPushMatrix();
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glTranslatef(0, -1, -2);

	glPushMatrix();
	glScalef(1, 0.5, 1);
	glTranslatef(0, 6, 0);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glPopMatrix();

	glPopMatrix();
	glTranslatef(2, -1, -2);
	glPushMatrix();
	glTranslatef(0, 1, 2);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glTranslatef(0, -1, -2);
	glPushMatrix();
	glScalef(1, 0.5, 1);
	glTranslatef(0, 6, 0);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 0.5, 1);
	glTranslatef(0, 6, -4);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glTranslatef(0, -2, -2);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glTranslatef(0, 0, -4);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glTranslatef(0, 2, -4);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glTranslatef(0, 0, -2);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glScalef(1, 2, 1);
	glTranslatef(0, -2, -2);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glTranslatef(0, 0, -2);
	drawCube(data.GetID(IMG_PLANKS_OAK));
	glPopMatrix();

	glPopMatrix();

}
void Draw::drawText(int x, int y, std::string st)
{
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);  // Tell opengl that we are doing project matrix work
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();  // Clear the matrix
	glOrtho(-64.0, 64.0, -64.0, 64.0, 0.0, 30.0);  // Setup an Ortho view
	glMatrixMode(GL_MODELVIEW);  // Tell opengl that we are doing model matrix work. (drawing)
	glLoadIdentity(); // Clear the model matrix
	glDisable(GL_BLEND);
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y); // location to start printing text
	for (int i = 0; i < st.size(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
	glPopMatrix();
	glEnable(GL_BLEND);
	glMatrixMode(GL_PROJECTION);  // Tell opengl that we are doing project matrix work
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_LIGHTING);
}
void Draw::drawText(int x, int y, std::string st, int big)
{
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);  // Tell opengl that we are doing project matrix work
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();  // Clear the matrix
	glOrtho(-64.0, 64.0, -64.0, 64.0, 0.0, 30.0);  // Setup an Ortho view
	glMatrixMode(GL_MODELVIEW);  // Tell opengl that we are doing model matrix work. (drawing)
	glLoadIdentity(); // Clear the model matrix
	glDisable(GL_BLEND);
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y); // location to start printing text
	for (int i = 0; i < st.size(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
	glPopMatrix();
	glEnable(GL_BLEND);
	glMatrixMode(GL_PROJECTION);  // Tell opengl that we are doing project matrix work
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_LIGHTING);
}