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

	float one_tic = 0;	//Время потраченное на одну обработку всего
	float timer = 0;	//Время с момента последней обработки логики
	float delay = (float)0.1;	//Через сколько миллисекунд обрабатыватьлогику
	sf::Clock clock;


	//Фигура, которой управляет игрок
	FigureView MainFigure( sf::Vector2f(0,0), 16);
	MainFigure.setFigure( rand() % 7 );

	//Игровое поле
	BaseField Field;

	float FigureSpeed = 10;
	float Graviti = 1;
	int score = 0;
	int count_line = 0;

	while (window.isOpen())
	{
		one_tic = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += one_tic;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event:: Closed)
				window.close();

			//Повернуть фигуру можно только отпустив пробел и снова нажав.
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Space)
					MainFigure.turn();
			}
		}

		//Управление
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  
			MainFigure.moveY(  30 * one_tic);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
			MainFigure.moveX( -FigureSpeed * one_tic );

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
			MainFigure.moveX(  FigureSpeed * one_tic );



		//Гравитация
		MainFigure.moveY( Graviti * one_tic);


		//Ограничения на перемещения
		//if (MainFigure.position().x < 0)  MainFigure.setPositionX( (float)0  );
		//if (MainFigure.position().x > 12) MainFigure.setPositionX( (float)12 );
		//if (MainFigure.position().y > 24) { MainFigure.moveY(-24); MainFigure.setFigure(rand() % 7); }
		count_line = Field.Check(MainFigure);
		if (count_line >= 0) {
			MainFigure.setPosition(sf::Vector2f(5, 0));
			MainFigure.setFigure(rand() % 7);
			score += count_line;
			std::cout << score << std::endl;
		}

		//Обновление мира
		if (timer > delay) timer = 0;
		MainFigure.Update( delay - timer );



		window.clear(ClearColor);
		//Рисуем спрайты фигуры
		for (int n = 0; n < 4; n++) {
			sp.setPosition( MainFigure.screenPos(n) );
			window.draw(sp);
		}

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

