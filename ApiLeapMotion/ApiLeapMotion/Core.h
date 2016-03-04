#pragma once

#include "stdafx.h"
#include "UIWindow.h"
#include "UIButton.h"
#include "Controller.h"

class Core
{
private :
	//Controller *controller;
	Controller *controller;

public :
	Core();
	~Core();

	void Init();
	void Run();
	void Finish();
};

