#pragma once


#include <string>
class Component;


struct MessageFrom
{
	Component * sender;
	Component * reciver;



	std::wstring message;
};
