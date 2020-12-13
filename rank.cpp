#include "rank.h"
#include "macros.h"
#include "input.h"

using namespace std;

struct comp
{

};

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Rank::Rank()
{
	// 자기등수 집어넣기
}


void Rank::Draw_Rank()
{

}



int Rank::Select_Menu()
{

}