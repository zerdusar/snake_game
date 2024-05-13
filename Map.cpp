#include "Map.h"

Map::Map(int height, int width)
{
	map.resize(height);
	for (size_t i = 0; i < height; i++)
	{
		map[i].resize(width);
		for (size_t j = 0; j < width; j++)
		{
			map[i][j] = '*';
		}
	}
}

bool Map::is_intersection(Abstract_shape& first)
{
	if (map[first.y][first.x]=='*')
		return false;
	else
		return true; 
}

void Map::print(HANDLE hwnd)
{
	SetConsoleCursorPosition(hwnd, { 0, 0 });
	for (size_t i = 0; i < this->get_height(); i++)
	{
		for (size_t j = 0; j < this->get_width(); j++)
		{
			std::cout << map[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Map::creat_fruit(Fruit& fruit)
{
	Fruit temp;
	do 
	{
		temp.x = rand() % get_width();
		temp.y = rand() % get_height();
	} while (is_intersection(temp));
	fruit = temp;
}

void Map::clear()
{
	for (size_t i = 0; i < map.size(); i++)
	{
		for (size_t j = 0; j < map[i].size(); j++)
		{
			map[i][j] = '*';
		}
	}
}