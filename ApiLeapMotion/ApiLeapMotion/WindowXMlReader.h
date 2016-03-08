#pragma once

#include "tinyxml2.h"
#include "Page.h"
#include "CallBackListener.h"
#include <string>
#include <sstream>

class WindowXMlReader
{
	tinyxml2::XMLDocument			_Rootdoc;
	tinyxml2::XMLDocument			_Pagedoc;
	tinyxml2::XMLDocument			_Textdoc;
	std::string						_rootPath;

public:
	WindowXMlReader(std::string rootPath);
	~WindowXMlReader();

	Page				*ReadPageDoc(std::string fileName, CallBackListener *callBackListener);

	UIButton			*GetButton(tinyxml2::XMLElement *element, CallBackListener *callBackListener);

	static bool			OpenDoc(tinyxml2::XMLDocument *doc, std::string filePath);
};

