#pragma once

#include <SFML\Window.hpp>
#include <list>

#include "UIObject.h"

class UIObjectList
{
private:
	std::list<UIObject *> _objectList;

public:
	UIObjectList();
	~UIObjectList();

	void Add(UIObject *newObject);
	void Draw(sf::RenderWindow *windows);
	
	UIObject *GetObjectOnFocus(sf::Event *event);

};

