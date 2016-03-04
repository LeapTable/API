#include "stdafx.h"
#include "Controller.h"


Controller::Controller()
{
	page = new Page();
}


Controller::~Controller()
{

}

void Controller::Init()
{
	window = new sf::RenderWindow(sf::VideoMode(1000, 500), "");
}

void Controller::LoadPage()
{
	page->Init();
}

void Controller::Render()
{
	page->Draw(window);
	window->display();
}

void Controller::Event()
{
	sf::Event event;
	UIObject *obj;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		
		if ((obj = page->GetObjectOnFocus(&event)) != NULL)
			obj->OnFocus();
	}
}

bool Controller::IsWindowOpen()
{
	return window->isOpen();
}
