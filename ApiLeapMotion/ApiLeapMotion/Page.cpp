#include "stdafx.h"
#include "Page.h"


Page::Page(std::string filePath)
{
	_listObject = new UIObjectList();
}

Page::~Page()
{
}

void Page::Init()
{
	_listObject->Add(new UIButton("buttonTest", 20, 20, 300, 150));
	_listObject->Add(new UIButton("buttonTest2", 20, 300, 300, 150));
}

void Page::Draw(sf::RenderWindow *window)
{
	_listObject->Draw(window);
}

std::string Page::getTag() const
{
	return _tag;
}

UIObject *Page::GetObjectOnFocus(sf::Event *event)
{
	return _listObject->GetObjectOnFocus(event);
}