#ifndef BASEFIGURE_H
#define BASEFIGURE_H

#include <array>
#include <SFML/System.hpp>

/*
	Базовая фигура для тетриса
	Все координаты в int так как вся игра и логика квадратиками,
	то положение фигуры не может быть не целым
*/


/*
	Points4_t
	Массив из 4-х точек
*/
using Points4i_t = std::array< sf::Vector2i, 4>;

/*
	BaseFigure
	Базовая интерактивная фигура.
	Содержит свои координаты на поле и массив точек.
	Добавлены функции смещения и поворота. 
	Поворот только на 90 градусов и только вокруг 0.0,
	что сильно упростило формулу поворота.
*/
class BaseFigure
{
public:
	BaseFigure() {};
	~BaseFigure() {};
	BaseFigure &operator=(const BaseFigure &figure);

	void setFigureType(int type);
	int  FigureType() const { return _figureType; };

	sf::Vector2i position() const { return _position;   }
	int positionX()			const { return _position.x; }
	int positionY()			const { return _position.y; }

	sf::Vector2i g_points(int n) const { return _position + _points[n]; }
	const sf::Vector2i &points (int n) const { return _points[n]; }
	
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

	sf::Vector2i turn90(int n);
};

#endif //BASEFIGURE_H