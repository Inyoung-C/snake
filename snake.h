#ifndef _snake_h
#define _snake_h

#include "input.h"
#include <vector>
#include <utility>
#include "macros.h"

using namespace std;

class Snake
{
public:
  Snake();
  ~Snake();
  void Update_Direction();
  enum Direction Get_Direction();
  vector<pair<int, int>> snake_parts;
  pair<int, int> snake_head;
  void Update_Movement();
  void Set_Snake_Food(pair<int, int> snake_food);
  bool food_eaten;
  bool is_dead;
  int length;
private:
  enum Direction direction;
  enum Direction next_direction;
  pair<int, int> snake_food;
  int snake_world_array[MAP_HEIGHT][MAP_WIDTH];
  void Clear_Snake_World();
  void Initialize_Snake();
};

#endif
