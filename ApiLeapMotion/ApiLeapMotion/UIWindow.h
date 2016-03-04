#pragma once

#include <SFML\Window.hpp>
#include <list>

#include "UIObject.h"

class UIWindow : public sf::RenderWindow
{
private:
	std::list<UIObject *> _objectList;


public:
	UIWindow(std::string windowName);
	~UIWindow();

	void Init();
	void Add(UIObject *newObject);
	void Refresh();

	bool IsOpen();

private:
	void Clean();
	void Draw();

};

