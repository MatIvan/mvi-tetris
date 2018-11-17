#include "FigureView.h"


FigureView::FigureView() : BaseFigure()
{
	setPosition( 0,0 );
	setScreenPos ( this->position().x * _scale, this->position().y * _scale);
	setScale(1);
}

FigureView::FigureView(int X, int Y, float Scale)
{
	setPosition( X,Y );
	setScreenPos( this->position().x * _scale, this->position().y * _scale );
	setScale( Scale );
}


FigureView::~FigureView()
{
}

void FigureView::UpdateAnimation(float tic)
{
	sf::Vector2f target;

	//Плавное перемещение центра фигуры
	target = sf::Vector2f( this->position().x * _scale, this->position().y * _scale);
	_ScreenPosition += (target - _ScreenPosition) * AnimSpeed_figure * tic;

	//Плавное перемещение точек фигуры
	for (int n = 0; n < 4; n++) {
		target = sf::Vector2f( points(n).x * _scale, points(n).y * _scale);
		_ScreenPoints[n] += (target - _ScreenPoints[n]) * AnimSpeed_points * tic;
	}
}

sf::Vector2f FigureView::screenPos(int n)
{
	return _ScreenPosition + _ScreenPoints[n];
}

void FigureView::setScreenPos(float X, float Y)
{
	_ScreenPosition.x = X;
	_ScreenPosition.y = Y;
}

void FigureView::setScreenPoints()
{
	for (int n = 0; n < 4; n++) {
		_ScreenPoints[n].x = (points(n).x * _scale);
		_ScreenPoints[n].y = (points(n).y * _scale);
	}
}

void FigureView::setScale(float newScale)
{
	_scale = newScale;
}
