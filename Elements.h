#include <array>
#include <SFML/System.hpp>

/*
	Базовые структуры и классы для тетриса
*/

/*
	Points4_t
	Массив из 4-х точек
*/
using Points4_t = std::array< sf::Vector2f, 4>;

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
	BaseFigure() { _position = sf::Vector2f(0, 0);  };
	BaseFigure(sf::Vector2f position) { setPosition(position); }
	~BaseFigure() {};

	sf::Vector2f position() { 
		sf::Vector2f res;
		res.x = (int)_position.x;
		res.y = (int)_position.y;
		return res; 
	}

	void  setPosition(sf::Vector2f newPosition ) { _position = newPosition; }

	const Points4_t &points() { return _points;  }
	sf::Vector2f &operator[](int n) { return _points[n]; }
	sf::Vector2f g_point(int n) {
		return sf::Vector2f( (int)_position.x + _points[n].x,
						     (int)_position.y + _points[n].y);
	}

	void move(float dX, float dY) { moveX(dX); moveY(dY); }
	void moveX (float d) { _position.x += d; }
	void moveY (float d) { _position.y += d; }

	void turn()	{
		for (int n = 0; n < 4; n++) 
			turn90(n);
	}

private:
	sf::Vector2f	_position;
	Points4_t		_points;

	void turn90( int n ) {
		//X = x1 + (x2 - x1)*cos(A) - (y2 - y1)*sin(A)
		//Y = y1 + (x2 - x1)*sin(A) + (y2 - y1)*cos(A)
		//Поворот только на 90 градусов и только вокруг 0
		sf::Vector2f R;
		R.x = -_points[n].y;
		R.y =  _points[n].x;
		_points[n] = R;
	}
};

