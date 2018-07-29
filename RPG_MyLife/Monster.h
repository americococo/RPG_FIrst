#pragma once

#include "MoveObject.h"

class Monster :public MoveObject
{
public:
	Monster();
	~Monster();


	/*overRide*/void Init(float posX, float posY, int mapX, int mapY, int hp, float power);
	/*overRide*/void render();

	/*overRide*/void Update(float dletaTime);

};