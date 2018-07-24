#pragma once

#include "MessageFrom.h"

class Sprite;


enum eComponentType
{
	PlAYER,
	ENEMY,
	GATE,
	OBJECT,
	ITEM,
	NONE,
};


class Component
{
public:
	Component();
	~Component();

	virtual void Init(float posX,float posY,int mapX,int mapY);
	virtual void Update(float deltaTime);
	virtual void render();
	virtual void DeInit();
	


protected:
	eComponentType _ObjectType;

	float _posX;
	float _posY;

	




public:
	eComponentType GetComponentType();



public:
	float GetPosX() { return _posX; }
	float GetPosY() { return _posY; }

	virtual void SetPos(float posX, float posY);



protected:
	int _mapX;
	int _mapY;




	float _radius;

public:
	int GetMapX() { return _mapX; }
	int GetMapY() { return _mapY; }

	float GetRadius() { return _radius; }
	void SetRadius(float radius) { _radius = radius; }


	void SetMapPosition(int mapX, int maY) { _mapX = mapX; _mapY = maY; }

	//메세지 수신
public:
	virtual void ReciverMessage(MessageFrom msgFrom);
};

