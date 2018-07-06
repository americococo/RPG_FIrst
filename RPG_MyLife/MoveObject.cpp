#include "MoveObject.h"
#include "GlobalType.h"

#include "State.h"
MoveObject::MoveObject()
{
	_direction = eDirection::NONEDIRCTION;
	_state = nullptr;
}


MoveObject::~MoveObject()
{
}

void MoveObject::ChangeState(eState stateType)
{
	if (_state != nullptr)
		_state->Stop();

	_state = _StateMap[stateType];
	_state->Start();
}

void MoveObject::ReplaceState(eState stateType,State * changeState)
{
	std::map<eState, State*>::iterator itr = _StateMap.find(stateType);
	if (itr != _StateMap.end())
	{
		delete _StateMap[stateType];
		_StateMap.erase(stateType);
	}

	State * state = changeState;
	state->Init(this);
	_StateMap[stateType] = changeState;
}
