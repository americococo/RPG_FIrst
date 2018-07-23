#pragma once

#include "EquipItem.h" 
class EquipItemWeapon : public EquipItem
{

public:
	void Init(float posX, float posY, int mapX, int mapY, LPCWSTR textureFileName, LPCWSTR scriptFileName,int durability);

private:
	int _durability;

	int _incressAtk;

public:
	int GetDurability() { return _durability; }
	int GetWeaponAttackpoint() { return _incressAtk; }
	

public:
	void ReduceDurability(int reducepoint);
};
