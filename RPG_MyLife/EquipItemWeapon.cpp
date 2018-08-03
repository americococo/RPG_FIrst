#include "EquipItemWeapon.h"



void EquipItemWeapon::Init(float posX, float posY, int mapX, int mapY, LPCWSTR textureFileName, LPCWSTR scriptFileName,int durability)
{
	EquipItem::Init(posX, posY, mapX, mapY, textureFileName, scriptFileName);

	_durability = durability;

	 _equipItemType = eEquipItemType::EquipITEM_WEAPON;

	_incressAtk=rand() % 100 + 20;
}
void EquipItemWeapon::ReduceDurability(int reducepoint)
{
	_durability = reducepoint;
}