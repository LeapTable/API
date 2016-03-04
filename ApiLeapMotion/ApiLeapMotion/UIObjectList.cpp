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
		obj->Draw(windows);
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
