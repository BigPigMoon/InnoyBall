#include "global.h"

void drawChar(int x, int y, int layerNum, char ch)
{
	terminal_layer(layerNum);
	terminal_put(x, y, ch);
	terminal_layer(0);
}