#include "stdafx.h"
#include "UIObject.h"


UIObject::UIObject()
	: _posX(0)
	, _posY(0)
	, _height(0)
	, _width(0)
{

}
UIObject::UIObject(std::string Tag, int PosX, int PosY, int Height, int Weight)
	: _tag(Tag)
	, _posX(PosX)
	, _posY(PosY)
	, _height(Height)
	, _width(Weight)
{
}



UIObject::~UIObject()
{
}


bool	UIObject::OnFocus(sf::Event *event)
{
	if (event->mouseMove.x > _posX && event->mouseMove.x < _posX + _width)
	{
		if (event->mouseMove.y > _posY && event->mouseMove.y < _posY + _height)
			return true;
	}
	return false;
}

int UIObject::getHeight() const {
	return _height;
}

int UIObject::getWidth() const {
	return _width;
}

int UIObject::getPosX() const {
	return _posX;
}

int UIObject::getPosY() const {
	return _posY;
}
