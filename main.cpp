#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

#include "Elements.h"

using namespace std;


int main()
{
	cout << "Start MVI_tetris." << endl;

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::Color ClearColor(195, 195, 195);
	
	sf::Image im;
	im.loadFromFile("images/block16.png");
	im.createMaskFromColor(sf::Color(255, 0, 0));

	sf::Texture tx;
	tx.loadFromImage(im);

	sf::Sprite sp(tx);
	sp.setPosition(10, 10);

	float timer = 0;
	float delay = 0.6;
	sf::Clock clock;


	//Точки на фигуре задаются относительно центра поворота.
	Figure MainFigure;
	MainFigure[0].set( 0, -1);
	MainFigure[1].set(-1,  0);	//  #
	MainFigure[2].set( 0,  0);  // ###
	MainFigure[3].set( 1,  0);


	int needMoveX = 0, needMoveY = 0;
	bool needTurn = false;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event:: Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  needMoveY = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  needMoveX =-1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) needMoveX = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) needTurn = true;


		if (timer > delay) {
			//logik
			timer = 0;

			//Управление
			MainFigure.moveX(needMoveX);
			MainFigure.moveY(needMoveY);
			needMoveX = 0;
			needMoveY = 0;
			if (needTurn) {
				MainFigure.turn();
				needTurn = false;
			}


			//Гравитация
			MainFigure.moveY(1);
			if (MainFigure.position().y > 10) MainFigure.moveY(-10);
		}


		window.clear(ClearColor);
		for (int n = 0; n < 4; n++) {
			sf::Vector2f vec(MainFigure.g_point(n).x * 16, 
			MainFigure.g_point(n).y * 16);
			sp.setPosition(vec);
			window.draw(sp);
		}
		window.display();


	}

	return 0;
}

