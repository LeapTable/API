#include "stdafx.h"
#include "PageConstructor.h"


PageConstructor::PageConstructor()
{
}


PageConstructor::~PageConstructor()
{
}
 
Page *Constuction(std::string filePath)
{
	return new Page();
}
