#pragma once

#include "IGameState.h"

class Player;

class PlayState : public IGameState
{
public:
	PlayState(Application* _app);

	virtual void Load();
	virtual void Update(float _dt);
	virtual void Draw();
	virtual void Unload();

	bool isRunning;

private:
	Player* m_player;

};

