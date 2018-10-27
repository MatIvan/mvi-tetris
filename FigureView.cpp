#include "FigureView.h"


FigureView::FigureView() : BaseFigure()
{

}

FigureView::FigureView(float X, float Y, float Scale)
{
	_ScreenPosition.set(X, Y);
	_scale = Scale;
}


FigureView::~FigureView()
{
}

void FigureView::Update(float tic)
{
	float targetX, targetY;
	targetX = (int)position().x * _scale;
	targetY = (int)position().y * _scale;
	_ScreenPosition.x += ((targetX - _ScreenPosition.x) * tic ) / _scale;
	_ScreenPosition.y += ((targetY - _ScreenPosition.y) * tic ) / _scale;
}

sf::Vector2f FigureView::screenPos(int n)
{
	return sf::Vector2f(
		_ScreenPosition.x + points()[n].x * _scale,
		_ScreenPosition.y + points()[n].y * _scale);
}
