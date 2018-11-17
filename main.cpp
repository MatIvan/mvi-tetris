#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

#include "TetrisController.h"

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
	TetrisController tc;
	tc.setFigureType( rand() % 7 );

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
				tc.KeyReleased(event.key.code);
				break;
			default: break;
			}
		}

		//Управление
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  tc.KeyPressed(sf::Keyboard::Left);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) tc.KeyPressed(sf::Keyboard::Right);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  tc.KeyPressed(sf::Keyboard::Down);


		count_line = tc.Update(one_tic);
		if (count_line >= 0) {
			tc.setFigureType(rand() % 7);
			tc.setPosition( 5, 0 );

			score += count_line;
			std::cout << score << std::endl;
		}



		//Анимации
		MainFigure.UpdateAnimation( one_tic );


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

