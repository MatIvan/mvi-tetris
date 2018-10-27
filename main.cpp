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

	float one_tic = 0;	//Время потраченное на одну обработку всего
	float timer = 0;	//Время с момента последней обработки логики
	float delay = 0.1;	//Через сколько миллисекунд обрабатыватьлогику
	sf::Clock clock;


	//Точки на фигуре задаются относительно центра поворота.
	Figure MainFigure;
	MainFigure[0].set( 0, -1);
	MainFigure[1].set(-1,  0);	//  #
	MainFigure[2].set( 0,  0);  // ###
	MainFigure[3].set( 1,  0);

	float FigureSpeed = 10.0;
	float Graviti = 1;

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

			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Space)
					MainFigure.turn();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  MainFigure.moveY(  30 * one_tic);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  MainFigure.moveX( -FigureSpeed * one_tic );
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) MainFigure.moveX(  FigureSpeed * one_tic );

		MainFigure.moveY( Graviti * one_tic );


		if (timer > delay) {

			if (MainFigure.position().y > 10) MainFigure.moveY(-10);


			timer = 0;
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

