#pragma once
#include "Component.h"

enum eDirection;

class State;

class MoveObject :	public Component
{
public:
	MoveObject();
	~MoveObject();

protected:
	eDirection _direction;


protected:
	State * _state;

};

