#include "PlayState.h"

#include "Player.h"
#include "Assets.h"

#include <raylib.h>

PlayState::PlayState(Application* _app) : IGameState(_app)
{
	Texture2D playerTex = Assets::GetTexture("dino_run");
	m_player = new Player(
		Vector2 { 30, (float)_app->windowHeight - playerTex.height - 30 }, 
		Vector2 { 1, 1 }, 
		playerTex,
		this);

	isRunning = false;
}

void PlayState::Load()
{
	m_player->Load();
}

void PlayState::Update(float _dt)
{
	m_player->Update(_dt);

	if (IsKeyPressed(KEY_SPACE))
		isRunning = true;
}

void PlayState::Draw()
{
	m_player->Draw();
}

void PlayState::Unload()
{
	m_player->Unload();
}