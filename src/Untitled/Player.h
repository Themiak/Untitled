#pragma once
#include "stdafx.h"
#include "Question.h"
#include <vector>

class Player
{
public:
	Player() : health(4), level(1), maxLevel(16), lastBridge('N'), speed(0.5f)
	{
		// Inicjalizacja kamery:
		pos.x = 38.0f;
		pos.y = 16.75f;
		pos.z = 38.0f;

		dir.x = 0.0f;
		dir.y = 0.0f;
		dir.z = -1.0f;
	};
	~Player();
	void init();
	void setPosX(const float x);
	void setPosY(const float y);
	void setPosZ(const float z);
	void setMenuPos();
	void setLastBridge(char a);
	void setDirX(const float x);
	void setDirY(const float y);
	void setDirZ(const float z);
	void setSpeed(float speed);
	void setHealth(int health);
	void setLevel(int level);
	void setMaxLevel(int maxlevel);
	int getHealth();
	int getLevel();
	int getMaxLevel();
	char getlastBridge();
	float getPosX() const;
	float getPosY() const;
	float getPosZ() const;
	float getDirX() const;
	float getDirY() const;
	float getDirZ() const;
	float GetSpeed() const;
	std::string getQuestion();;
	std::string getA();;
	std::string getB();;
	std::string getC();;
	std::string getD();
	void Reset();;
	std::vector<Question> Questions;
private:
	vec3 pos;
	vec3 dir;
	int health, level, maxLevel;
	char lastBridge;
	float speed;
};
