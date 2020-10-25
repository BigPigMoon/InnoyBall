#pragma once
#include "BearLibTerminal.h"

#include <vector>

using std::vector;

namespace globalVar
{
	const vector<char> blockChar = { '#', '-', '|' };
	const vector<char> specialChar = { '+', '/', '<', '>' };
};

void drawChar(int x, int y, int layerNum, char ch);
