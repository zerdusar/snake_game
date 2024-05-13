#pragma once
#include <vector>
#include <conio.h>
#include "Snake_part.h"
#include "Fruit.h"
#include "Map.h"

class Snake 
{
	std::vector<Snake_part> snake;
	char direction=0;
	char new_direction = 0;
	Snake_part place_for_part;
	bool check_new_dir();
public:

	bool is_broken();

	Snake(int x, int y)
	{
		snake.push_back({ x - 1 , y - 1 });
	}

	void draw(Map& map);

	bool is_intersection(Abstract_shape& shape);

	void move(size_t height, size_t width);

	void change_direction();

	void input_direction()
	{
		new_direction = _getch();
	}

	int size()
	{
		return snake.size();
	}

	void eat(Fruit& fruit, Map map)
	{
		if (!this->is_intersection(fruit))
			return;
		snake.push_back(place_for_part);
		map.creat_fruit(fruit);
	}
};
    