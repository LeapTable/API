#include "stdafx.h"
#include "UIButton.h"


UIButton::UIButton(std::string Tag, int PosX, int PosY, int Height, int Width,
	int background, int foreground, int border, int Text)
	: UIObject(Tag, PosX, PosY, Height, Width)
	
{
	_background.Hexa = background;
	_foreground.Hexa = foreground;
	_border.Hexa = border;
	_text = Text;
}


UIButton::UIButton(std::string Tag, int PosX, int PosY, int Height, int Width)
	: UIObject(Tag, PosX, PosY, Height, Width)
{
	this->InitiazeCompoment();
}


UIButton::~UIButton()
{
}

void		UIButton::InitiazeCompoment()
{
	shape = new sf::RectangleShape(sf::Vector2f(_height, _width));

	shape->setFillColor(sf::Color(255, 255, 0, 255));
	shape->setOutlineColor(sf::Color(255, 255, 0, 255));

	shape->setPosition(sf::Vector2f(_posX, _posY));
}

void		UIButton::Draw(sf::RenderWindow *window){
	window->draw(*shape);
}

void		UIButton::OnClick(){
	//std::count << "OnClick on : " + _tag << std::end;
	
}

void		UIButton::OnFocus(){
	std::cout << "OnFocus : " << _tag << std::endl;
}