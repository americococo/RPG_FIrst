#include "AttackShape.h"

#include "MoveObject.h"


#include "GameSystem.h"

#include "Sprite.h"

#include "Room.h"
#include "Stage.h"
#include "StageManager.h"


#include "EquipItem.h"
#include "EquipItemWeapon.h"
AttackShape::AttackShape()
{
}

AttackShape::~AttackShape()
{
}

void AttackShape::Init(MoveObject * character)
{
	_character = character;
	FixedObject::Init(_character->GetPosX(),_character->GetPosY(),_character->GetMapX(),_character->GetMapY(), L"./Sprite/AttackShape/AttackShape.png", L"./Sprite/AttackShape/AttackShape.json");
	_ObjectType = eComponentType::OBJECT;

	_directionLR = 0;
	_directionUD = 0;

	switch (_character->GetDirection())
	{
	case eDirection::LEFT:
		_directionLR--;
		break;
	case eDirection::RIGHT:
		_directionLR++;
		break;
	case eDirection::UP:
		_directionUD--;
		break;
	case eDirection::DOWN:
		_directionUD++;
		break;
	}

	_attackPoint = character->GetPower();

	if (nullptr != character->GetItem() && eEquipItemType::EquipITEM_WEAPON == character->GetItem()->GetEquipType())
	{
		_attackPoint += ((EquipItemWeapon*)character->GetItem())->GetWeaponAttackpoint();
	}
}
void AttackShape::Update(float deltaTime)
{
	FixedObject::Update(deltaTime);

	_posX += (0.014*(_directionLR));
	_posY += (0.014*_directionUD);


	if (!(_posX >= 0 - _radius && _posX <= GameSystem::GetInstance()->GetWidth() + _radius
		&& _posY >= -_radius && _posY <= GameSystem::GetInstance()->GetHeight() + _radius))
	{
		Room * room = StageManager::GetInstance()->GetStage()->GetRoom(_mapX, _mapY);

		room->AddremoveList(this);
		_sprite->deInit();
		delete this;
	}
}
void AttackShape::render()
{
	FixedObject::render();
	SetPos(_posX, _posY);
}