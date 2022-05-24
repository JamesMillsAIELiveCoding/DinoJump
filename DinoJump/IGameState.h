#pragma once

#include "Application.h"

class IGameState
{
public:
	IGameState(Application* _app) { app = _app; }
	virtual void Load() = 0;
	virtual void Update(float _dt) = 0;
	virtual void Draw() = 0;
	virtual void Unload() = 0;

	Application* app;

};