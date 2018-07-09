#pragma once
#include "Component.h"


enum eDirectionGATE
{
	NONERoom,
	LEFTRoom,
	RIGHTRoom,
	UPRoom,
	DOWNRoom
};


class Gate : public Component
{

public:
	Gate();
	~Gate();

	void Init(float posX,float posY,int mapX,int mapY,eDirectionGATE GateDirection);
	void Update(float deltaTime);
	void render();
	void DeInit();



	

private:

	eDirectionGATE _GateDirection;


public:
	void SetGateDirection(eDirectionGATE direction);

};

