#pragma once
#include "FixedObject.h"

class MoveObject;

class AttackShape : public FixedObject
{
public:
	AttackShape();
	~AttackShape();

	void Init(MoveObject *  character);

	void Update(float deltaTime);

	void render();
private:
	MoveObject * _character;

	int _directionLR;
	int _directionUD;




	float _attackPoint;
};

