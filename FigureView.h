#pragma once
#include "Elements.h"
#include <SFML/System.hpp>

/*
	FigureView
	����� ������ ������������� ��������� �� ������
	���������� ���������� ��������
*/

class FigureView : public BaseFigure
{
public:
	FigureView();
	FigureView( float X, float Y, float Scale );
	~FigureView();

	void Update(float tic);
	sf::Vector2f screenPos( int n );

private:
	float _scale;
	Point_f _ScreenPosition;

};

