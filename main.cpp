#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

#include "TetrisView.h"

using namespace std;

int main()
{
	cout << "Start MVI_tetris." << endl;

	sf::RenderWindow window(sf::VideoMode(12*16, 24*16), "SFML works!");
	sf::Color ClearColor(195, 195, 195);
	
	sf::Image im;
	im.loadFromFile("images/block16.png");
	im.createMaskFromColor(sf::Color(255, 0, 0));

	sf::Texture tx;
	tx.loadFromImage(im);

	sf::Sprite sp(tx);
	sp.setPosition(10, 10);

	//Таймеры
	sf::Clock clock;
	float one_tic = 0;	//Время потраченное на одну обработку одного цикла

	//Управляемая фигура и поле
	TetrisView tv;
	tv.setScale(16);
	tv.setPosition(5, 0);
	tv.setFigureType( rand() % 7 );

	tv.setSpeeds(1, 0); //SpeedDown, SpeedX
	tv.setAnimSpeeds(30, 30); //figure, points


	int score = 0;
	int count_line = 0;
	

	while (window.isOpen())
	{
		one_tic = clock.getElapsedTime().asSeconds();
		clock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyReleased:
				tv.KeyReleased(event.key.code);
				break;
			default: break;
			}
		}

		//Управление
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  tv.KeyPressed(sf::Keyboard::Left);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) tv.KeyPressed(sf::Keyboard::Right);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  tv.KeyPressed(sf::Keyboard::Down);


		count_line = tv.Update(one_tic);
		if (count_line >= 0) {
			tv.setFigureType(rand() % 7);
			tv.setPosition( 5, 0 );

			score += count_line;
			std::cout << score << std::endl;
		}



		//Анимации
		tv.UpdateAnimation( one_tic );


		window.clear(ClearColor);
		//Рисуем 
		std::vector<sf::Vector2f> points;
		points = tv.getPointsToView();
		for (auto& p : points) {
			sp.setPosition( p );
			window.draw(sp);
		}
		/*
		//Рисуем поле
		for (int i = 0; i < Field.Hight(); i++) {
			for (int j = 0; j < Field.Width(); j++) {
				if (Field.isFilled(j, i)) {
					sp.setPosition( j*16, i*16 );
					window.draw(sp);
				}
			}
		}
		*/

		window.display();


	}

	return 0;
}

