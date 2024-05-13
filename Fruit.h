#pragma once
#include "Abstract_shape.h"
#include <ctime>
class Fruit :
    public Abstract_shape
{
private:
public:
    Fruit(int x, int y)
    {
        this->x = x;
        this->y = y;
        texture = '0';
    }
    Fruit()
    {
        x = 0;
        y = 0;
        texture = '0';
    }
};