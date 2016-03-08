#pragma once

#include "stdafx.h"
#include "Page.h"
#include "CallBackListener.h"
#include "WindowXMlReader.h"

class Controller
{
private:
	Page	*page;

	sf::RenderWindow *window;
	WindowXMlReader	 *reader;
	CallBackListener *callBackListener;

public:
	Controller();
	~Controller();

	void Init();

	void LoadPage();
	void Render();
	void Event();

	bool IsWindowOpen();
	
};

