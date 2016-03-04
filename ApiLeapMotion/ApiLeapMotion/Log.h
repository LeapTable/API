#pragma once

#include <windows.h>
#include <iostream>
#include <string>

#define LOG (info) Log.Print(info)

class Log
{
public:
	Log();
	~Log();

	static void		Print(std::string text);
	
};

