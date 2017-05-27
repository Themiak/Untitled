#include "stdafx.h"
#include "Player.h"

Player::~Player()
{
}
void Player::init()
{
	// Inicjalizacja kamery:
	pos.x = 38.0f;
	pos.y = 16.75f;
	pos.z = 38.0f;

	dir.x = 0.0f;
	dir.y = 0.0f;
	dir.z = -1.0f;

	health = 4;
	level = 1;
};
void Player::setMenuPos()
{
	setDirX(0.24369f);
	setDirY(-0.35f);
	setDirZ(0.97f);
	setPosX(38.0f);
	setPosY(25.0f);
	setPosZ(38.0f);
}
float Player::getPosX() const
{
	return pos.x;
}
void Player::setPosX(const float x)
{
	this->pos.x = x;
}
float Player::getPosY() const
{
	return pos.y;
}
void Player::setPosY(const float y)
{
	this->pos.y = y;
}
float Player::getPosZ() const
{
	return pos.z;
}
void Player::setPosZ(const float z)
{
	this->pos.z = z;
}
float Player::getDirX() const
{
	return dir.x;
}
void Player::setDirX(const float x)
{
	this->dir.x = x;
}
float Player::getDirY() const
{
	return dir.y;
}
void Player::setDirY(const float y)
{
	this->dir.y = y;
}
float Player::getDirZ() const
{
	return dir.z;
}
void Player::setDirZ(const float z)
{
	this->dir.z = z;
}
float Player::GetSpeed() const
{
	return speed;
}
int Player::getHealth()
{
	return health;
}
int Player::getLevel()
{
	return level;
}
int Player::getMaxLevel()
{
	return maxLevel;
}
char Player::getlastBridge()
{ return lastBridge; }
void Player::setLastBridge(char a)
{ lastBridge = a; }
void Player::setSpeed(float speed)
{
	this->speed = speed;
}
void Player::setHealth(int health)
{
	this->health = health;
}
void Player::setLevel(int level)
{
	this->level = level;
}
void Player::setMaxLevel(int maxlevel)
{
	this->maxLevel = maxlevel;
}
std::string Player::getQuestion()
{
	return Questions.front().question;
}
std::string Player::getA()
{
	return Questions.front().A.answerABCD;
}
std::string Player::getB()
{
	return Questions.front().B.answerABCD;
}
std::string Player::getC()
{
	return Questions.front().C.answerABCD;
}
std::string Player::getD()
{
	return Questions.front().D.answerABCD;
}
void Player::Reset()
{
	Questions.clear();
}