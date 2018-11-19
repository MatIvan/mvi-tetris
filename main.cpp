#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

#include "TetrisView.h"
#include "NumericStorage.h"

using namespace std;

#define MAIN_SCALE 16

int main()
{
	cout << "Start MVI_tetris." << endl;

	sf::RenderWindow window(sf::VideoMode((12+4+2+2)*16, 24*16), "SFML works!");
	sf::Color ClearColor(195, 195, 195);
	
	//Главный спрайт активных элементов
	sf::Image im;
	im.loadFromFile("images/block16.png");
	im.createMaskFromColor(sf::Color(255, 0, 0));
	sf::Texture tx;
	tx.loadFromImage(im);
	sf::Sprite sp(tx);
	sp.setPosition(10, 10);

	//Спрайт пассивных элементов
	//sf::Image im;
	im.loadFromFile("images/block16_gray.png");
	im.createMaskFromColor(sf::Color(255, 0, 0));
	sf::Texture tx1;
	tx1.loadFromImage(im);
	sf::Sprite sp_gray(tx1);

	//ТЕСТ
	NumericStorage ns;
	ns.LoadSprites("images/numbers.png",6,11);

	//Таймеры
	sf::Clock clock;
	float one_tic = 0;	//Время потраченное на одну обработку одного цикла

	//Управляемая фигура и поле
	TetrisView tv;
	tv.setScale( MAIN_SCALE );
	tv.setPosition(5, 0);
	tv.setFigureType( rand() % 7 );
	tv.setSpeeds(1); //SpeedDownMax
	tv.setAnimSpeeds(30, 30); //figure, points

	//Следующая фигура
	BaseFigure nextFigureB;
	nextFigureB.setPosition(13, 3);
	nextFigureB.setFigureType(rand() % 7);
	FigureView nextFigureV;
	nextFigureV.setFigure(&nextFigureB);
	nextFigureV.setScale(MAIN_SCALE);
	nextFigureV.setAnimSpeeds(15, 15);


	int score = 0;
	int count_line = 0;
	sf::Vector2f offset( MAIN_SCALE, MAIN_SCALE );

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  tv.KeyPressed(sf::Keyboard::Left, one_tic);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) tv.KeyPressed(sf::Keyboard::Right, one_tic);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  tv.KeyPressed(sf::Keyboard::Down, one_tic);


		count_line = tv.Update(one_tic);
		if (count_line >= 0) {
			tv.setFigureType( nextFigureB.FigureType() );
			nextFigureB.setFigureType(rand() % 7);
			tv.setPosition( 5, 0 );

			score += count_line;
			std::cout << score << std::endl;
		}



		//Анимации
		tv.UpdateAnimation( one_tic );
		nextFigureV.UpdateAnimation( one_tic );

		window.clear(ClearColor);
		//Рисуем фон
		{
			//TODO: переделать на один большой спрайт

			//Игровой стакан
			for (int i = 1; i < 11; i++) {
				for (int j = 1; j < 21; j++) {
					sp_gray.setPosition( i * MAIN_SCALE, j * MAIN_SCALE );
					window.draw(sp_gray);
				}
			}

			//Поле отображения седующей фигуры
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					sp_gray.setPosition( (i+12) * MAIN_SCALE, (j+1) * MAIN_SCALE);
					window.draw(sp_gray);
				}
			}

			//Следующая фигура
			for (int n = 0; n < 4; n++) {
				sp.setPosition(nextFigureV.screenPos(n) );
				window.draw(sp);
			}
		}

		//Рисуем фигуру и поле
		std::vector<sf::Vector2f> points;
		points = tv.getPointsToView();
		for (auto& p : points) {
			sp.setPosition( p + offset );
			window.draw(sp);
		}

		
		//ТЕСТ
		char cc = ' ';
		window.draw(ns.getSprite(&cc, sf::Vector2f(200 + 7 * 0, 100) ) );

		window.display();


	}

	return 0;
}

