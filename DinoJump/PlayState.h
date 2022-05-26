#pragma once

#include "IGameState.h"
#include <vector>

using std::vector;

class Player;
class Ground;
struct Vector2;

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
	Ground* CreateGround(Vector2 _pos);

	Player* m_player;
	vector<Ground*> m_grounds;

};

