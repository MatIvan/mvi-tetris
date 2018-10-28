#ifndef BASEFIELD_H
#define BASEFIELD_H

#pragma once
#include <array>
#include "Elements.h"

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

	//  онтролирует, что все точки фигуры не выход€т за границы
	// и сдвигает фигуру.
    // ѕроверка на контакт фигуры с другими элементами на поле
	// ¬ернет:
	//			-1 фигура в полете
	//			 0 фигура остановилась, но нет полных строк
	//			 или  количество заполненных и уничтоженных строк.
	int Check(BaseFigure &figure);

private:
	static const int _h = 20;
	static const int _w = 10;
	bool _field[_w][_h] = { 0 };

	//«аписать фигуру в поле
	void push( BaseFigure & figure);

	//ѕроверить все линии на поле и удалить заполненные
	//¬ернет количество заполненных
	int checkLines();
	void destroyLine(int line);
};


#endif //BASEFIELD_H