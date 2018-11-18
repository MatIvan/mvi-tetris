#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#pragma once
#include "BaseField.h"
#include <vector>
#include <SFML/System.hpp>

using Points4f_t = std::array< sf::Vector2f, 4>;

class FieldView
{
public:
	FieldView();
	~FieldView();

	void setAnimSpeeds( float newAnimSpeed_points);

	void setField(BaseField *newField);
	void UpdateAnimation(float tic);

	void setScale(float newScale);

	std::vector<sf::Vector2f> getPointToView();

private:

	BaseField *field;

	float _scale;

	float AnimSpeed_points;

};

#endif //FIELDVIEW_H