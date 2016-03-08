#include "stdafx.h"
#include "UIButton.h"

UIButton::UIButton(std::string Tag, float PosX, float PosY, float Height, float Width,
	int background, int foreground, int border, std::string Text, std::function<void(void*, void*)> onClickCallBack)
	: UIButton(Tag, PosX, PosY, Height, Width, background, foreground, border, Text)

{
	_onClickCallBack = onClickCallBack;
}

UIButton::UIButton(std::string Tag, float PosX, float PosY, float Height, float Width,
	int background, int foreground, int border, std::string Text)
	: UIButton(Tag, PosX, PosY, Height, Width)

{
	_background.c = background;
	_background.argb.a = 255;
	_foreground.c = foreground;
	_foreground.argb.a = 255;
	_border.c = border;
	_border.argb.a = 255;
	_text = Text;
}


UIButton::UIButton(std::string Tag, float PosX, float PosY, float Height, float Width)
	: UIObject(Tag, PosX, PosY, Height, Width)
{
	this->InitiazeCompoment();
}


UIButton::~UIButton()
{
}

void		UIButton::InitiazeCompoment()
{
	shape = new sf::RectangleShape();
	shape->setSize(sf::Vector2f((float) _height, (float) _width));
	shape->setPosition(sf::Vector2f((float) _posX, (float) _posY));
	this->Reset();
}

void		UIButton::Draw(sf::RenderWindow *window){
	if (_UIPropChanged)
		OnWindowsSizeChange(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y));
	window->draw(*shape);
	_UIPropChanged = false;
}



void		UIButton::Reset(){
	if (_isFocus)
	{
		shape->setOutlineColor(sf::Color(_background.argb.r, _background.argb.g, _background.argb.b, _background.argb.a));
		shape->setFillColor(sf::Color(_foreground.argb.r, _foreground.argb.g, _foreground.argb.b, _foreground.argb.a));
		if (_isClick)
		{
			shape->setOutlineColor(sf::Color(_background.argb.r, _background.argb.g, _background.argb.b, _background.argb.a));
			shape->setFillColor(sf::Color(_border.argb.r, _border.argb.g, _border.argb.b, _border.argb.a));
			return;
		}
	}
	else
	{
		shape->setFillColor(sf::Color(_background.argb.r, _background.argb.g, _background.argb.b, _background.argb.a));
		shape->setOutlineColor(sf::Color(_foreground.argb.r, _foreground.argb.g, _foreground.argb.b, _foreground.argb.a));
	}
}

bool		UIButton::OnClick(sf::Event *event){
	_isClick = false;
	if (event->mouseButton.x > shape->getPosition().x && event->mouseButton.x <  shape->getPosition().x + shape->getSize().x)
	{
		if (event->mouseButton.y > shape->getPosition().y && event->mouseButton.y <  shape->getPosition().y + shape->getSize().y)
			_isClick = true;
	}
	return _isClick;
}

bool		UIButton::OnFocus(sf::Event *event){
	_isFocus = false;
	if (event->mouseMove.x > shape->getPosition().x && event->mouseMove.x <  shape->getPosition().x + shape->getSize().x)
	{
		if (event->mouseMove.y > shape->getPosition().y && event->mouseMove.y < shape->getPosition().y + shape->getSize().y)
			_isFocus = true;
	}
	return _isFocus;
}


void		UIButton::OnFocus(sf::RenderWindow *window){
}

void		UIButton::OnWindowsSizeChange(float x, float y)
{
	shape->setSize(sf::Vector2f(x * (_height / 100), y *(_width / 100)));
	shape->setPosition(sf::Vector2f(x * (_posX / 100), y *(_posY / 100)));
}

void		UIButton::OnClick(void *arg){
	_onClickCallBack(this, arg);
}


UIButton	*UIButton::NewButton(std::string Tag, float  PosX, float PosY, float Height, float Width,
	int background, int foreground, int border, std::string Text,
	std::function<void(void*, void*)> onClickCallBack)
{
	return new UIButton(Tag, PosX, PosY, Height, Width, background, foreground, border, Text, onClickCallBack);
}