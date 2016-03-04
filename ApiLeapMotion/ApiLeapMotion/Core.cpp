#include "stdafx.h"
#include "Core.h"


Core::Core()
{
	controller = new Controller();
}

Core::~Core()
{
}

void Core::Init()
{
	controller->Init();
	controller->LoadPage();
}

void Core::Run()
{
	while (controller->IsWindowOpen())
	{
		controller->Render();
		controller->Event();
	}

}

void Core::Finish()
{

}