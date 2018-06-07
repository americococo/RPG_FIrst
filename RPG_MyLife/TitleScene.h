#pragma once
#include "Scene.h"

class Sprite;
class TitleScene :public Scene
{
public:
	TitleScene();
	~TitleScene();

	/*over Ride*/void Update(float deltaTime);
	/*over Ride*/void render();


	/*over Ride*/void Init();

	/*over Ride*/void Start();

	/*over Ride*/void Stop();


private:
	Sprite * _sprite;
};

