#ifndef TETRISVIEW_H
#define TETRISVIEW_H

#pragma once
#include "TetrisController.h"
#include "FigureView.h"
#include "FieldView.h"
#include <SFML/Graphics.hpp>

using Points4f_t = std::array< sf::Vector2f, 4>;

class TetrisView : public TetrisController
{
public:
	TetrisView();
	~TetrisView();

	void setAnimSpeeds(float newAnimSpeed_figure, float newAnimSpeed_points);

	void UpdateAnimation(float tic);
	void setScale(float newScale);

	std::vector<sf::Vector2f> getPointsToView();

private:
	FigureView figureV;
	FieldView  fieldV;
};



#endif //TETRISVIEW_H