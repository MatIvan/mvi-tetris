#include <iostream>
#include <SFML/Graphics.hpp>

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
	float delay = 0.03;
	sf::Clock clock;

	int fps=0;
	int frames=0;
	float frame_timer = 0;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		if (timer > delay) {
			//logik
			timer = 0;

			window.clear(ClearColor);
			window.draw( sp );
			window.display();

			frames++;

		}



		
		frame_timer += time;
		if (frame_timer >= 1) {
			cout << "fps " << frames << endl;
			frames = 0;
			frame_timer = 0;
		}
	}

	return 0;
}

