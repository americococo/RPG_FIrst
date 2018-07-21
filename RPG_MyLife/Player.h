#pragma once

#include "MoveObject.h"


enum eDirection;
class Player :public MoveObject
{
public:
	Player();
	~Player();


	/*overRide*/void Init(float posX, float posY, int mapX, int mapY, int hp, float power);
	/*overRide*/void render();

	/*overRide*/void Update(float dletaTime);

};