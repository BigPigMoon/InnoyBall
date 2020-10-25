#include "Player.h"

Player::Player(int startX, int startY)
{
	mx = startX;
	my = startY;
}

Player::Player(int startX, int startY, vector<vector<char>> level)
{
	mx = startX;
	my = startY;
	m_level = level;
}

void Player::move(int dx, int dy)
{
	char nextCell = m_level.at(my + dy).at(mx + dx);

	for (int i = 0; i < globalVar::blockChar.size(); ++i)
	{
		if (nextCell == globalVar::blockChar.at(i)) { return; }
	}

	for (int i = 0; i < globalVar::specialChar.size(); ++i)
	{
		if (nextCell == globalVar::specialChar.at(i))
		{
			if (nextCell == '+')
			{
				// ask user open door
			}
			if (nextCell == '/')
			{
				// ask user close door
			}
			if (nextCell == '<')
			{
				// ask user go down 
			}
			if (nextCell == '>')
			{
				// ask user go up
			}
		}
	}

	drawChar(mx, my, 1, ' ');
	mx += dx;
	my += dy;
	drawChar(mx, my, 1, '@');
}

void Player::draw()
{
	drawChar(mx, my, 1, '@');
}

void Player::bindLevel(vector<vector<char>> level)
{
	m_level = level;
}
