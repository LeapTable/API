#include "stdafx.h"
#include "UIWindow.h"


UIWindow::UIWindow(std::string windowName)
	: sf::RenderWindow(sf::VideoMode(800, 600), windowName)
{
}


UIWindow::~UIWindow()
{
}

void UIWindow::Init()
{

}

void UIWindow::Add(UIObject *newObject)
{
	_objectList.push_back(newObject);
}

void UIWindow::Refresh()
{
	this->Clean();
	this->Draw();
}

void UIWindow::Draw()
{
	for (UIObject *obj : _objectList)
	{
		obj->Draw(this);
	}
	this->display();
}

void UIWindow::Clean()
{

}






