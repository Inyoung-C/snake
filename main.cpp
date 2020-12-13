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

using namespace std;

Snake snake;
SnakeMap snake_map(&snake);

void initialize()
{
    input_init();
}

bool is_game_end()
{
    bool result = false;
    pair<int, int> snake_head = snake.snake_head;
    if (snake.is_dead)
    {
        result = true;
    }
    return result;
}

void game_over()
{
    cout << "GAME IS OVER" << endl;
}

void start_game()
{
    while (true)
    {
        snake.update_direction();
        snake.update_movement();
        if (is_game_end())
        {
            game_over();
            break;
        }
        snake_map.redraw();

				//faster
        Sleep(PAUSE_LENGTH - snake.length*5);
    }
}

int main()
{
    initialize();
		Intro *intro = new Intro();
		while (true) {
    	switch (intro->SelectMenu()) {
				case 1:
					start_game(); // 2p
					break;
				case 2:
					start_game(); // Rank
					break;
				case 3:
					break;
			}
		}
    return 0;
}
