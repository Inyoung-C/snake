#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include "input.h"
#include "snake.h"
#include "snake_map.h"
#include <utility>
#include "macros.h"
#include "intro.h"
#include <Windows.h>
#include "rank.h"

using namespace std;

Snake snake;
SnakeMap snake_map(&snake);
Rank rank1;

void Initialize()
{
    Input_Init();
}

bool Is_Game_End()
{
    bool result = false;
    pair<int, int> snake_head = snake.snake_head;
    if (snake.is_dead) {
        result = true;
    }
    return result;
}


void Start_Game()
{
    Outro *outro;
    while (true) {
        snake.Update_Direction();
        snake.Update_Movement();
        if (Is_Game_End()) {
            outro = new Outro(snake.length);
            rank1.Draw_Rank(); // Rank
            while (true) {
                switch (outro->Select_Menu())
                {
                case 1:
                    Start_Game();
                    break;
                case 2:
                    break;
                case 3:
                    break;
                }
            }
            break;
        }
        snake_map.Redraw();

        Sleep(PAUSE_LENGTH - snake.length*5);   //faster
    }
}

int main()
{
    Initialize();
	Intro *intro = new Intro;
	while (true) {
        switch (intro->Select_Menu())
        {
	    case 1:
		    Start_Game();
	    	break;
	    case 2:
	    	rank1.Draw_Rank(); // Rank
	    	break;
	    case 3:
	    	return 0;
	    }
	}
    return 0;
}
