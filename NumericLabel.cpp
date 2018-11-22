#include "NumericLabel.h"



NumericLabel::NumericLabel()
{
	_size = 8;
}


NumericLabel::~NumericLabel()
{
}

void NumericLabel::setValue(int value)
{
	std::string str = std::to_string(value);
	if ((str.size() > _size) || (str.size() < 1)) {
		_symbols.insert(_symbols.end(), std::size_t(_size), 0);
		return;
	}

	int symbol;
	_symbols.clear();

	_symbols.insert(_symbols.end() , std::size_t(_size - str.size()), 0);

	for (int i = 0; i < str.size(); i++) {
		symbol = int(str.at(i) - 47);
		if (symbol < 1 || symbol>10) {
			_symbols.push_back(0);
		}else {
			_symbols.push_back(symbol);
		}
	}
}

void NumericLabel::Draw( sf::RenderWindow * window)
{
	sf::Vector2f p;
	int h = _storage->getWidth();

	float dp=0;
	for (auto& i : _symbols) {
		p = _position + sf::Vector2f(dp*h, 0);
		window->draw( _storage->getSprite( i, p) );
		dp++;
	}
}
