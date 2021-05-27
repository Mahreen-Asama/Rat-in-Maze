#pragma once

struct Pair
{
	int x, y;					//x,y coordinates of matrix
	Pair();
	Pair(int, int);
	bool operator==(Pair&);
	void setValues(int, int);
	int getx();
	int gety();
};
