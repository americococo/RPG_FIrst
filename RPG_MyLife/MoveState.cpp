#include "MoveState.h"

#include "MoveObject.h"

MoveState::MoveState()
{
	_duractionTime = 0.0f;
}


MoveState::~MoveState()
{
}

void MoveState::Start()
{

	State::Start();

	eDirection direction = _character->GetDirection();

	posx = 0;
	posY = 0;

	switch (direction)
	{
	case LEFT:
		posx--;
		break;
	case RIGHT:
		posx++;
		break;
	case UP:
		posY--;
		break;
	case DOWN:
		posY++;
		break;
	}


}

void MoveState::Update(float deltaTime)
{
	_duractionTime += deltaTime;
	

	if (_duractionTime >= _character->GetMoveCoolTime())
	{
		_duractionTime = 0.0f;
		_character->MoveStart(posx, posY);
		_character->ChangeState(eState::ES_IDLE);
	}
}
void MoveState::Stop()
{

}