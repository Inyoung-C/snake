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
{ "                                                                                   ",
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
{ "                                                                                   ",
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

string init_outro_map1[OUTRO_HEIGHT] =
{"                                                                                   ",
 "-----------------------------------------------------------------------------------",
 "-                                                                                 -",
 "-                                                                                 -",
 "-          *********************                                                  -",
 "-          *     GAME OVER!    *                                                  -",
 "-          *********************                                                  -",
 "-                                               XXXXXXXXXXXX                      -",
 "-           SCORE :                       XXXXXXXXXXXXXXXXXXXXXX                  -",
 "-                                     XXXXXXXXXXXXXXX     XXXXXXX                 -",
 "-             RESTART             XXXXXXXXXXX               XXXXXXXX              -",
 "-             RANK              XXXXXXXXXXXX               XXXXXXXXXXXX           -",
 "-             EXIT             XXXXXXXXXX                  XXXXXXXXXXXXXXXX       -",
 "-                                 XXXXXXXXXXXXX          XXXXX(T)XXXXX(T)XXX      -",
 "-                                    XXXXXXXXXXXX         XXXXXXXXXXXXXXXXXX      -",
 "-                                       XXXXXXXXXXX         XXXXXXXXXXXXXXX       -",
 "-                                         XXXXXXXXXXX           XXXXXXXXXX        -",
 "-                                            XXXXXXX              XXXXXX          -",
 "-               IIIIII                             XXXXXXXX                       -",
 "-             IIII  IIII                             XXXXXXXXX                    -",
 "-            III   XXXXX                          XXXXXXXXXXX                     -",
 "-            I      XXXXX                      XXXXXXXXXXXXX                      -",
 "-                   XXXXXXX                 XXXXXXXXXXXXX                         -",
 "-                      XXXXXXXXXXXXXXXXXXXXXXXXXXXX                               -",
 "-                           XXXXXXXXXXXXXXXXXXX                                   -",
 "-                                XXXXXXXXXX                                       -",
 "-                                                                                 -",
 "-                                                                                 -",
 "-----------------------------------------------------------------------------------" };

string init_outro_map2[OUTRO_HEIGHT] =
{"                                                                                   ",
 "-----------------------------------------------------------------------------------",
 "-                                                                                 -",
 "-                                                                                 -",
 "-          *********************                                                  -",
 "-          *     GAME OVER     *                                                  -",
 "-          *********************                                                  -",
 "-                                               XXXXXXXXXXXX                      -",
 "-           SCORE :                       XXXXXXXXXXXXXXXXXXXXXX                  -",
 "-                                     XXXXXXXXXXXXXXX     XXXXXXX                 -",
 "-             RESTART             XXXXXXXXXXX               XXXXXXXX              -",
 "-             RANK              XXXXXXXXXXXX               XXXXXXXXXXXX           -",
 "-             EXIT             XXXXXXXXXX                  XXXXXXXXXXXXXXXX       -",
 "-                                 XXXXXXXXXXXXX          XXXXX(T)XXXXX(T)XXX      -",
 "-                                    XXXXXXXXXXXX         XXXX I XXXXX I XXX      -",
 "-                                       XXXXXXXXXXX         XX I XXXXX I XX       -",
 "-                                         XXXXXXXXXXX           XXXXXXXXXX        -",
 "-                                            XXXXXXX              XXXXXX          -",
 "-               IIIIII                             XXXXXXXX                       -",
 "-             IIII  IIII                             XXXXXXXXX                    -",
 "-            III   XXXXX                          XXXXXXXXXXX                     -",
 "-            I      XXXXX                      XXXXXXXXXXXXX                      -",
 "-                   XXXXXXX                 XXXXXXXXXXXXX                         -",
 "-                      XXXXXXXXXXXXXXXXXXXXXXXXXXXX                               -",
 "-                           XXXXXXXXXXXXXXXXXXX                                   -",
 "-                                XXXXXXXXXX                                       -",
 "-                                                                                 -",
 "-                                                                                 -",
 "-----------------------------------------------------------------------------------" };

Intro::Intro() 
{

}

Outro::Outro(int score) 
{
	this->score = score;
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
	system("cls");

	if (cnt % 2 == 0) {
		for (int i = 0; i < OUTRO_HEIGHT; i++)
			this->outro_map[i] = init_outro_map1[i];
	}
	else {
		for (int i = 0; i < OUTRO_HEIGHT; i++)
			this->outro_map[i] = init_outro_map2[i];
	}

	if (this->score / 10 != 0) {
		this->outro_map[8][20] = this->score / 10 + '0';
		this->outro_map[8][21] = this->score % 10 + '0';
	}
	else {
		this->outro_map[8][21] = this->score % 10 + '0';
	}
	

	switch (num)
	{
	case 1:
		this->outro_map[10][12] = '>';
		break;
	case 2:
		this->outro_map[11][12] = '>';
		break;
	case 3:
		this->outro_map[12][12] = '>';
		break;
	default:
		break;
	}
	for (int i = 0; i < OUTRO_HEIGHT; i++) {
		cout << this->outro_map[i] << endl;
	}
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

		if (input == Space) {
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
		Sleep(PAUSE_LENGTH);
	}
}
