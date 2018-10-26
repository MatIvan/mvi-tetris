#include <array>

/*
	������� ��������� � ������ ��� �������
	��� ���������� ������ - ������ �����������.
*/


/*
	Point
	����� � ������������ x,y
*/
struct Point
{
	Point() { x = 0, y = 0; }
	Point(int X, int Y) { set(X, Y); }

	void set(int X, int Y) { x = X, y = Y; }
	void set( Point newPoint) { set( newPoint.x, newPoint.y); }

	Point operator+ (const Point &point) {
		return Point(x + point.x, y + point.y);
	}

	int x, y;
};

/*
	Points4_t
	������ �� 4-� �����
*/
using Points4_t = std::array<Point, 4>;

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
	Figure() {};
	Figure(Point position) { setPosition(position); }
	~Figure() {};

	const Point& position() { return _position; }
	void  setPosition(Point newPosition ) { _position = newPosition; }

	Points4_t points() { return _points;  }
	Point &operator[](int n) { return _points[n]; }
	Point g_point(int n) {
		return Point(_position + _points[n]);
	}

	void moveX (int d) { _position.x += d; }
	void moveY (int d) { _position.y += d; }

	void turn()	{
		for (int n = 0; n < 4; n++) 
			turn90(n);
	}

private:
	Point		_position;
	Points4_t	_points;

	void turn90( int n ) {
		//X = x1 + (x2 - x1)*cos(A) - (y2 - y1)*sin(A)
		//Y = y1 + (x2 - x1)*sin(A) + (y2 - y1)*cos(A)
		//������� ������ �� 90 �������� � ������ ������ 0
		Point R;
		R.x = -_points[n].y;
		R.y =  _points[n].x;
		_points[n].set(R);
	}
};

