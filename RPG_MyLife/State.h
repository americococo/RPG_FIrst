#pragma once
#include <map>
enum eDirection;
class Component;
class Sprite;
class State
{
public:
	State();
	~State();



public:

	void Init(Component * character);

	void Start();

	void render();

	void Update(float dletaTime);

	void Stop();

private:	
	Component * _character;
	std::map<eDirection,Sprite*> _spriteVector;
	

	void createSprite();
};
