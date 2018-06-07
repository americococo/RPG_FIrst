#pragma once


enum eScene
{
	TITLE,
	GAME,
	RESULT,
};

class Scene
{
public:
	Scene();
	~Scene();

	virtual void Init();

	virtual void Start();

	virtual void Update(float deltaTime);
	virtual void render();

	virtual void Stop();
};


