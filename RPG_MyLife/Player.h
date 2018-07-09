#pragma once

#include "MoveObject.h"


enum eDirection;
class Player :public MoveObject
{
public:
	Player();
	~Player();


	/*overRide*/void Init(float posX, float posY,int mapX,int mapY);
	/*overRide*/void render();

	/*overRide*/void Update(float dletaTime);

};