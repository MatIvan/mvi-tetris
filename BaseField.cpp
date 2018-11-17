#include "BaseField.h"
#include <iostream>


BaseField::BaseField()
{
}

BaseField::~BaseField()
{
}

void BaseField::push( BaseFigure *figure )
{
	for (int n = 0; n < 4; n++) {
		sf::Vector2i p = figure->g_points(n);
		_field[p.x][p.y] = true;
	}
}

int BaseField::checkLines()
{
	int res=0;
	int count = 0;

	for (int h = _h - 1; h >= 0; h--) {
		count = 0;
		for (int w = 0; w < _w; w++) {
			if (_field[w][h]) 
				count++;
			else break;
		}

		if (count == _w) {
			res++;
			destroyLine(h);
			h++;
		}
	}

	return res;
}

void BaseField::destroyLine(int line)
{
	for (int h = line; h >= 0; h--) {
		if (h == 0) {
			for (int w = 0; w < _w; w++)
				_field[w][h] = 0;
			break; //for (int h = line; h >= 0; h--)
		} else {
			for (int w = 0; w < _w; w++)
				_field[w][h] = _field[w][h - 1];
		}
	}
}

