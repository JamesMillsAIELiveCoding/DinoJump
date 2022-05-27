#pragma once

#include "IGameState.h"
#include <vector>

using std::vector;

class Button;

class MenuState : public IGameState
{
public:
	MenuState(Application* _app);

	virtual void Load();
	virtual void Update(float _dt);
	virtual void Draw();
	virtual void Unload();

private:
	vector<Button*> m_buttons;

};

