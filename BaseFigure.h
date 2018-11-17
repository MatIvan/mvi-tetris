#ifndef BASEFIGURE_H
#define BASEFIGURE_H

#include <array>
#include <SFML/System.hpp>

/*
	������� ������ ��� �������
	��� ���������� � int ��� ��� ��� ���� � ������ ������������,
	�� ��������� ������ �� ����� ���� �� �����
*/


/*
	Points4_t
	������ �� 4-� �����
*/
using Points4i_t = std::array< sf::Vector2i, 4>;

/*
	BaseFigure
	������� ������������� ������.
	�������� ���� ���������� �� ���� � ������ �����.
	��������� ������� �������� � ��������. 
	������� ������ �� 90 �������� � ������ ������ 0.0,
	��� ������ ��������� ������� ��������.
*/
class BaseFigure
{
public:
	BaseFigure() {};
	~BaseFigure() {};

	void setFigureType(int type);
	int  FigureType() { return _figureType; };

	sf::Vector2i position() { return _position;   }
	int positionX()			{ return _position.x; }
	int positionY()			{ return _position.y; }

	sf::Vector2i g_points(int n)	 { return _position + _points[n]; }
	const sf::Vector2i &points (int n)   { return _points[n]; }
	
	void setPosition  (sf::Vector2i newPos ) { _position = newPos; }
	void setPosition  (int X, int Y)		 { setPositionX(X); setPositionY(Y); }
	void setPositionX ( int X )				 { _position.x = X; }
	void setPositionY ( int Y )				 { _position.y = Y; }
	
	void move  (int dX, int dY)	{ moveX(dX); moveY(dY); }
	void moveX (int d)			{ _position.x += d; }
	void moveY (int d)			{ _position.y += d; }
	
	void turn();

private:
	int _figureType;
	sf::Vector2i	_position;
	Points4i_t		_points;

	void turn90(int n);
};

#endif //BASEFIGURE_H