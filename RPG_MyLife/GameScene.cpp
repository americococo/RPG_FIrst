#include "GameScene.h"

#include <list>
#include <string>

#include "StageManager.h"
GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}
void GameScene::Init()
{
	StageManager::GetInstance()->Init();
	
}
void GameScene::Update(float deltaTime)
{
	StageManager::GetInstance()->Update(deltaTime);
}

void GameScene::render()
{
	StageManager::GetInstance()->render();
}
void GameScene::Start()
{
	
}

void GameScene::Stop()
{

}