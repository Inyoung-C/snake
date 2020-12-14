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

Snake *snake;
SnakeMap *snake_map;
Rank rank1;
Outro* outro;


void Initialize()
{
    Input_Init();
}

bool Is_Game_End()
{
    bool result = false;
    pair<int, int> snake_head = (*snake).snake_head;
    if ((*snake).is_dead) {
        result = true;
    }
    return result;
}


void Start_Game()
{
    snake = new Snake();
    snake_map = new SnakeMap(snake);
    while (true) {
        (*snake).Update_Direction();
        (*snake).Update_Movement();
        if (Is_Game_End()) {
            outro = new Outro((*snake).length);
            rank1.Draw_Rank(); // Rank
            delete(snake_map);
            while (true) {
                switch (outro->Select_Menu())
                {
                case 1:
                    Start_Game();
                    return;
                case 2:
                    rank1.Draw_Rank(); // Rank
                    break;
                case 3:
                    return;
                }
            }
            break;
        }
        (*snake_map).Redraw();

        Sleep(PAUSE_LENGTH*4 - (*snake).length*10); //faster
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
            return 0;
	    case 2:
	    	rank1.Select_Menu(); // Rank
	    	break;
	    case 3:
	    	return 0;
	    }
	}
    return 0;
}
