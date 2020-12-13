#ifndef _rank_h
#define _rank_h
#include "macros.h"
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <Windows.h>

using namespace std;

class Rank
{
public:
	Rank();
	void Draw_Rank();
	int Select_Menu();
private:
	string rank_map[RANK_HEIGHT];
};


#endif