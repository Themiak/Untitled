#pragma once
#include "Player.h"
#include "Data.h"
#include "Draw.h"
#include "Skybox.h"
#include <irrKlang.h>

extern Player player;
extern Data data;
extern GLuint Floor;
extern GLuint Mountain;
extern GLuint Fence;
extern GLuint FenceBracket;
extern Draw draw;
extern GLuint win;
extern GLuint lose;
extern float angle;
extern std::vector <vec3> trees;
extern Skybox Sky;
extern irrklang::ISoundEngine* engine;

class Game
{
public:
	Game();
	~Game();
	void init();
	void shuffle();
	void render();
	void newLevel();
	void DrawGUI();
	void DrawMENU();
	void makeBridge(char direction);
	void setNoclip();
	void setCountDown();
	void setMove();
	void reset();
	void set_hour(int hour);
	void set_min(int min);
	void set_sec(int sec);
	void setRenderNewLevel();
	void setMenuState();
	void setGameStatus(GameStatus a);
	int getHour() const;
	int getMin() const;
	int getSec() const;
	bool getMenuState();
	bool getMove();
	bool getCountDown();
	bool getNoclip();
	GameStatus getGameStatus();
	void setPlaying() { playing = !playing; }
	bool getPlaying() { return playing; }

private:
	int hour, min, sec;
	bool CountDown = false;
	bool Noclip = false;
	bool renderNewLevel = false;
	bool menu = true;
	bool Move = true;
	bool playing = false;
	char HitBox[75][75];//przechowuje wyzerowane hitboxy
	GameStatus status;
};