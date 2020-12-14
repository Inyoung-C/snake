#ifndef _rank_h
#define _rank_h

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <Windows.h>

class Rank
{
public:
	Rank();
	void Push_Score(int score);
	void Show_Score();
private:
	std::vector<int> board;
};


#endif