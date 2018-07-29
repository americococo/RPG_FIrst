#pragma once
#include "State.h"
class IdleState : public State
{
public:
	IdleState();
	~IdleState();




public:
	
	/*overRide*/	virtual	void Update(float dletaTime);

	/*overRide*/	void Stop();

private:

};
