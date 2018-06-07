#include "StageManager.h"
#include "Stage.h"
#include <list>
#include <string>
StageManager * StageManager::_instance = nullptr;

StageManager * StageManager::GetInstance()
{
	if (_instance == nullptr)
		_instance = new StageManager();

	return _instance;
}
StageManager::StageManager()
{
}


StageManager::~StageManager()
{
	
}
void StageManager::Init()
{
	{

		Stage * stage = new Stage(L"./RoomData/RoomData.csv");
		stage->Init();
		_stageList.push_back(stage);
	}



	_stage = _stageList.front();
	

}
void StageManager::Update(float deltaTime)
{
	if (_stage->checkingClearStage()&&_stageList.back()!=_stage)
	{
		_stageList.pop_front();
		delete _stage;
		_stage = _stageList.front();
		
	}

	_stage->Update(deltaTime);

}

void StageManager::render()
{
	_stage->render();
}

