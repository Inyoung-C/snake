#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unistd.h>
#include <bits/stdc++.h>
#include "input.h"
#include "snake.h"
#include "snake_map.h"
#include <utility>
#include "macros.h"
#include "intro.h"

using namespace std;

Snake snake;
SnakeMap snake_map(&snake);

void initialize()
{
    input_init();
    input_enter_off();
}

bool is_game_end()
{
    bool result = false;
    pair<int, int> snake_head = snake.snake_head;
		// pass
    /*if (snake_head.first < 0 || snake_head.first >= MAP_WIDTH || snake_head.second < 0 || snake_head.second >= MAP_HEIGHT)
    {
        result = true;
    }*/
    if (snake.is_dead)
    {
        result = true;
    }
    return result;
}

void game_over()
{
		snake.End_Move();
    cout << "GAME IS OVER" << endl;
}

void start_game()
{
	  snake.Start_Move();
    while (true)
    {
        snake.update_movement();
        if (is_game_end())
        {
            game_over();
            break;
        }
        snake_map.redraw();

				//faster
        usleep(PAUSE_LENGTH - snake.length*5000);

        snake.validate_direction();
    }
}

int main()
{
    initialize();
		Intro *intro = new Intro(snake);
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
		input_enter_on();
    return 0;
}
