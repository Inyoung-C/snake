#include "input.h"
#include <stdio.h>

using namespace std;

enum Direction Get_Input()
{
    enum Direction result = East;
    char user_input = _getch();
    switch (user_input)
    {
    case 'a':
        result = West;
        break;
    case 'w':
        result = North;
        break;
    case 'd':
        result = East;
        break;
    case 's':
        result = South;
        break;
	case ' ':
		result = Space;
		break;
    default:
        result = Error;
        break;
	}
    return result;
}

void Input_Init()
{
    
}
