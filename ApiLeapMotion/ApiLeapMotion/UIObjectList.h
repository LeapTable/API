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
	void OnWindowsSizeChange(float x, float y);

	UIObject *GetObjectOnFocus(sf::Event *event);
	UIObject *GetObjectOnClick(sf::Event *event);

	
};

