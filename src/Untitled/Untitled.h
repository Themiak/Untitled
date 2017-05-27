#pragma once
#include "Data.h"
#include "Player.h"
#include "Draw.h"
#include "Game.h"
#include "Skybox.h"
#include <irrKlang.h>

#pragma comment(lib, "irrKlang.lib")


void OnRender();
void OnReshape(int, int);
void OnKeyPress(unsigned char, int, int);
void OnKeyDown(unsigned char, int, int);
void OnKeyUp(unsigned char, int, int);
void OnTimer(int);
void Time(int);
void RotateTime(int);
void GameUpdate(int);

float angle = 0;
Player player;
Data data;
Draw draw;
Game game;
Skybox Sky;
GLuint Floor;
GLuint Mountain;
GLuint Fence;
GLuint FenceBracket;
GLuint MenuEasy;
GLuint MenuNormal;
GLuint MenuHard;
GLuint MenuVeryHard;
GLuint win;
GLuint lose;
GLuint correct;
GLuint wrong;
irrklang::ISoundEngine* engine;