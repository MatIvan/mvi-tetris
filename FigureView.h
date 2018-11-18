#ifndef FIGUREVIEW_H
#define FIGUREVIEW_H

#pragma once
#include "BaseFigure.h"
#include <SFML/System.hpp>

/*
	FigureView
	Класс фигуры для вычисления координат на экране
	Реализация математики анимаций
*/

using Points4f_t = std::array< sf::Vector2f, 4>;

class FigureView
{
public:
	FigureView();
	~FigureView();

	void setAnimSpeeds(float newAnimSpeed_figure, float newAnimSpeed_points );

	void setFigure(BaseFigure *fig);
	void UpdateAnimation(float tic);
	sf::Vector2f screenPos( int n );
	
	void setScale(float newScale);

private:

	BaseFigure *figure;

	float _scale;
	sf::Vector2f _ScreenPosition;
	Points4f_t	 _ScreenPoints;

	float AnimSpeed_figure = 30;
	float AnimSpeed_points = 30;

	void setScreenPos( float X, float Y);
	void setScreenPoints();
};


#endif //FIGUREVIEW_H