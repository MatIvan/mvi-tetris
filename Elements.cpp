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
	case 0: //�������
		_points = { sf::Vector2f(-1,0), sf::Vector2f(0,0), sf::Vector2f(1,0), sf::Vector2f(2,0) };
		break;
	case 1: //������� �����
		_points = { sf::Vector2f(-1,-1), sf::Vector2f(0,-1), sf::Vector2f(0,0), sf::Vector2f(0,1) };
		break;
	case 2: //������� ������
		_points = { sf::Vector2f(1,-1), sf::Vector2f(0,-1), sf::Vector2f(0,0), sf::Vector2f(0,1) };
		break;
	case 3: //������ �����
		_points = { sf::Vector2f(0,-1), sf::Vector2f(0,0), sf::Vector2f(1,0), sf::Vector2f(1,1) };
		break;
	case 4: //������ ������
		_points = { sf::Vector2f(0,-1), sf::Vector2f(0,0), sf::Vector2f(-1,0), sf::Vector2f(-1,1) };
		break;
	case 5: //���������
		_points = { sf::Vector2f(-1,0), sf::Vector2f(0,0), sf::Vector2f(1,0), sf::Vector2f(0,-1) };
		break;
	case 6: //�����
		_points = { sf::Vector2f(0,0), sf::Vector2f(1,0), sf::Vector2f(0,1), sf::Vector2f(1,1) };
		break;
	default:
		break;
	}

}
