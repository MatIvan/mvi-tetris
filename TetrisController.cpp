#include "TetrisController.h"



TetrisController::TetrisController( )
{
	SpeedDownMax = 1;
	SpeedDown = SpeedDownMax;
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
	figure.setPositionX((int)X);
}

void TetrisController::setPositionY(float Y)
{
	f_position.y = Y;
	figure.setPositionY((int)Y);
}

void TetrisController::setSpeeds(float newSpeedDown)
{
	SpeedDownMax = newSpeedDown;
}



void TetrisController::moveX(float d)
{
	f_position.x += d;
}

void TetrisController::moveY(float d)
{
	f_position.y += d;
}

void TetrisController::TurnFiguer()
{
	BaseFigure tf = figure;
	tf.turn();
	if ( checkPoints(tf.position(), tf) ) {
		figure.turn();
	}
}

void TetrisController::setFigureType(int type)
{
	figure.setFigureType(type);
}

void TetrisController::KeyReleased(sf::Keyboard::Key key)
{
	switch (key) {
	case sf::Keyboard::Down: 
		SpeedDown = SpeedDownMax;
		break;
	case sf::Keyboard::Left:
	case sf::Keyboard::Right: 
		SpeedX = 0;
		f_position.x = figure.positionX();
		break;
	case sf::Keyboard::Space:
		TurnFiguer();
		break;
	default: break;
	}
}

void TetrisController::KeyPressed(sf::Keyboard::Key key, float tic )
{
	switch (key) {
	case sf::Keyboard::Down:
		SpeedDown += DELTA_SPEED_DOWN * tic;
		break;
	case sf::Keyboard::Left:
		if (SpeedX == 0) moveX(-1); 
		SpeedX -= DELTA_SPEED_X * tic;
		break;
	case sf::Keyboard::Right:
		if (SpeedX == 0) moveX(1);
		SpeedX += DELTA_SPEED_X * tic;
		break;
	default: break;
	}
}

int TetrisController::Update(float tic)
{
	move(tic * SpeedX, tic * SpeedDown);

	sf::Vector2i np(
		figure.positionX() + getDelta(f_position.x, figure.positionX()),
		figure.positionY() + getDelta(f_position.y, figure.positionY())
	);

	if (checkPoints(np,figure)) {
		// двигать можно
		figure.setPosition(np);
		return -1;
	}

		// двигать нельзя
		SpeedX = 0;
		f_position.x = figure.positionX();

		sf::Vector2i np2(
			figure.positionX() + getDelta(f_position.x, figure.positionX()),
			figure.positionY() + getDelta(f_position.y, figure.positionY())
		);
		np2.y += 1;
		if (!checkPoints(np2,figure)) {
			//Под фигурой что-то есть.
			SpeedDown = SpeedDownMax;
			f_position.y = figure.positionY();

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

bool TetrisController::checkPoints(sf::Vector2i newPos, const BaseFigure&fig)
{
	for (int n = 0; n < 4; n++) {
		sf::Vector2i p = fig.points(n) + newPos;

		//Выход за границы поля
		if (	(p.x < 0) || 
				(p.x > field.Width() - 1) || 
				(p.y > field.Hight() - 1)		) return false;

		//Место на поле занято
		if ( field.isFilled(p.x,p.y) ) return false;

	}
	return true;
}
