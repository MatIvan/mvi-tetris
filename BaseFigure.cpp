#include "BaseFigure.h"

void BaseFigure::setFigureType(int type)
{
	//Точки на фигуре задаются относительно центра поворота.
	_figureType = type;
	using pt = sf::Vector2i;
	switch (_figureType)
	{
	case 0: //Палочка
		_points = { pt(-1,0), pt(0,0), pt(1,0), pt(2,0) };
		break;
	case 1: //Кочерга левая
		_points = { pt(-1,-1), pt(0,-1), pt(0,0), pt(0,1) };
		break;
	case 2: //Кочерга правая
		_points = { pt(1,-1), pt(0,-1), pt(0,0), pt(0,1) };
		break;
	case 3: //Зигзаг левый
		_points = { pt(0,-1), pt(0,0), pt(1,0), pt(1,1) };
		break;
	case 4: //Зигзаг правый
		_points = { pt(0,-1), pt(0,0), pt(-1,0), pt(-1,1) };
		break;
	case 5: //Полукрест
		_points = { pt(-1,0), pt(0,0), pt(1,0), pt(0,-1) };
		break;
	case 6: //Кубик
		_points = { pt(0,0), pt(1,0), pt(0,1), pt(1,1) };
		break;
	default:
		break;
	}
}

void BaseFigure::turn()
{
	for (int n = 0; n < 4; n++)
		turn90(n);
}

void BaseFigure::turn90(int n)
{
	//X = x1 + (x2 - x1)*cos(A) - (y2 - y1)*sin(A)
	//Y = y1 + (x2 - x1)*sin(A) + (y2 - y1)*cos(A)
	//Поворот только на 90 градусов и только вокруг 0
	sf::Vector2i R;
	R.x = -_points[n].y;
	R.y =  _points[n].x;
	_points[n] = R;
}
