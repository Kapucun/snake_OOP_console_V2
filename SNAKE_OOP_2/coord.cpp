#include "coord.h"
coord::coord()
{
	x = 0;
	y = 0;
}
void coord::gotoxy(int x, int y) {
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}
