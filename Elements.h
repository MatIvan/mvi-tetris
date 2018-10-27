#include <array>

/*
	������� ��������� � ������ ��� �������
*/


/*
	Point
	������ ������ ����� � ������������ x,y
*/
template <typename T>
struct Point
{
	Point() { x = 0, y = 0; }
	Point(T X, T Y) { set(X, Y); }

	void set(T X, T Y) { x = X, y = Y; }
	void set( Point newPoint) { set( newPoint.x, newPoint.y); }

	T x, y;
};

using Point_i = Point<int>;
using Point_f = Point<float>;

/*
	Points4_t
	������ �� 4-� �����
*/
using Points4_t = std::array<Point_i, 4>;

/*
	Figure
	������� ������������� ������.
	�������� ���� ���������� �� ���� � ������ �����.
	��������� ������� �������� � ��������. 
	������� ������ �� 90 �������� � ������ ������ 0.0,
	��� ������ ��������� ������� ��������.
*/
class Figure
{
public:
	Figure() { _position.set(0, 0);  };
	Figure(Point_f position) { setPosition(position); }
	~Figure() {};

	const Point_f& position() { return _position; }
	void  setPosition(Point_f newPosition ) { _position = newPosition; }

	Points4_t points() { return _points;  }
	Point_i &operator[](int n) { return _points[n]; }
	Point_i g_point(int n) {
		return Point_i( (int)_position.x + _points[n].x,
						(int)_position.y + _points[n].y);
	}

	void moveX (float d) { _position.x += d; }
	void moveY (float d) { _position.y += d; }

	void turn()	{
		for (int n = 0; n < 4; n++) 
			turn90(n);
	}

private:
	Point_f		_position;
	Points4_t	_points;

	void turn90( int n ) {
		//X = x1 + (x2 - x1)*cos(A) - (y2 - y1)*sin(A)
		//Y = y1 + (x2 - x1)*sin(A) + (y2 - y1)*cos(A)
		//������� ������ �� 90 �������� � ������ ������ 0
		Point_i R;
		R.x = -_points[n].y;
		R.y =  _points[n].x;
		_points[n].set(R);
	}
};

