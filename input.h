#ifndef _input_h
#define _input_h

#include <conio.h>
#include <Windows.h>

enum Direction
{
    Error = -1,
    West = 0,
    North = 1,
    East = 2,
    South = 3,
	Space = 4
};

void Input_Init(void);
enum Direction Get_Input(void);

#endif
