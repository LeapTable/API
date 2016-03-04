#pragma once

#include "UIObject.h"
#include "Color.h"

class UIButton : public UIObject
{
private :
	
	Color		_background;
	Color		_foreground;
	Color		_border;

	std::string _text;

	sf::RectangleShape *shape;

public:

	UIButton(std::string Tag, int PosX, int PosY, int Height, int Width,
		int background, int foreground, int border, int Text);
	UIButton(std::string Tag, int PosX, int PosY, int Height, int Width);
	~UIButton();

	void		InitiazeCompoment();

	void		OnFocus();
	void		OnClick();
	void		Draw(sf::RenderWindow *window);
};

