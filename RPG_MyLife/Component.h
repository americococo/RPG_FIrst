#pragma once
class Component
{
public:
	Component();
	~Component();

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void render();
	virtual void DeInit();
	
};

