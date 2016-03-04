#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <Windows.h>
#include <cstdlib>

class UIObject
{
protected:

	int					_posX;
	int					_posY;

	int					_height;
	int					_width;
	std::string		_tag;


public:
	UIObject();
	UIObject(std::string Tag, int PosX, int PosY, int Height, int width);
	~UIObject();

	virtual void OnClick() = 0;
	virtual void OnFocus() = 0;

	bool		OnClick(sf::Event *evevt);
	bool		OnFocus(sf::Event *event);

	int getPosX() const;
	int getPosY() const;
	int getHeight() const;
	int getWidth() const;

	virtual void Draw(sf::RenderWindow *windows) = 0;
};

