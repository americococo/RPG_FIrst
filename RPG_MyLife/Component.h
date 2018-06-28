#pragma once
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

	virtual void Init(int posX,int posY);
	virtual void Update(float deltaTime);
	virtual void render();
	virtual void DeInit();
	


protected:
	eComponentType _ObjectType;

	int _posX;
	int _posY;

	
	Sprite * _sprite;

public:
	eComponentType GetComponentType();

};

