#pragma once

#include "Component.h"

class Player :public Component
{
public:
	Player();
	~Player();


	/*overRide*/void Init(int posX, int posY);
	/*overRide*/void render();

	/*overRide*/void Update(float dletaTime);


private:

};