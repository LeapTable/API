#include "stdafx.h"
#include "WindowXMlReader.h"

int GetIntFromHexaString(std::string str)
{
	std::stringstream ss;
	
	unsigned int i;
	
	ss << std::hex << str.c_str();
	ss >> i;
	std::cout << i << std::endl;
	return i;
}


WindowXMlReader::WindowXMlReader(std::string rootPath)
	: _rootPath(rootPath)
{
}


WindowXMlReader::~WindowXMlReader()
{
}

Page				*WindowXMlReader::ReadPageDoc(std::string fileName, CallBackListener *callBackListener){
	Page *ret = new Page();
	tinyxml2::XMLElement *elementRoot;

	fileName = _rootPath + "Pages\\" + fileName;
	std::cout << fileName << std::endl;
	if (!OpenDoc(&_Pagedoc, fileName))
		return NULL;
	elementRoot = _Pagedoc.FirstChildElement("Page");

	for (tinyxml2::XMLElement *element = elementRoot->FirstChildElement("Object");
		element != NULL;
		element = element->NextSiblingElement())
	{
		if (std::string(element->Attribute("Type")) == "Button")
			ret->AddElement(this->GetButton(element, callBackListener));

	}
	return ret;
}

UIButton		*WindowXMlReader::GetButton(tinyxml2::XMLElement *buttonInfoXMl, CallBackListener *callBackListener)
{
	UIButton *ret = UIButton::NewButton(buttonInfoXMl->Attribute("Tag"),
		atof(buttonInfoXMl->Attribute("Posx")),
		atof(buttonInfoXMl->Attribute("Posy")),
		atof(buttonInfoXMl->Attribute("Height")),
		atof(buttonInfoXMl->Attribute("Width")),
		GetIntFromHexaString(std::string(buttonInfoXMl->Attribute("Background"))),
		GetIntFromHexaString(std::string(buttonInfoXMl->Attribute("Foreground"))),
		GetIntFromHexaString(std::string(buttonInfoXMl->Attribute("Border"))),
		buttonInfoXMl->Attribute("ContentText"),
		callBackListener->GetFunctionByTag(buttonInfoXMl->Attribute("OnClick")));
	return ret;
}

bool  WindowXMlReader::OpenDoc(tinyxml2::XMLDocument *doc, std::string filePath)
{
	if (doc->LoadFile(filePath.c_str()))
	{
		doc->PrintError();
		return false;
	}
	return true;
}

