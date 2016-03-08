// ApiLeapMotion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "Core.h"

int main()
{
	Core core;
	core.Init();
	core.Run();
	core.Finish();
	return 0;
}
