#pragma once
#include <list>

class Stage;

class StageManager
{
private:
	StageManager();
	static StageManager * _instance;
public:
	~StageManager();
	static StageManager * GetInstance();

public:
	void Init();

	void Update(float deltTime);
	void render();

private:
	Stage * _stage;
	std::list<Stage*> _stageList;
};