#pragma once
#include "Data.h"

extern Data data;
extern GLuint Mountain;
extern GLuint Floor;
extern GLuint Fence;
extern GLuint FenceBracket;
extern GLuint MenuEasy;
extern GLuint MenuNormal;
extern GLuint MenuHard;
extern GLuint MenuVeryHard;
extern GLuint win;
extern GLuint lose;
extern GLuint correct;
extern GLuint wrong;
extern std::vector <vec3> trees;

class Draw
{
public:
	Draw() {};
	~Draw();
	void init(Data data);
	void drawTree(GLuint log, GLuint leaves, int);
	void drawTree(GLuint log, GLuint leaves);
	void drawCube(GLuint Top, GLuint Side);
	void drawCube(GLuint Front, GLuint Else, int i);
	void drawCube(GLuint AllTexture);
	void drawTeleport();
	void drawbridge(GLuint ABCD);
	void drawText(int x, int y, std::string st);
	void drawText(int x, int y, std::string st, int);
};

