// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <GL/freeglut.h>
#include <string>

struct vec3
{
	float x, y, z;
};

struct answer
{
	std::string answerABCD;
	bool correct;
};

enum GameStatus
{
	Questions,
	Won,
	Lose,
	Correct,
	Wrong
};