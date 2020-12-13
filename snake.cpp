#include "snake.h"
#include <iostream>
#include <vector>
#include <utility>
#include "snake_map.h"
#include "macros.h"
#include "intro.h"

using namespace std;

Snake::Snake(void)
{
    direction = East;
    next_direction = direction;
    food_eaten = false;
    is_dead = false;
    length = INITIAL_SNAKE_LENGTH;
    Clear_Snake_World();
    Initialize_Snake();
}

void Snake::Update_Direction()
{
    enum Direction input = Error;
    if (GetAsyncKeyState(0x57) != 0x0000) input = North;
    if (GetAsyncKeyState(0x53) != 0x0000) input = South;
    if (GetAsyncKeyState(0x41) != 0x0000) input = West;
    if (GetAsyncKeyState(0x44) != 0x0000) input = East;

    switch (input)
    {
    case West:
        if (this->direction != East) {
            this->direction = input;
        }
        break;
    case North:
        if (this->direction != South) {
            this->direction = input;
        }
        break;
    case East:
        if (this->direction != West) {
            this->direction = input;
        }
        break;
    case South:
        if (this->direction != North) {
            this->direction = input;
        }
        break;
    default:
        break;
    }
}


enum Direction Snake::Get_Direction(void)
{
    return this->direction;
}


void Snake::Update_Movement(void)
{
    pair<int, int> movement_part;
    enum Direction direction = Get_Direction();
    switch (direction)
    {
    case West:  
		movement_part = make_pair(snake_head.first, snake_head.second - 1);
		if(snake_head.second < 1) {
			movement_part = make_pair(snake_head.first, MAP_HEIGHT-1);
		}
		break;
    case North:
        movement_part = make_pair(snake_head.first - 1, snake_head.second);
		if(snake_head.first < 1) {
			movement_part = make_pair(MAP_WIDTH - 1, snake_head.second);
		}
		break;
    case East:
        movement_part = make_pair(snake_head.first, snake_head.second + 1);
		if(snake_head.second >= MAP_HEIGHT-1) {
			movement_part = make_pair(snake_head.first, 0);
		}
		break;
    case South:
        movement_part = make_pair(snake_head.first + 1, snake_head.second);
		if(snake_head.first >= MAP_WIDTH-1) {
			movement_part = make_pair(0, snake_head.second);
		}
		break;
    }
    snake_head = movement_part;
    snake_parts.push_back(movement_part);
    food_eaten = snake_head.first == snake_food.first && snake_head.second == snake_food.second;
    if (food_eaten) {
        length++;
    }
    else {
        pair<int, int> tail = snake_parts.front();
        snake_world_array[tail.first][tail.second]--;
        snake_parts.erase(snake_parts.begin());
    }
    int head_value = ++snake_world_array[snake_head.first][snake_head.second];
    if (head_value > 1) {
        is_dead = true;
    }
}

void Snake::Set_Snake_Food(pair<int, int> snake_food)
{
    this->snake_food = snake_food;
}

void Snake::Clear_Snake_World(void)
{
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            snake_world_array[i][j] = 0;
        }
    }
}

void Snake::Initialize_Snake(void)
{
    for (int i = 0; i < INITIAL_SNAKE_LENGTH; i++) {
        pair<int, int> snake_part = make_pair(MAP_HEIGHT / 2, MAP_WIDTH / 2 - (INITIAL_SNAKE_LENGTH / 2) + i);
        snake_parts.push_back(snake_part);
        snake_world_array[snake_part.first][snake_part.second] = 1;
    }
    snake_head = snake_parts[snake_parts.size() - 1];
}
