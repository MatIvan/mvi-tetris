#ifndef TETRISCONTROLLER_H
#define TETRISCONTROLLER_H

#pragma once
#include "BaseFigure.h"
#include "BaseField.h"
#include <SFML/Graphics.hpp>



class TetrisController
{
public:
	TetrisController();
	~TetrisController() {}

	void setFigureType(int type);

	void setPosition( float X, float Y );
	void setPositionX(float X);
	void setPositionY(float Y);

	void setSpeeds(float newSpeedDown, float newSpeedX);

	BaseFigure *getBaseFigure() { return &figure; }
	BaseField  *getBaseField() { return &field; }

	// ������:
	//			-1 ������ � ������
	//			 0 ������ ������������, �� ��� ������ �����
	//			 ���  ���������� ����������� � ������������ �����.
	int Update( float tic );

	void KeyReleased(sf::Keyboard::Key key);
	void KeyPressed (sf::Keyboard::Key key);

private:
	sf::Vector2f f_position;

	BaseFigure figure;
	BaseField  field;

	

	float SpeedDown;
	float SpeedX;

	void move(float dX, float dY) { moveX(dX); moveY(dY); }
	void moveX(float d);
	void moveY(float d);

	int getDelta(float pos_f, int pos_i);

	bool checkPoints(sf::Vector2i newPos);
};

#endif //TETRISCONTROLLER_H