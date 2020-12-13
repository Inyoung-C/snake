#ifndef _intro_h
#define _intro_h

#include "input.h"
#include "macros.h"


using namespace std;

class Intro
{
	public:
		Intro();
		void DrawIntro();
		void DrawUserCursor(int num);
		int SelectMenu();
	private:
		string intro_map[INTRO_HEIGHT];
};

//class Outro
//{
//	public:
//		Outro();
//};

#endif
