#pragma once
struct Abstract_shape
{

	int x;
	int y;

	char texture;

	Abstract_shape()
	{
		x = 0;
		y = 0;
		texture = '!'; 
	}
	virtual bool operator==(const Abstract_shape& right)
	{
		if (this->x == right.x && this->y == right.y)
			return true;
		else
			return false;
	}
};