#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>


#include "FigureView.h"
#include "BaseField.h"

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


	//Фигура, которой управляет игрок
	FigureView MainFigure( sf::Vector2f(0,0), 16);
	MainFigure.setFigure( rand() % 7 );
	float SpeedDown = 1;
	float SpeedX    = 0;
	sf::Vector2f controlMove(0,0);


	//Игровое поле
	BaseField Field;


	int score = 0;
	int count_line = 0;
	

	while (window.isOpen())
	{
		one_tic = clock.getElapsedTime().asSeconds();
		clock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event:: Closed)
				window.close();
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Down) {
					SpeedDown = 1;
				}
				if (event.key.code == sf::Keyboard::Left) {
					SpeedX = 0;
				}
				if (event.key.code == sf::Keyboard::Right) {
					SpeedX = 0;
				}
				if (event.key.code == sf::Keyboard::Space) {
					MainFigure.turn();
				}
			}
		}

		//Управление
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  SpeedX = -15;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) SpeedX = 15;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  SpeedDown += 170 * one_tic;

		MainFigure.move( one_tic * SpeedX , one_tic * SpeedDown );
		

		//Ограничения на перемещения + Проверка на столкновения
		count_line = Field.Check(MainFigure);
		if (count_line >= 0) {
			MainFigure.setFigure(rand() % 7);
			MainFigure.setPosition(sf::Vector2f(5, 0));
			SpeedDown = 1;

			score += count_line;
			std::cout << score << std::endl;
		}



		//Анимации
		MainFigure.Update( one_tic );
		

		window.clear(ClearColor);
		//Рисуем спрайты фигуры
		for (int n = 0; n < 4; n++) {
			sp.setPosition( MainFigure.screenPos(n) );
			window.draw(sp);
		}

		//Рисуем поле
		for (int i = 0; i < Field.Hight(); i++) {
			for (int j = 0; j < Field.Width(); j++) {
				if (Field.isFilled(j, i)) {
					sp.setPosition( j*16, i*16 );
					window.draw(sp);
				}
			}
		}


		window.display();


	}

	return 0;
}

