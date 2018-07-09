#pragma once
#include "State.h"

enum eDirection;
class MoveState :	public State
{
public:
	MoveState();
	~MoveState();


public:

	/*overRide*/	void Start();

	/*overRide*/	void Update(float dletaTime);

	/*overRide*/	void Stop();


private:
	eDirection _direction;

	float _duractionTime;

	int posx = 0;
	int posY = 0;
};

