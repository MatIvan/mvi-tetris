#include "NumericStorage.h"



NumericStorage::NumericStorage()
{
}


NumericStorage::~NumericStorage()
{
}

void NumericStorage::LoadSprites(const std::string & filename, int width, int height)
{
	_image.loadFromFile( filename );
	_image.createMaskFromColor(sf::Color(255, 0, 0));

	for (int i = 0; i < 11; i++) {
		_textures[i].loadFromImage(_image,sf::IntRect( i*width, 0, width, height));
		_sprites[i].setTexture(_textures[i]);
	}
}

const sf::Sprite & NumericStorage::getSprite(const char *symbol, sf::Vector2f position)
{
	if (symbol[0] == ' ') {
		_sprites[0].setPosition(position);
		return _sprites[0]; //Пустой символ 
	}

	int i = std::atoi(symbol) + 1;
	_sprites[i].setPosition(position);
	return _sprites[i];
	
}
