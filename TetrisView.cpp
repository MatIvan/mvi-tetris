#include "TetrisView.h"





TetrisView::TetrisView() : TetrisController()
{
	figureV.setFigure( this->getBaseFigure() );
	figureV.setScale(1);

	fieldV.setField(this->getBaseField());
	fieldV.setScale(1);
}

TetrisView::~TetrisView()
{
}

void TetrisView::setAnimSpeeds(float newAnimSpeed_figure, float newAnimSpeed_points)
{
	figureV.setAnimSpeeds(newAnimSpeed_figure, newAnimSpeed_points);
	fieldV.setAnimSpeeds(newAnimSpeed_points);
}

void TetrisView::UpdateAnimation(float tic)
{
	figureV.UpdateAnimation(tic);
	fieldV.UpdateAnimation(tic);
}

void TetrisView::setScale(float newScale)
{
	figureV.setScale(newScale);
	fieldV.setScale(newScale);
}

std::vector<sf::Vector2f> TetrisView::getPointsToView()
{
	std::vector<sf::Vector2f> res;

	//Точки фигуры
	for (int i = 0; i < 4; i++) {
		res.push_back(figureV.screenPos(i));
	}

	//Точки поля
	std::vector<sf::Vector2f> fp;
	fp = fieldV.getPointToView();
	res.insert(res.end(), fp.begin(), fp.end() );


	return res;
}
