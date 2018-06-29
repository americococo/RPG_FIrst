#pragma once
#include "Component.h"

enum eDirection
{
	NONE,
	LEFT,
	RIGHT,
	UP,
	DOWN
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

