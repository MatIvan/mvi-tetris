#include "FigureView.h"


FigureView::FigureView()
{
}

FigureView::~FigureView()
{
}

void FigureView::setAnimSpeeds(float newAnimSpeed_figure, float newAnimSpeed_points)
{
	AnimSpeed_figure = newAnimSpeed_figure;
	AnimSpeed_points = newAnimSpeed_points;
}

void FigureView::setFigure(BaseFigure * fig)
{
	figure = fig;
}

void FigureView::UpdateAnimation(float tic)
{
	sf::Vector2f target;
	sf::Vector2i pos;

	//Плавное перемещение центра фигуры
	pos = figure->position();
	target = sf::Vector2f( pos.x * _scale, pos.y * _scale);
	_ScreenPosition += (target - _ScreenPosition) * AnimSpeed_figure * tic;

	//Плавное перемещение точек фигуры
	for (int n = 0; n < 4; n++) {
		pos = figure->points(n);
		target = sf::Vector2f( pos.x * _scale, pos.y * _scale);
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
	setScreenPoints();
}

void FigureView::setScreenPoints()
{
	sf::Vector2i pos;
	for (int n = 0; n < 4; n++) {
		pos = figure->points(n);
		_ScreenPoints[n].x = (pos.x * _scale);
		_ScreenPoints[n].y = (pos.y * _scale);
	}
}

void FigureView::setScale(float newScale)
{
	_scale = newScale;
}
