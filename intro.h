#ifndef _intro_h
#define _intro_h

#include "input.h"
#include "macros.h"


using namespace std;

class Intro
{
public:
	Intro();
	virtual void Draw_Tro(int num, int cnt);
	int Select_Menu();
private:
	string intro_map[INTRO_HEIGHT];
};

class Outro : public Intro
{
public:
	Outro(int);
	void Draw_Tro(int num, int cnt);
private:
	string outro_map[OUTRO_HEIGHT];
	int score;
};

#endif
