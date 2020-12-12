#include "snake.h"
#include <pthread.h>
#include <iostream>
#include <vector>
#include <utility>
#include "snake_map.h"
#include "macros.h"
#include "intro.h"

using namespace std;
Intro::Intro() {
	
}


void Intro::DrawIntro() {

}

void Intro::DrawUserCursor(int &num) {
	if (num <= 0)
			{
						num = 0;
							}
		else if (num >= 3)
				{
							num = 3;
								}

			gotoxy(9, 8 + num);
				cout << ">";

}

int Intro::SelectMenu() {
	int input = 0;
		while (true)
				{
					DrawReadyGame();
				  DrawUserCursor(y);
					input = get_input();			//→←↑↓
					if (input == MAGIC_KEY)
						{
							switch (get_input())
									{
									case North:
										--y;
										break;
									case South:
										++y;
										break;
									}
						}

					else if (input == SPACE)
						{
							switch (y)
									{
										case 0:
											return 0;	//PLAYER1
										case 1:
											return 1;	//PLAYER2
										case 2:
											return 2;	//RANK
										case 3:
											return 3;	//QUIT
									}
						}
				}
}


