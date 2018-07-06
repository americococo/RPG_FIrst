#pragma once
#include "Component.h"
#include <map>



enum eDirection;


enum eState;

class State;

class MoveObject :	public Component
{
public:
	MoveObject();
	~MoveObject();

protected:
	eDirection _direction;

public:
	eDirection GetDirection() { return _direction; }
	void SetDirection(eDirection directionType) { _direction = directionType; }

protected:
	State * _state;
	std::map<eState, State*> _StateMap;


public:
	void ChangeState(eState stateType);

	void ReplaceState(eState stateType, State  * changeState);
};

