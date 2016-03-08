#pragma once

#include "stdafx.h"

#include "UIObjectList.h"
#include "UIButton.h"
#include "CallBackListener.h"

class Page
{
private:
	sf::RectangleShape	*background;
	UIObjectList		*_listObject;
	std::string			_tag;

public:
	Page();
	~Page();


	void Init(float x, float y, CallBackListener *callBackListener);
	void Draw(sf::RenderWindow *window);
	void OnWindowSizeChange(float x, float y);

	void	AddElement(UIObject *object);

	UIObject *GetObjectOnFocus(sf::Event *event);
	UIObject *GetObjectOnClick(sf::Event *event);

	UIObjectList	*GetObjectList();
	void SetObjectList(UIObjectList *obj);
	std::string getTag() const;
};

