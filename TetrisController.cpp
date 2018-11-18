#include "TetrisController.h"



TetrisController::TetrisController( )
{
	SpeedDown = 1;
	SpeedX = 0;
}

void TetrisController::setPosition(float X, float Y)
{
	setPositionX(X);
	setPositionY(Y);
}

void TetrisController::setPositionX(float X)
{
	f_position.x = X;
	figure.setPositionX( (int)X );
}

void TetrisController::setPositionY(float Y)
{
	f_position.y = Y;
	figure.setPositionY( (int)Y );
}

void TetrisController::setSpeeds(float newSpeedDown, float newSpeedX)
{
	SpeedDown = newSpeedDown;
	SpeedX = newSpeedX;

}



void TetrisController::moveX(float d)
{
	f_position.x += d;
}

void TetrisController::moveY(float d)
{
	f_position.y += d;
}

void TetrisController::setFigureType(int type)
{
	figure.setFigureType(type);
}

void TetrisController::KeyReleased(sf::Keyboard::Key key)
{
	switch (key) {
	case sf::Keyboard::Down: 
		SpeedDown = 1;
		break;
	case sf::Keyboard::Left:
	case sf::Keyboard::Right: 
		SpeedX = 0;
		break;
	case sf::Keyboard::Space:
		figure.turn();
		break;
	default: break;
	}
}

void TetrisController::KeyPressed(sf::Keyboard::Key key)
{
	switch (key) {
	case sf::Keyboard::Down:
		SpeedDown += 10;
		break;
	case sf::Keyboard::Left:
		SpeedX = -15;
		break;
	case sf::Keyboard::Right:
		SpeedX = 15;
		break;
	default: break;
	}
}

int TetrisController::Update(float tic)
{
	int res = -1;
	move(tic * SpeedX, tic * SpeedDown);

	sf::Vector2i np(
		figure.positionX() + getDelta(f_position.x, figure.positionX()),
		figure.positionY() + getDelta(f_position.y, figure.positionY())
	);

	if (checkPoints(np)) {
		// двигать можно
		figure.setPosition(np);
	} else {
		// двигать нельзя
		SpeedDown = 1;
		SpeedX = 0;
		setPosition(figure.positionX(), figure.positionY());
	}

	np.y += 1;
	if (!checkPoints(np)) {
		//Под фигурой что-то есть.
		field.push(&figure);
		return field.checkLines();
	}

	return -1;
}

int TetrisController::getDelta(float pos_f, int pos_i)
{
	int delta = pos_f - pos_i;
	if (delta >= 1) return 1;
	else if (delta <= -1) return -1;
	return 0;
}

bool TetrisController::checkPoints(sf::Vector2i newPos)
{
	for (int n = 0; n < 4; n++) {
		sf::Vector2i p = figure.points(n) + newPos;

		//Выход за границы поля
		if (	(p.x < 0) || 
				(p.x > field.Width() - 1) || 
				(p.y > field.Hight() - 1)		) return false;

		//Место на поле занято
		if ( field.isFilled(p.x,p.y) ) return false;

	}
	return true;
}
