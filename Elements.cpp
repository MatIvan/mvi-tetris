#include "Elements.h"

BaseFigure::BaseFigure()
{
	_position = sf::Vector2f(0, 0);
}

BaseFigure::BaseFigure(sf::Vector2f position)
{
	setPosition(position);
}

sf::Vector2f BaseFigure::position()
{
	sf::Vector2f res;
	res.x = (int)_position.x;
	res.y = (int)_position.y;
	return res;
}

sf::Vector2f BaseFigure::g_point(int n)
{
	return sf::Vector2f((int)_position.x + _points[n].x,
						(int)_position.y + _points[n].y);
}

void BaseFigure::setFigure(int id)
{
	switch (id)
	{
	case 0: //Палочка
		_points = { sf::Vector2f(-1,0), sf::Vector2f(0,0), sf::Vector2f(1,0), sf::Vector2f(2,0) };
		break;
	case 1: //Кочерга левая
		_points = { sf::Vector2f(-1,-1), sf::Vector2f(0,-1), sf::Vector2f(0,0), sf::Vector2f(0,1) };
		break;
	case 2: //Кочерга правая
		_points = { sf::Vector2f(1,-1), sf::Vector2f(0,-1), sf::Vector2f(0,0), sf::Vector2f(0,1) };
		break;
	case 3: //Зигзаг левый
		_points = { sf::Vector2f(0,-1), sf::Vector2f(0,0), sf::Vector2f(1,0), sf::Vector2f(1,1) };
		break;
	case 4: //Зигзаг правый
		_points = { sf::Vector2f(0,-1), sf::Vector2f(0,0), sf::Vector2f(-1,0), sf::Vector2f(-1,1) };
		break;
	case 5: //Полукрест
		_points = { sf::Vector2f(-1,0), sf::Vector2f(0,0), sf::Vector2f(1,0), sf::Vector2f(0,-1) };
		break;
	case 6: //Кубик
		_points = { sf::Vector2f(0,0), sf::Vector2f(1,0), sf::Vector2f(0,1), sf::Vector2f(1,1) };
		break;
	default:
		break;
	}

}
