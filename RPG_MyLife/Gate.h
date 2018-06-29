#pragma once
#include "Component.h"
#include "MessageFrom.h"

enum eDirection
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

	void Init(int posX,int posY,eDirection GateDirection);
	void Update(float deltaTime);
	void render();
	void DeInit();



	

private:

	eDirection _GateDirection;



public:
	void ReciverMessage(MessageFrom msgFrom);
};

