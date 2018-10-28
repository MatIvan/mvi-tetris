#ifndef FIGUREVIEW_H
#define FIGUREVIEW_H

#pragma once
#include "Elements.h"
#include <SFML/System.hpp>

/*
	FigureView
	Класс фигуры длявычисления координат на экране
	Реализация математики анимаций
*/

class FigureView : public BaseFigure
{
public:
	FigureView();
	FigureView( sf::Vector2f newPosition, float Scale );
	~FigureView();

	void Update(float tic);
	sf::Vector2f screenPos( int n );
	
	void setScale(float newScale);

private:
	float _scale;
	sf::Vector2f _ScreenPosition;
	Points4_t	 _ScreenPoints;

	void setScreenPos(sf::Vector2f newPosition);
	void setScreenPoints();
};


#endif //FIGUREVIEW_H