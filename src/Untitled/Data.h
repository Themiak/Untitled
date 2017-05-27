#pragma once
#include "Player.h"
#include "vector"
#include "Texture.h"
#include "Question.h"

extern Player player;
extern std::vector <vec3> trees;


#define NUM_TEX		 30
#define NUM_QUE		 30

enum {
	IMG_GRASS_TOP,
	IMG_GRASS_SIDE,
	IMG_HEALTH,
	IMG_LEAVES_OAK,
	IMG_LEAVES_SPRUCE,
	IMG_LEAVES_BIRCH,
	IMG_LOG_OAK,
	IMG_LOG_SPRUCE,
	IMG_LOG_BIRCH,
	IMG_PLANKS_OAK,
	IMG_PLANKS_BIRCH,
	IMG_DIRT,
	IMG_FLOOR,
	IMG_TELEPORT,
	IMG_A,
	IMG_B,
	IMG_C,
	IMG_D,
	IMG_LOGO,
	IMG_SKY,
	IMG_MENU_VERY_HARD,
	IMG_MENU_HARD,
	IMG_MENU_NORMAL,
	IMG_MENU_EASY,
	IMG_WIN,
	IMG_LOSE,
	IMG_CORRECT,
	IMG_WRONG
};

class Data
{
public:
	Data(void);
	~Data(void);
	void GetSize(int img, int *w, int *h);
	void LoadQuestion(std::string name);
	void RotateQuestionAnswers();
	int  GetID(int img);
	int ammoutOfQuestions;
	char Height[75][75];
	char Level0[38][40];
	char Level1[38][40];
	char Level2[38][40];
	char Level3[38][40];
	char Level4[38][40];
	char Level5[38][40];
	char Level6[38][40];
	bool Load();
	void resetQuestions();
	std::vector<bool> UsedQuestions;
	Question Questions[NUM_QUE];
private:
	bool LoadImage(int img, char *filename, int type = GL_RGBA);
	Texture textures[NUM_TEX];
};