#pragma once
#include "IdleState.h"
class MonsterIdleState :public IdleState
{
public:
	MonsterIdleState();
	~MonsterIdleState();



	void Update(float dletaTime);
private:

};

