#pragma once
class Room
{
public:
	Room();
	~Room();


	void Init(int RoomCode,int posx,int posy);
	void Update(float deltaTime);
	void render();

public:
	int _posX;
	int _posY;
	int _roomCode;
};

