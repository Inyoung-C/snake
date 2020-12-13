#ifndef _intro_h
#define _intro_h

#include "input.h"
#include "macros.h"


using namespace std;

class Intro
{
public:
	Intro();
	void Draw_Tro(int num, int cnt);
	int Select_Menu();
private:
	string intro_map[INTRO_HEIGHT];
};

class Outro : public Intro
{
public:
	Outro();
	void Draw_Tro(int num, int cnt);
	int Select_Menu();
private:
	string outro_map[OUTRO_HEIGHT];
};

#endif
