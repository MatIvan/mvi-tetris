#ifndef BASEFIELD_H
#define BASEFIELD_H

#pragma once
#include <array>
#include "BaseFigure.h"

#define FIELD_HIGHT 20
#define FIELD_WIDTH 10

class BaseField
{
public:
	BaseField();
	~BaseField();

	const int Hight() { return _h; }
	const int Width() { return _w; }
	bool isFilled(int x, int y) { return _field[x][y]; }

	//Записать фигуру в поле
	void push( BaseFigure *figure);

	//Проверить все линии на поле и удалить заполненные
	//Вернет количество заполненных
	int checkLines();

private:
	static const int _h = 20;
	static const int _w = 10;
	bool _field[_w][_h] = { 0 };

	void destroyLine(int line);
};


#endif //BASEFIELD_H