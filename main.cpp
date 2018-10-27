#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>


#include "FigureView.h"

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
	float delay = 0.1;	//Через сколько миллисекунд обрабатыватьлогику
	sf::Clock clock;


	//Точки на фигуре задаются относительно центра поворота.
	FigureView MainFigure( sf::Vector2f(0,0), 16);
	MainFigure[0] = sf::Vector2f( 0, -1);
	MainFigure[1] = sf::Vector2f(-1,  0);	//  #
	MainFigure[2] = sf::Vector2f( 0,  0);   // ###
	MainFigure[3] = sf::Vector2f( 1,  0);

	float FigureSpeed = 30;
	float Graviti = 5;

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  
			MainFigure.moveY(  30 * one_tic);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
			MainFigure.moveX( -FigureSpeed * one_tic );

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
			MainFigure.moveX(  FigureSpeed * one_tic );



		MainFigure.moveY( Graviti * one_tic);
		if (MainFigure.position().y > 24) MainFigure.moveY(-24);



		if (timer > delay) timer = 0;
		MainFigure.Update( delay - timer );

		window.clear(ClearColor);
		for (int n = 0; n < 4; n++) {
			sp.setPosition( MainFigure.screenPos(n) );
			window.draw(sp);
		}
		window.display();


	}

	return 0;
}

