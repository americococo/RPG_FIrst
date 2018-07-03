#pragma once

#include "MessageFrom.h"

class Sprite;


enum eComponentType
{
	PlAYER,
	ENEMY,
	GATE,
	OBJECT,
	NONE,
};


class Component
{
public:
	Component();
	~Component();

	virtual void Init(float posX,float posY);
	virtual void Update(float deltaTime);
	virtual void render();
	virtual void DeInit();
	


protected:
	eComponentType _ObjectType;

	float _posX;
	float _posY;

	
	Sprite * _sprite;



public:
	eComponentType GetComponentType();



public:
	int GetPosX() { return _posX; }
	int GetPosY() { return _posY; }


	//메세지 수신
public:
	virtual void ReciverMessage(MessageFrom msgFrom);
};

