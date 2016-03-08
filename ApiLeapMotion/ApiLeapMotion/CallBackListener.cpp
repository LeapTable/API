#include "stdafx.h"
#include "CallBackListener.h"
#include "CallBack.h"

CallBackListener::CallBackListener()
{

}


CallBackListener::~CallBackListener()
{
}

void CallBackListener::Init()
{
	Add("Test", OnClickTest);
	Add("OnButtonClick_1", OnButtonClick_1);
}

void CallBackListener::Add(std::string tag, std::function<void(void*, void*)> function)
{
	_listener[tag] = function;
}

std::function<void(void*, void*)> CallBackListener::GetFunctionByTag(std::string tag)
{
	return _listener[tag];
}