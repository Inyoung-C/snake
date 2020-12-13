#include "snake.h"
#include "snake_map.h"
#include <iostream>
#include <vector>
#include <utility>
#include "snake_map.h"
#include "macros.h"
#include "intro.h"

using namespace std;

std::string init_intro_map1[INTRO_HEIGHT] =
	{"-----------------------------------------------------------------------------------",
	 "-                                                                                 -",
	 "-                                                  XXXXXXXXXXXX                   -",
	 "-          *********************                 XXXXX(>)XXXX(<)XX                -",
	 "-          *  SNAKE PSST !!!!  *                XXXXXXXXXXXXXXXXXX                -",
	 "-          *********************                XXXXXXXXXXXXX----------<          -",
	 "-                                                XXXXXXXXXXXXXX                   -",
	 "-                                              XXXXXXXXXXXX                       -",
	 "-              GAME  START                 XXXXXXXXXXXXX                          -",
	 "-              RANK                      XXXXXXXXXXXXX                            -",
	 "-              EXIT                    XXXXXXXXXXXX                               -",
	 "-                                     XXXXXXXXXXXX                                -",
	 "-                                      XXXXXXXXXXXXXXXX                           -",
	 "-                                         XXXXXXXXXXXXXX                          -",
	 "-                     I                       XXXXXXXXXXXXX                       -",
	 "-                   III                           XXXXXXXXXXXX                    -",
	 "-                  IIII                               XXXXXXXXXX                  -",
	 "-                  IIII                                  XXXXXXXX                 -",
	 "-                  IIII                                 XXXXXXXXX                 -",
	 "-                  XXXXX                              XXXXXXXXXXX                 -",
	 "-                   XXXXX                         XXXXXXXXXXXXX                   -",
	 "-                   XXXXXXX                    XXXXXXXXXXXXX                      -",
	 "-                      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX                            -",
	 "-                           XXXXXXXXXXXXXXXXXXXXXX                                -",
	 "-                                XXXXXXXXXXXXX                                    -",
	 "-                                                                                 -",
	 "-  Designed by YONG & SONG & YOUNG                                                -",
	 "-----------------------------------------------------------------------------------" };


Intro::Intro() {

}


void Intro::DrawIntro() {
//	for(int i = 0; i < MAP_END; i++)
//		cout << endl;
	system("cls");

	for(int i = 0; i < INTRO_HEIGHT; i++)
		this->intro_map[i] = init_intro_map1[i];
}

void Intro::DrawUserCursor(int num) {
	

	switch (num) 
	{
		case 1:
			this->intro_map[8][13] = '>';
			break;
		case 2:
			this->intro_map[9][13] = '>';
			break;
		case 3:
			this->intro_map[10][13] = '>';
			break;
		default:
			break;
	}
	for(int i = 0; i < INTRO_HEIGHT; i++) {
		std::cout << this->intro_map[i] << std::endl;
	}
}

int Intro::SelectMenu() {
	int num = 1;
	int input = 0;
	while (true)
	{
		DrawIntro();
		DrawUserCursor(num);
		if (GetAsyncKeyState(0x57) & 0x8000) // North
		{
			input = North;
		}
		else if (GetAsyncKeyState(0x53) & 0x8000) // South
		{
			input = South;
		}
		else if (GetAsyncKeyState(0x20) & 0x8000) // Space
		{
			input = Space;
		}
		else
		{
			input = Error;
		}
		if(input == Space)
		{
			switch (num)
			{
				case 1:
					return 1;	//PLAYER2
				case 2:
					return 2;	//RANK
				case 3:
					return 3;	//QUIT
			}
		}
		else { 
			switch (input)
			{
				case North:
					num--;
					if (num < 1) num = 3;
					break;
				case South:
					num++;
					if (num > 3) num = 1;
					break;
				default:
					break;
			}
		}
		Sleep(PAUSE_LENGTH/4);
	}
}
