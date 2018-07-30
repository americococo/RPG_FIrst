#pragma once
#include <map>


enum eState
{
	ES_NONE,
	ES_IDLE,
	ES_MOVE,
	ES_ATTACK,
	ES_DEFEND,
};


enum eDirection;
class MoveObject;
class Sprite;
class State
{
public:
	State();
	~State();



public:

	virtual void Init(MoveObject * character);

	virtual void Start();

	virtual	void render();

	virtual	void Update(float dletaTime);

	virtual	void Stop();

protected:
	MoveObject * _character;
	std::map<eDirection, Sprite*> _spriteVector;


	eState _nextState;
	

	void createSprite();
};
