#pragma once
#include "IdleState.h"
class MonsterIdleState :public IdleState
{
public:
	MonsterIdleState();
	~MonsterIdleState();


	void Init(MoveObject * character);

	void Update(float dletaTime);
private:
	float _IdleSkipTime;
	float _duractionTime;
};

