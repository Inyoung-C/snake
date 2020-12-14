#include "rank.h"
#include "macros.h"
#include "input.h"

using namespace std;

string init_rank_map[RANK_HEIGHT] =
{ "-----------------------------------------------------------------------------------",
 "-                                                                                 -",
 "-                                                                                 -",
 "-          *************************************************************          -",
 "-          *                   T O P  5  S N A K E S                   *          -",
 "-          *************************************************************          -",
 "-                                                                                 -",
 "-                   RANKING                          SCORE                        -",
 "-                                                                                 -",
 "-                                                                                 -",
 "-                   *  1  *                                                       -",
 "-                                                                                 -",
 "-                                                                                 -",
 "-                   *  2  *                                                       -",
 "-                                                                                 -",
 "-                                                                                 -",
 "-                   *  3  *                                                       -",
 "-                                                                                 -",
 "-                                                                                 -",
 "-                   *  4  *                                                       -",
 "-                                                                                 -",
 "-                                                                                 -",
 "-                   *  5  *                                                       -",
 "-                                                                                 -",
 "-                                                                                 -",
 "-             T R Y  O U R  G A M E  A N D  B E  A  T O P  S N A K E  !           -",
 "-                                                                                 -",
 "-----------------------------------------------------------------------------------" };

struct comp
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Rank::Rank()
{
	// 자기등수 집어넣기
	this->board.push_back(41);
	this->board.push_back(39);
	this->board.push_back(35);
}

void Rank::Push_Score(int score)
{
	char name[3];
	char trash;
	gotoxy(MAP_HEIGHT / 2, MAP_WIDTH / 2);
	cout << "GAME OVER";
	gotoxy(MAP_HEIGHT / 2, MAP_WIDTH / 2 - 1);
	cout << "SCORE : " << score << "    ";
	this->board.push_back(score);
	Sleep(3000);
}

void Rank::Show_Score()
{
	int last = 5;
	int tmp;
	system("cls");
	string rank_map[RANK_HEIGHT];
	priority_queue<int, vector<int>, comp> pq;
	vector<int>::iterator iter;

	for (int i = 0; i < RANK_HEIGHT; i++)
		rank_map[i] = init_rank_map[i];
	for (iter = (this->board).begin(); iter != (this->board).end(); iter++)
		pq.push(*iter);
	if (this->board.size() < 5) last = this->board.size();

	for (int i = 0; i < last; i++) {
		tmp = pq.top();
		pq.pop();
		if (tmp / 10 != 0) rank_map[10 + i * 3][53] = tmp / 10 + '0';
		rank_map[10 + i * 3][54] = tmp % 10 + '0';
	}

	for (int i = 0; i < RANK_HEIGHT; i++) {
		cout << rank_map[i] << endl;
	}
	Sleep(5000);
}