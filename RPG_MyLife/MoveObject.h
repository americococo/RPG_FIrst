#pragma once
#include "Component.h"
#include <map>


#include "GlobalType.h"



#include <queue>




enum eState;

class State;




class EquipItem;
class MoveObject :	public Component
{
public:
	MoveObject();
	~MoveObject();



	virtual void Init(float posX, float posY, int mapX, int mapY,int hp,float _power);


	void render();
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

	

	void SetPos(float posX, float posY);



public:
	float GetMoveCoolTime() { return _moveCoolTime; }

public:
	void ChangeState(eState stateType);

	void ReplaceState(eState stateType, State  * changeState);


protected:

	int _hp;
	float _power;

public:
	void AffectHp(int affecthealth) { _hp += affecthealth; }
	void AffectPower(float affecthealth) { _power += affecthealth; }

	

protected:
	std::queue < EquipItem*> _equipItem;

public:
	void MountEquipItem(EquipItem * item);


protected:
	float _attackCoolTime;
	float _attackduraction;

public:
	float GetAttackDuraction() { return _attackduraction; }
	void SetAttackDuraction(float duraction) { _attackduraction += duraction; }
	void ReSetAttackDuraction() { _attackduraction=0; }

	float GetAttackCoolTime() { return _attackCoolTime; }

	float GetPower() { return _power; }

	EquipItem * GetItem();

public:
	void ReduceDurability(int reducePoint);


	
};

