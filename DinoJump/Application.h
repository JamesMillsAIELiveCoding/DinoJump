#pragma once

class GameStateManager;

class Application
{
public:
	Application();
	~Application();

	void Load();
	void Run();
	void Update(float _dt);
	void Draw();
	void Unload();

	int windowWidth;
	int windowHeight;

private:
	void SetupStates();
	GameStateManager* m_gameStateManager;

};

