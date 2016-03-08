#pragma once

#include "Page.h"
#include "tinyxml2.h"

class PageConstructor
{
public:
	PageConstructor();
	~PageConstructor();

	Page *Constuction(std::string file);
};

