#include"Pair.h"

Pair::Pair() :x(0), y(0)
{
	//constructor
}

Pair::Pair(int xx, int yy)
{
	x = xx, y = yy;
}

bool Pair::operator==(Pair& p2)
{
	if (x == p2.x && y == p2.y)
		return true;
	else
		return false;
}

void Pair::setValues(int xx, int yy)
{
	x = xx, y = yy;
}

int Pair::getx()
{
	return x;
}

int Pair::gety()
{
	return y;
}