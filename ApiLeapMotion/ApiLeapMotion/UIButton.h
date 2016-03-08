#pragma once

#include "UIObject.h"
#include "Color.h"
#include <functional>

class UIButton : public UIObject
{
private:

	Color				_background;
	Color				_foreground;
	Color				_border;

	std::string			_text;

	sf::RectangleShape *shape;
	std::function<void(void*, void*)> _onClickCallBack;
	std::function<void(void*, void*)> _onFocusCallBack;


public:

	UIButton(std::string Tag, float PosX, float PosY, float Height, float Width,
		int background, int foreground, int border, std::string Text,
		std::function<void(void*, void*)> onClickCallBack);

	UIButton(std::string Tag, float PosX, float PosY, float Height, float Width,
		int background, int foreground, int border, std::string Text);
	UIButton(std::string Tag, float PosX, float PosY, float Height, float Width);
	~UIButton();

	void		InitiazeCompoment();

	void		OnFocus(sf::RenderWindow *window);
	void		OnClick(void *arg = NULL);
	void		OnWindowsSizeChange(float x, float y);
	bool		OnClick(sf::Event *event);
	bool		OnFocus(sf::Event *event);

	void		Draw(sf::RenderWindow *window);
	void		Reset();

	static		UIButton *NewButton(std::string Tag, float PosX, float PosY, float Height, float Width,
		int background, int foreground, int border, std::string Text,
		std::function<void(void*, void*)> onClickCallBack);

};

