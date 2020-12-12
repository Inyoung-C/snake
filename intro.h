#ifndef _intro_h
#define _intro_h

#include <iostream>
#include "input.h"
#include "macros.h"

using namespace std;

class Intro
{
	public:
		Intro();
		void DrawIntro();
		void DrawUserCursor(int &num);
		int SelectMenu();
};

//class Outro
//{
//	public:
//		Outro();
//};

#endif
