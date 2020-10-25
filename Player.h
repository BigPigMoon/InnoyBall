#pragma once
#include "BearLibTerminal.h"

#include <vector>

#include "global.h"

using std::vector;

class Player
{
public:
	Player(int startX, int startY);
	Player(int startX, int startY, vector<vector<char>> level);
	void move(int dx, int dy);
	void draw();
	void bindLevel(vector<vector<char>> level);

private:
	int mx;
	int my;
	vector<vector<char>> m_level;
};