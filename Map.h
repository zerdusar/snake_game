#pragma once
#include <vector>
#include <iostream>
#include "Abstract_shape.h"
#include "Fruit.h"
#include <Windows.h>

class Map
{
	std::vector<std::vector<char>> map;
public:
	Map(int height, int width);
	
	void draw(Abstract_shape& shape)
	{
		map[shape.y][shape.x] = shape.texture;
	}

	bool is_intersection(Abstract_shape& first);
	
	int get_height()
	{
		return map.size();
	}
	
	int get_width()
	{
		return map[0].size();
	}

	std::vector<char>& operator [] (int i)
	{
		return map[i];
	}

	void print(HANDLE hwnd);

	void creat_fruit(Fruit& fruit);

	void clear();
};