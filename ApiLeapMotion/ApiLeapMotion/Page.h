#pragma once

#include "stdafx.h"

#include "UIObjectList.h"
#include "UIButton.h"

class Page
{
private:
	UIObjectList *_listObject;
	std::string			_tag;

public:
	Page(std::string filePath = "");
	~Page();


	void Init();
	void Draw(sf::RenderWindow *window);
	UIObject *GetObjectOnFocus(sf::Event *event);

	std::string getTag() const;
};

