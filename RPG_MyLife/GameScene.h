#pragma once
#include "Scene.h"
class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	/*override*/ void Init();

	/*override*/ void Start();

	/*override*/ void Update(float deltaTime);
	/*override*/ void render();

	/*override*/ void Stop();
};

