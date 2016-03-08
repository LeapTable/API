#include "stdafx.h"
#include "Controller.h"
#include "CallBack.h"

Controller::Controller()
{
	reader = new WindowXMlReader("E:\\Project\\GitHub\\LeapTable\\API\\WindowTest\\");
	callBackListener = new CallBackListener();
}


Controller::~Controller()
{

}

void Controller::Init()
{
	window = new sf::RenderWindow(sf::VideoMode(1000, 500), "");
	callBackListener->Init();
}

void Controller::LoadPage()
{
	page = reader->ReadPageDoc("PageOne.xml", callBackListener);
	page->Init(static_cast<float> (window->getSize().x), static_cast<float> (window->getSize().y), callBackListener);
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
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::Resized:
			page->OnWindowSizeChange(static_cast<float> (window->getSize().x), static_cast<float> (window->getSize().y));
			break;
		case sf::Event::MouseMoved:
			if ((obj = page->GetObjectOnFocus(&event)) != NULL)
				obj->OnFocus(window);
		case sf::Event::MouseButtonPressed:
			page->GetObjectOnClick(&event);
		case sf::Event::MouseButtonReleased:
			if ((obj = page->GetObjectOnClick(&event)) != NULL)
				obj->OnClick();
		default:
			break;
		}
	}
}

bool Controller::IsWindowOpen()
{
	return window->isOpen();
}
