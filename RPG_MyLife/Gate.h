#pragma once
#include "Component.h"
class Gate : public Component
{

public:
	Gate();
	~Gate();

	void Init(int posX,int posY);
	void Update(float deltaTime);
	void render();
	void DeInit();



	


};

