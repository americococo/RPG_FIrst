#pragma once
#include "State.h"
class IdleState : public State
{
public:
	IdleState();
	~IdleState();




public:
	
	/*overRide*/	void Update(float dletaTime);

	/*overRide*/	void Stop();

private:

};
