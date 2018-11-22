#ifndef NUMERISTORAGE_H
#define NUMERISTORAGE_H

#pragma once

#include <SFML/Graphics.hpp>

/*
	Класс NumericStorage
	Загружает и хранит картинку, текстуры и спрайты цифр
	Картинка должна сожержать 11 кусков:
		Первый пустой
		Второй 0
		Остачные цыфры от 1 до 9
*/
class NumericStorage
{
public:
	NumericStorage();
	~NumericStorage();

	//Загрузить спрайты
	void LoadSprites(const std::string &filename, int width, int height);

	//Получить спрайт по цифре
	const sf::Sprite &getSprite( int symbol, sf::Vector2f position = sf::Vector2f(0,0) );

	//Ширина символа
	int getWidth() const { return _textures[0].getSize().x; }

private:
	sf::Image	_image;			//Катринка
	sf::Texture _textures[11];	//Хранилище текстур
	sf::Sprite	_sprites[11];	//Хранилище спрайтов


};

#endif //NUMERISTORAGE_H