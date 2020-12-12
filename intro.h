#ifndef _intro_h
#define _intro_h

#include <iostream>
#include <thread>
#include <semaphore.h>
#include <string.h>
#include "input.h"
#include "macros.h"

using namespace std;

class Intro
{
	public:
		Intro(Snake snake);
		void DrawIntro();
		void DrawUserCursor(int num);
		int SelectMenu();
		void Update_Next_Direction(enum Direction direction);
		enum Direction Get_Direction(void);
		void Update_Direction(enum Direction direction);
		void Validate_Direction(void);
	private:
		sem_t intro_sema;
		string intro_map[INTRO_HEIGHT];
		Snake snake;
		pthread_t intro_thread;
		enum Direction next_direction;
		enum Direction direction;
};

//class Outro
//{
//	public:
//		Outro();
//};

#endif
