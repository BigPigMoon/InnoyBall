#include "BearLibTerminal.h"
#include "tinyxml2.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <locale>

#include "global.h"
#include "Player.h"
#include "LevelParser.h"


using std::vector;
using std::string;

int main()
{
	// setlocale(0, "Rus");
	setlocale(0, "");
	dialogParse("test.xml", "John");

	vector<vector<char>> level = levelParse("hotel.lvl");

	int startX = 2;
	int startY = 2;

	Player player(startX, startY);
	player.bindLevel(level);

	terminal_open();
	terminal_set("settings.ini");

	while (true)
	{
		if (terminal_has_input())
		{
			int key = terminal_read();

			if (key == TK_ESCAPE) { break; }
			// if (key == TK_CLOSE) { break; } // why doesn't it work?

			if (key == TK_LEFT) { player.move(-1, 0); }
			if (key == TK_RIGHT) { player.move(1, 0); }
			if (key == TK_UP) { player.move(0, -1); }
			if (key == TK_DOWN) { player.move(0, 1); }
		}

		// ----------DRAW----------

		/*
		*	layer 0 -- level layer
		*	layer 1 -- player layer
		*/

		// draw level
		for (int x = 0; x < level.at(0).size(); ++x)
		{
			for (int y = 0; y < level.size(); ++y)
			{
				drawChar(x, y, 0, level.at(y).at(x));
			}
		}

		player.draw();

		terminal_refresh();
	}

	terminal_close();

	return 0;
}

