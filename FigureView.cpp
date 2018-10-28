#include "FigureView.h"


FigureView::FigureView() : BaseFigure()
{
	setPosition(sf::Vector2f(0,0));
	setScreenPos ( this->position() * _scale );
	setScale(1);
}

FigureView::FigureView( sf::Vector2f newPosition, float Scale)
{
	setPosition( newPosition );
	setScreenPos(this->position() * _scale);
	setScale( Scale );
}


FigureView::~FigureView()
{
}

void FigureView::Update(float tic)
{
	sf::Vector2f target;

	//Плавное перемещение центра фигуры
	target = this->position() * _scale;
	_ScreenPosition += ( target - _ScreenPosition ) * tic / (float)9;

	//Плавное перемещение точек фигуры
	for (int n = 0; n < 4; n++) {
		target = points()[n] * _scale;
		_ScreenPoints[n] += (target - _ScreenPoints[n]) * tic / (float)4.5;
	}
}

sf::Vector2f FigureView::screenPos(int n)
{
	return _ScreenPosition + _ScreenPoints[n];
}

void FigureView::setScreenPos(sf::Vector2f newPosition)
{
	_ScreenPosition = newPosition;
}

void FigureView::setScreenPoints()
{
	for (int n = 0; n < 4; n++)
		_ScreenPoints[n] = (points()[n] * _scale);
}

void FigureView::setScale(float newScale)
{
	_scale = newScale;
}
