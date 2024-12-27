#include "FieldView.h"



FieldView::FieldView()
{
}


FieldView::~FieldView()
{
}

void FieldView::setAnimSpeeds(float newAnimSpeed_points)
{
	AnimSpeed_points = newAnimSpeed_points;
}

void FieldView::setField(BaseField * newField)
{
	field = newField;
}

void FieldView::UpdateAnimation(float tic)
{
	//Тут пока нет анимации
}

void FieldView::setScale(float newScale)
{
	_scale = newScale;
}

std::vector<sf::Vector2f> FieldView::getPointToView()
{
	std::vector<sf::Vector2f> res;

	for (int i = 0; i < field->Hight(); i++) {
		for (int j = 0; j < field->Width(); j++) {
			if (field->isFilled(j, i)) {
				res.push_back( sf::Vector2f(j * 16, i * 16) );
			}
		}
	}

	return res;
}
