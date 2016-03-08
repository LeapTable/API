#pragma once

#include <map>
#include <functional>
#include <string>

class CallBackListener
{
private:
	std::map < std::string, std::function<void(void*, void*)>> _listener;

public:
	CallBackListener();
	~CallBackListener();

	void Init();
	
	void Add(std::string, std::function<void(void*, void*)>);

	std::function<void(void*, void*)> GetFunctionByTag(std::string);
};

