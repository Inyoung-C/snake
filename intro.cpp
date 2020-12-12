#include "snake.h"
#include <pthread.h>
#include <iostream>
#include <vector>
#include <utility>
#include "snake_map.h"
#include "macros.h"
#include "intro.h"

using namespace std;

void gotoxy(int x, int y) {
	printf("\033[%d;%df", y, x);
	fflush(stdout);
}

Intro::Intro() {
	
}


void Intro::DrawIntro() {
	system("cls");
	gotoxy(5, 2);
	cout << "******************************";
	gotoxy(5, 3);
	cout << "*        Snake Shhhh         *";
	gotoxy(5, 4);
	cout << "******************************";
	gotoxy(10, 8);
  cout << "1 PLAYER";
	gotoxy(10, 9);
	cout << "2 PLAYERS";
	gotoxy(10, 10);
	cout << "RANK" << endl;
	gotoxy(10, 11);
	cout << "QUIT" << endl;
}

void Intro::DrawUserCursor(int &num) {

}

int Intro::SelectMenu() {
	return 0;
}
