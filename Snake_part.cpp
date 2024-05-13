#include "Snake_part.h"

Snake_part::Snake_part(int x, int y)
{
	texture = '@';
	this->x = x;
	if (x >= 10)
		x %= 10;
	this->y = y;
	if (y >= 10)
		y %= 10;
}

Snake_part::Snake_part()
{
	texture = '@';
	this->x = 0;
	this->y = 0;
}