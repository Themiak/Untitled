#include "stdafx.h"
#include "Data.h"
#include <fstream>
#include <string>
#include <sstream>

Data::Data(void) {}
Data::~Data(void) {}
int Data::GetID(int img)
{
	return textures[img].GetID();
}
void Data::GetSize(int img, int *w, int *h)
{
	textures[img].GetSize(w, h);
}
bool Data::LoadImage(int img, char *filename, int type)
{
	int res;

	res = textures[img].Load(filename, type);
	if (!res) return false;

	return true;
}

bool Data::Load()
{
	int res;

	res = LoadImage(IMG_GRASS_TOP, "Textures/grass_top.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_GRASS_SIDE, "Textures/grass_side.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_HEALTH, "Textures/zycie.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_LEAVES_OAK, "Textures/leaves_oak.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_LEAVES_SPRUCE, "Textures/leaves_spruce.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_LEAVES_BIRCH, "Textures/leaves_birch.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_LOG_OAK, "Textures/log_oak.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_LOG_SPRUCE, "Textures/log_spruce.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_LOG_BIRCH, "Textures/log_birch.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_PLANKS_OAK, "Textures/planks_oak.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_PLANKS_BIRCH, "Textures/planks_birch.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_DIRT, "Textures/dirt.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_FLOOR, "Textures/floor.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_TELEPORT, "Textures/teleport.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_A, "Textures/A.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_B, "Textures/B.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_C, "Textures/C.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_D, "Textures/D.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_LOGO, "Textures/Untitled_logo.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_SKY, "Textures/Sky2.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_MENU_EASY, "Textures/Menu_Easy.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_MENU_NORMAL, "Textures/Menu_Normal.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_MENU_HARD, "Textures/Menu_Hard.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_MENU_VERY_HARD, "Textures/Menu_VeryHard.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_WIN, "Textures/Win.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_LOSE, "Textures/Lose.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_CORRECT, "Textures/Correct.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_WRONG, "Textures/Wrong.png", GL_RGBA);
	if (!res) return false;


#pragma region Resources
	std::string lineAsString;
	std::ifstream inputFile("Resources/0.txt");
	if (!inputFile.is_open())
		throw std::exception("Can't read file");
	while (!inputFile.eof())
	{
		for (int i = 0; i < 38; i++) {
			for (int j = 0; j < 40; j++) {
				inputFile >> lineAsString;
				Level0[i][j] = lineAsString[0];
			}
		}
	}
	std::ifstream inputFile1("Resources/1.txt");
	if (!inputFile1.is_open())
		throw std::exception("Can't read file");
	while (!inputFile1.eof())
	{
		for (int i = 0; i < 38; i++) {
			for (int j = 0; j < 40; j++) {
				inputFile1 >> lineAsString;
				Level1[i][j] = lineAsString[0];
			}
		}
	}
	std::ifstream inputFile2("Resources/2.txt");
	if (!inputFile2.is_open())
		throw std::exception("Can't read file");
	while (!inputFile2.eof())
	{
		for (int i = 0; i < 38; i++) {
			for (int j = 0; j < 40; j++) {
				inputFile2 >> lineAsString;
				Level2[i][j] = lineAsString[0];
			}
		}
	}
	std::ifstream inputFile3("Resources/3.txt");
	if (!inputFile3.is_open())
		throw std::exception("Can't read file");
	while (!inputFile3.eof())
	{
		for (int i = 0; i < 38; i++) {
			for (int j = 0; j < 40; j++) {
				inputFile3 >> lineAsString;
				Level3[i][j] = lineAsString[0];
			}
		}
	}
	std::ifstream inputFile4("Resources/4.txt");
	if (!inputFile4.is_open())
		throw std::exception("Can't read file");
	while (!inputFile4.eof())
	{
		for (int i = 0; i < 38; i++) {
			for (int j = 0; j < 40; j++) {
				inputFile4 >> lineAsString;
				Level4[i][j] = lineAsString[0];
			}
		}
	}
	std::ifstream inputFile5("Resources/5.txt");
	if (!inputFile5.is_open())
		throw std::exception("Can't read file");
	while (!inputFile5.eof())
	{
		for (int i = 0; i < 38; i++) {
			for (int j = 0; j < 40; j++) {
				inputFile5 >> lineAsString;
				Level5[i][j] = lineAsString[0];
			}
		}
	}
	std::ifstream inputFile6("Resources/6.txt");
	if (!inputFile6.is_open())
		throw std::exception("Can't read file");
	while (!inputFile6.eof())
	{
		for (int i = 0; i < 38; i++) {
			for (int j = 0; j < 40; j++) {
				inputFile6 >> lineAsString;
				Level6[i][j] = lineAsString[0];
			}
		}
	}
	std::ifstream inputarea("Resources/area.txt");
	if (!inputarea.is_open())
		throw std::exception("Can't read file");
	while (!inputarea.eof())
	{
		for (int i = 0; i < 75; i++) {
			for (int j = 0; j < 75; j++) {
				inputarea >> lineAsString;
				Height[i][j] = lineAsString[0];
			}
		}
	}
	std::ifstream inputQuestion("Resources/area.txt");
	if (!inputarea.is_open())
		throw std::exception("Can't read file");
	while (!inputarea.eof())
	{
		for (int i = 0; i < 75; i++) {
			for (int j = 0; j < 75; j++) {
				inputarea >> lineAsString;
				Height[i][j] = lineAsString[0];
			}
		}
	}

	std::ifstream inputtrees("Resources/trees.txt");
	if (!inputtrees.is_open())
		throw std::exception("Can't read file");
	float number;
	while (!inputtrees.eof())
	{
		vec3 tmp;
		inputtrees >> tmp.x;
		tmp.y = 0;
		inputtrees >> tmp.z;
		trees.push_back(tmp);
	
	}

	LoadQuestion("str");
	RotateQuestionAnswers();
	for (int i = 0; i < ammoutOfQuestions; i++)
		UsedQuestions.push_back(false);

#pragma endregion 

	return true;
}
void Data::resetQuestions()
{
	UsedQuestions.clear();
	for (int i = 0; i < ammoutOfQuestions; i++)
		UsedQuestions.push_back(false);
}
void Data::LoadQuestion(std::string name)
{

	std::string lineAsString;
	std::ifstream inputarea("Resources/Question.txt");
	if (!inputarea.is_open())
		throw std::exception("Can't read file");
	std::stringstream a;
	int k = 0;
	while (!inputarea.eof())
	{
		Question Questionsnew;
		for (int i = 0; i < 6; i++)
		{
			inputarea >> lineAsString;
			while (lineAsString[0] != ';')
			{
				a << lineAsString << " ";
				inputarea >> lineAsString;

			}
			switch (i)
			{
			case 0:
				Questions[k].setQuestion(a.str());
				break;
			case 1:
				Questions[k].setA(a.str());
				break;
			case 2:
				Questions[k].setB(a.str());
				break;
			case 3:
				Questions[k].setC(a.str());
				break;
			case 4:
				Questions[k].setD(a.str());
				break;
			case 5:
				Questions[k].setCorrect(a.str()[0]);
				break;
			default:throw - 1;
			};
			a.str("");
		}
		k++;
	}
	ammoutOfQuestions = k - 1;
};
void Data::RotateQuestionAnswers()
{
	for (int i = 0; i < player.getMaxLevel(); i++)
	{
		for (int j = 0; j < rand() % 20; j++)
		{
			auto a = rand() % 6;
			switch (a)
			{
			case 0:
				std::swap(Questions[i].A, Questions[i].B);
				break;
			case 1:
				std::swap(Questions[i].A, Questions[i].C);
				break;
			case 2:
				std::swap(Questions[i].A, Questions[i].D);
				break;
			case 3:
				std::swap(Questions[i].B, Questions[i].C);
				break;
			case 4:
				std::swap(Questions[i].B, Questions[i].D);
				break;
			case 5:
				std::swap(Questions[i].D, Questions[i].C);
				break;
			default:;
			}
		}
	}
}