#include "BaseField.h"
#include <iostream>


BaseField::BaseField()
{
}


BaseField::~BaseField()
{
}

int BaseField::Check(BaseFigure & figure)
{
	for (int n = 0; n < 4; n++) {
		sf::Vector2f p = figure.g_point(n);

		//Выход за границы поля
		if (p.x < 0) figure.moveX( -p.x );
		if (p.x >_w-1) figure.moveX( _w-1 - p.x );
		if (p.y > _h-1) figure.moveY( _h-1 - p.y );

		//Остановить фигуру или нет
		if (_field[(int)p.x][(int)p.y + 1] || p.y == _h-1) {
			push(figure);
			return checkLines(); 
		}

	}
	return -1; //Фигура в полете
}

void BaseField::push( BaseFigure & figure)
{
	for (int n = 0; n < 4; n++) {
		sf::Vector2f p = figure.g_point(n);
		_field[(int)p.x][(int)p.y] = true;
	}
}

int BaseField::checkLines()
{
	int res=0;
	/*
	for (int h = _h-1; h >=0 ; h--) {
		int count = 0;
		for (int w = 0; w < _w; w++)
			if (_field[w][h]) count++;

		if (count == _w) {
			res++;
			destroyLine(h);
			h++;
		}
	}
	*/
	return res;
}

void BaseField::destroyLine(int line)
{
	if (line == 0) {
		for (int w = 0; w < _w; w++) 
			_field[w][line] = 0;
		return;
	}
	for (int w = 0; w < _w; w++)
		_field[w][line] = _field[w][line - 1];

}

