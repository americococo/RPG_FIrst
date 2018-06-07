#pragma once
#include <map>

#include "Scene.h"

class SceneManager
{
private:
	SceneManager();
	static SceneManager  * _instance;
public:
	~SceneManager();
	static SceneManager * GetInstance();
	

private:
	void SetUp();
	Scene * _scene;
	std::map<eScene,Scene*> _sceneMap;

public:
	void Update(float deltaTime);
	void render();



	void ChangeScene(eScene sceneType);
};
