#include "stdafx.h"
#include "Log.h"


Log::Log()
{
}


Log::~Log()
{
}

static void print(std::string msg)
{
	SYSTEMTIME st, lt;
	static int MessageNumber = 0;
	GetSystemTime(&st);
	GetLocalTime(&lt);

	printf("Log[&d][%02d:%02d]", MessageNumber, lt.wHour, lt.wMinute);
	std::cout << msg << std::endl;
}
