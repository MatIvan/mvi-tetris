#ifndef TETRISCONTROLLER_H
#define TETRISCONTROLLER_H

#pragma once
#include "BaseFigure.h"
#include "BaseField.h"
#include <SFML/Graphics.hpp>

#define DELTA_SPEED_DOWN 200
#define DELTA_SPEED_X 70

class TetrisController
{
public:
	TetrisController();
	~TetrisController() {}

	void setFigureType(int type);

	void setPosition( float X, float Y );
	void setPositionX(float X);
	void setPositionY(float Y);

	void setSpeeds(float newSpeedDown);

	BaseFigure *getBaseFigure() { return &figure; }
	BaseField  *getBaseField() { return &field; }

	// ������:
	//			-1 ������ � ������
	//			 0 ������ ������������, �� ��� ������ �����
	//			 ���  ���������� ����������� � ������������ �����.
	int Update( float tic );

	void KeyReleased(sf::Keyboard::Key key);
	void KeyPressed (sf::Keyboard::Key key, float tic);

private:
	sf::Vector2f f_position;

	BaseFigure figure;
	BaseField  field;

	
	float SpeedDownMax; //������������� �������� ������� (�������� �� �����������)
	float SpeedDown;	//������������ �������� �������
	float SpeedX;		//������������ �������� ������

	void move(float dX, float dY) { moveX(dX); moveY(dY); }
	void moveX(float d);
	void moveY(float d);

	void TurnFiguer();

	int getDelta(float pos_f, int pos_i);

	bool checkPoints(sf::Vector2i newPos, const BaseFigure&fig);
};

#endif //TETRISCONTROLLER_H