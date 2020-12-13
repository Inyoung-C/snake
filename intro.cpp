#include "snake.h"
#include "snake_map.h"
#include <iostream>
#include <vector>
#include <utility>
#include "snake_map.h"
#include "macros.h"
#include "intro.h"

using namespace std;

string init_intro_map1[INTRO_HEIGHT] =
{"                                                                                   ",
 "-----------------------------------------------------------------------------------",
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

string init_intro_map2[INTRO_HEIGHT] =
{"                                                                                   ",
 "-----------------------------------------------------------------------------------",
 "-                                                                                 -",
 "-                                                  XXXXXXXXXXXX                   -",
 "-          *********************                 XXXXX(>)XXXX(<)XX                -",
 "-          *  SNAKE PSST !!!!  *                XXXXXXXXXXXXXXXXXX                -",
 "-          *********************                XXXXXXXXXXXXX                     -",
 "-                                                XXXXXXXXXXXXXX                   -",
 "-                                              XXXXXXXXXXXX                       -",
 "-              GAME  START                 XXXXXXXXXXXXX                          -",
 "-              RANK                      XXXXXXXXXXXXX                            -",
 "-              EXIT                    XXXXXXXXXXXX                               -",
 "-                                     XXXXXXXXXXXX                                -",
 "-                                      XXXXXXXXXXXXXXXX                           -",
 "-                                         XXXXXXXXXXXXXX                          -",
 "-            I                                XXXXXXXXXXXXX                       -",
 "-             III                                 XXXXXXXXXXXX                    -",
 "-              IIII                                   XXXXXXXXXX                  -",
 "-                IIII                                    XXXXXXXX                 -",
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

Intro::Intro()
{

}

Outro::Outro()
{

}

void Intro::Draw_Tro(int num, int cnt)
{
	system("cls");

	if (cnt % 2 == 0) {
		for (int i = 0; i < INTRO_HEIGHT; i++)
			this->intro_map[i] = init_intro_map1[i];
	}
	else {
		for (int i = 0; i < INTRO_HEIGHT; i++)
			this->intro_map[i] = init_intro_map2[i];
	}

	switch (num)
	{
	case 1:
		this->intro_map[9][13] = '>';
		break;
	case 2:
		this->intro_map[10][13] = '>';
		break;
	case 3:
		this->intro_map[11][13] = '>';
		break;
	default:
		break;
	}
	for (int i = 0; i < INTRO_HEIGHT; i++) {
		cout << this->intro_map[i] << endl;
	}
}

void Outro::Draw_Tro(int num, int cnt)
{

}

int Intro::Select_Menu()
{
	int num = 1;
	int input = Error;
	int cnt = 0;
	while (true) {
		this->Draw_Tro(num, ++cnt);
		input = Error;
		if (GetAsyncKeyState(0x57) != 0x0000) { // North
			input = North;
		}
		if (GetAsyncKeyState(0x53) != 0x0000) { // South
			input = South;
		}
		if (GetAsyncKeyState(0x20) != 0x0000) { // Space
			input = Space;
		}

		if(input == Space) {
			switch (num)
			{
			case 1:
				return 1;	//START
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
