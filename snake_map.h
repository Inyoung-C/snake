#ifndef _snake_map_h
#define _snake_map_h

#include "snake.h"
#include "macros.h"


class SnakeMap
{
public:
  SnakeMap(Snake *snake);
  ~SnakeMap();
  void Redraw();
  pair<int, int> snake_food;
  void Update_Snake_Food(bool force_update);
  void Update_Score();
  void Update_Snake_Head(char map_array[MAP_HEIGHT][MAP_WIDTH], Snake *snake);

private:
  char map_array[MAP_HEIGHT][MAP_WIDTH];
  Snake *snake;
  bool cnt;
};

void Clear_Map(char map_array[MAP_HEIGHT][MAP_WIDTH]);

#endif
