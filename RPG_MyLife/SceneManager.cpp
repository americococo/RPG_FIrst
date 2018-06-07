#include "SceneManager.h"

#include "Scene.h"
#include "TitleScene.h"
#include "GameScene.h"
SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}
SceneManager * SceneManager::_instance = nullptr;
SceneManager * SceneManager::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new SceneManager();
		_instance->SetUp();
	}
	return _instance;
}

void SceneManager::SetUp()
{
	{
		Scene * scene = new TitleScene();
		scene->Init();
		_sceneMap[eScene::TITLE] = scene;
	}
	{
		Scene * scene = new GameScene();
		scene->Init();
		_sceneMap[eScene::GAME] = scene;
	}

	_scene = _sceneMap[eScene::TITLE];

	_scene->Start();
}

void SceneManager::ChangeScene(eScene sceneType)
{
	if (_scene != nullptr)
		_scene->Stop();

	_scene = _sceneMap[sceneType];
	_scene->Start();
	
}

void SceneManager::Update(float deltaTime)
{
	_scene->Update(deltaTime);
}
void SceneManager::render()
{
	_scene->render();
}