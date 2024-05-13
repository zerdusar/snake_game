#include "Snake.h"

void Snake::draw(Map& map)
{
	for (size_t i = 0; i < snake.size(); i++)
	{
		map.draw(snake[i]);
	}
}

bool Snake::is_broken()
{
	for (size_t i = 0; i < snake.size()-1; i++)
	{
		if (snake[0] == snake[i + 1])
			return true;
	}
	return false;
}

void Snake::move(size_t height, size_t width)
{
	for (size_t i = snake.size()-1; i > 0 ; i--)
	{
		snake[i] = snake[i - 1];
		if (snake[i].x < 0) snake[i].x += width;
		snake[i].x %= width;

		if (snake[i].y < 0) snake[i].y += height;
		snake[i].y %= height;
	}
	if (direction == 'R')
		++snake[0].x;
	else if (direction == 'L')
		--snake[0].x;
	else if (direction == 'U')
		--snake[0].y;
	else if (direction == 'D')
		++snake[0].y;
	if (snake[0].x < 0) snake[0].x += width;
	snake[0].x %= width;

	if (snake[0].y < 0) snake[0].y += height;
	snake[0].y %= height;

	place_for_part = snake.back();
}

bool Snake::is_intersection(Abstract_shape& shape)
{
	for (size_t i = 0; i < snake.size(); i++)
	{
		if (shape == snake[i])
			return true;
	}
	return false;
}



void Snake::change_direction()
{
	if (!check_new_dir())
		return;
	direction = new_direction;
	new_direction = 0;
}



bool Snake::check_new_dir()
{
	if (direction == 0)
		return true;
	switch (new_direction) {

	case 'W':
	case 'w':
	case 72:
	{
		new_direction = 'U';
		break;
	}

	case 'S':
	case 's':
	case 80: {
		new_direction = 'D';
		break;
	}

	case 'D':
	case 'd':
	case 77: 
	{
		new_direction = 'R';
		break;
	}

	case 'A':
	case 'a':
	case 75:
	{
		new_direction = 'L';
		break;
	}
	default:
		return false;
	}
	if ((direction == 'R' && new_direction == 'L') || (direction == 'L' && new_direction == 'R') || (direction == 'U' && new_direction == 'D') || (direction == 'D' && new_direction == 'U'))
		return false;
	else
		return true;
}
