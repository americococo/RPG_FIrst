#pragma once
#include "Component.h"
#include <map>


#include "GlobalType.h"




enum eState;

class State;

class MoveObject :	public Component
{
public:
	MoveObject();
	~MoveObject();



	void Init(float posX, float posY, int mapX, int mapY);
protected:
	eDirection _direction;

public:
	eDirection GetDirection() { return _direction; }
	void SetDirection(eDirection directionType) { _direction = directionType; }

	void MoveStart(int posx,int posy);

protected:
	State * _state;
	std::map<eState, State*> _StateMap;
	float _speed;
	float _moveCoolTime;

	





public:
	float GetMoveCoolTime() { return _moveCoolTime; }

public:
	void ChangeState(eState stateType);

	void ReplaceState(eState stateType, State  * changeState);


protected:

};

