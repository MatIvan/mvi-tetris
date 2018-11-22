#ifndef NUMERISTORAGE_H
#define NUMERISTORAGE_H

#pragma once

#include <SFML/Graphics.hpp>

/*
	����� NumericStorage
	��������� � ������ ��������, �������� � ������� ����
	�������� ������ ��������� 11 ������:
		������ ������
		������ 0
		�������� ����� �� 1 �� 9
*/
class NumericStorage
{
public:
	NumericStorage();
	~NumericStorage();

	//��������� �������
	void LoadSprites(const std::string &filename, int width, int height);

	//�������� ������ �� �����
	const sf::Sprite &getSprite( int symbol, sf::Vector2f position = sf::Vector2f(0,0) );

	//������ �������
	int getWidth() const { return _textures[0].getSize().x; }

private:
	sf::Image	_image;			//��������
	sf::Texture _textures[11];	//��������� �������
	sf::Sprite	_sprites[11];	//��������� ��������


};

#endif //NUMERISTORAGE_H