#include "PlayState.h"

#include "Player.h"
#include "Assets.h"
#include "Ground.h"

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
	Texture2D groundTex = Assets::GetTexture("ground");
	m_grounds.push_back(CreateGround(Vector2{ 0, (float)app->windowHeight - groundTex.height * 2 }));
	m_grounds.push_back(CreateGround(Vector2{ (float)groundTex.width, (float)app->windowHeight - groundTex.height * 2 }));
		
	m_player->Load();
}

void PlayState::Update(float _dt)
{
	for (int i = 0; i < m_grounds.size(); i++)
	{
		Ground* ground = m_grounds.at(i);
		Texture2D texture = ground->GetTexture();
		ground->Update(_dt);

		if (ground->GetPos().x < -texture.width)
		{
			m_grounds.push_back(CreateGround(Vector2{ (float)texture.width, (float)app->windowHeight - texture.height *2 }));

			ground->Unload();
			delete ground;
			m_grounds.erase(m_grounds.begin() + i, m_grounds.begin() + i + 1);
			i--;
		}
	}

	m_player->Update(_dt);

	if (IsKeyPressed(KEY_SPACE))
		isRunning = true;
}

void PlayState::Draw()
{
	for (Ground* ground : m_grounds)
		ground->Draw();

	m_player->Draw();
}

void PlayState::Unload()
{
	m_player->Unload();
}

Ground* PlayState::CreateGround(Vector2 _pos)
{
	Texture2D groundTex = Assets::GetTexture("ground");
	Ground* ground = new Ground(_pos, Vector2{1, 1}, groundTex, this);

	ground->Load();

	return ground;
}
