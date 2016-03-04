#pragma once

#include "stdafx.h"
#include "Page.h"


class Controller
{
private:
	Page	*page;
	sf::RenderWindow *window;

public:
	Controller();
	~Controller();

	void Init();

	void LoadPage();
	void Render();
	void Event();

	bool IsWindowOpen();
	
};

