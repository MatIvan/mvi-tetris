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

const sf::Sprite & NumericStorage::getSprite(int symbol, sf::Vector2f position)
{
	_sprites[symbol].setPosition(position);
	return _sprites[symbol];
}
