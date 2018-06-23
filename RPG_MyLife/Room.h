#pragma once
#include <list>

class Component;
class Room
{
public:
	Room();
	~Room();


	void Init(char * RoomCode,int posx,int posy);
	void Update(float deltaTime);
	void render();

private:
	int _posX;
	int _posY;





private:
	std::list<Component*> _componentList;
	

	bool CheckPlayer();

};

