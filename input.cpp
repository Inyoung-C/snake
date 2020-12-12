#include "input.h"
#include <termios.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include <string>
#include <stdio.h>

using namespace std;

struct termios t;

void input_enter_off()
{
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
		t.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void input_enter_on()
{
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON;
		t.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}
/*
char getch(void){
	int ch;
	struct termios buf;
	struct termios save;

	tcgetattr(0,&save);
	buf=save;
	buf.c_lflag &= ~(ICANON|ECHO);
	buf.c_cc[VMIN]=1;
	buf.c_cc[VTIME]=0;
	tcsetattr(0,TCSAFLUSH,&buf);
	ch=getchar();
	fflush(stdout);
	tcsetattr(0,TCSAFLUSH,&save);
	return ch;
}
*/
enum Direction get_input()
{
    enum Direction result = East;
    char user_input = getchar();
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
        //cout << "Incorrect button clicked(" << user_input << ")" << endl;
        break;
		}
		printf("%d\n", result);
    return result;
}

void input_init()
{
    
}
