#include "stdafx.h"
#include "UIObjectList.h"


UIObjectList::UIObjectList()
{
}


UIObjectList::~UIObjectList()
{
}


void UIObjectList::Add(UIObject *newObject)
{
	_objectList.push_back(newObject);
}

void UIObjectList::Draw(sf::RenderWindow *windows)
{
	for (UIObject *obj : _objectList)
	{
		obj->Reset();
		obj->Draw(windows);
	}
}

void	UIObjectList::OnWindowsSizeChange(float x, float y)
{
	for (UIObject *obj : _objectList)
	{
		obj->OnWindowsSizeChange(x, y);
	}
}

UIObject *UIObjectList::GetObjectOnFocus(sf::Event *event)
{
	for (UIObject *obj : _objectList)
	{
		if (obj->OnFocus(event))
			return obj;
	}
	return NULL;
}


UIObject *UIObjectList::GetObjectOnClick(sf::Event *event)
{
	for (UIObject *obj : _objectList)
	{
		if (obj->OnClick(event))
			return obj;
	}
	return NULL;
}
