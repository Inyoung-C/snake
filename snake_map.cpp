#include "snake_map.h"
#include <iostream>
#include <vector>
#include <utility>
#include <time.h>
#include "macros.h"

using namespace std;

SnakeMap::SnakeMap(Snake *snake)
{
    this->snake = snake;
    Clear_Map(this->map_array);
    srand(time(NULL));
    Update_Snake_Food(true);
	this->cnt = 0;
}

SnakeMap::~SnakeMap()
{
    delete(snake);
}

void SnakeMap::Redraw(void)
{
    Clear_Map(this->map_array);
	system("cls");
    Update_Score();
    vector<pair<int, int>> snake_parts = snake->snake_parts;
    for (int i = 0; i < snake_parts.size(); i++) {
        pair<int, int> tmp = snake_parts[i];
        map_array[tmp.first][tmp.second] = SNAKE_CHAR;
    }
    Update_Snake_Head(map_array, snake);
    Update_Snake_Food(false);
    map_array[snake_food.first][snake_food.second] = SNAKE_FOOD_CHAR;
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            cout << map_array[i][j] << " ";
        }
        cout << endl;
    }
}

//bomb, wall
void SnakeMap::Update_Snake_Food(bool force_update)
{
    if (snake->food_eaten || force_update) {
        while (true) {
            int random_i = rand() % MAP_WIDTH;
            int random_j = rand() % MAP_HEIGHT;
            if (map_array[random_i][random_j] == MAP_CHAR) {
                snake_food = make_pair(random_i, random_j);
                snake->Set_Snake_Food(snake_food);
                snake->food_eaten = false;
                break;
            }
        }
    }
}

void Clear_Map(char map_array[MAP_HEIGHT][MAP_WIDTH])
{
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map_array[i][j] = MAP_CHAR;
        }
    }
}

//mouth
void SnakeMap::Update_Snake_Head(char map_array[MAP_HEIGHT][MAP_WIDTH], Snake *snake)
{
	char snake_head_char = SNAKE_CHAR;
    enum Direction direction = snake->Get_Direction();
    if(this->cnt == 0) {
			switch (direction)
	    {
		  case West:
			  snake_head_char = SNAKE_HEAD_WEST;
				break;
		  case North:
			   snake_head_char = SNAKE_HEAD_NORTH;
				 break;
		  case East:
			   snake_head_char = SNAKE_HEAD_EAST;
				 break;
		  case South:
			   snake_head_char = SNAKE_HEAD_SOUTH;
				 break;
			}
			this->cnt = 1;
		} else {
			switch (direction)
			{
			case West:
		    snake_head_char = SNAKE_HEAD_WE;
			  break;
		  case North:
			  snake_head_char = SNAKE_HEAD_NS;
			  break;
			case East:
		    snake_head_char = SNAKE_HEAD_WE;
			  break;
		  case South:
			  snake_head_char = SNAKE_HEAD_NS;
			  break;

			}
			this->cnt = 0;
		}
    pair<int, int> snake_head = snake->snake_head;
    map_array[snake_head.first][snake_head.second] = snake_head_char;
}

void SnakeMap::Update_Score(void)
{
    cout << "Score:" << snake->length << endl;
}
