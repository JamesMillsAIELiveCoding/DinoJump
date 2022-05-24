#include "Player.h"

#include "Config.h"
#include "IGameState.h"
#include "RayGizmos.h"
#include "PlayState.h"

Player::Player(Vector2 _start, Vector2 _size, Texture2D _texture, IGameState* _state)
	: IEntity(_start, _size, _texture, _state, 0) {}

void Player::Load()
{
	m_speed = config.GetFloatValue("Player", "speed");
	m_animationSpeed = config.GetFloatValue("Player", "animationSpeed");

	m_groundHeight = m_state->app->windowHeight - m_texture.height - 30;
}

void Player::Update(float _dt)
{
	m_pos.y = fmin(m_pos.y, m_groundHeight);
	m_grounded = m_groundHeight - m_pos.y < 0.001f && m_groundHeight - m_pos.y > -0.001f;

	m_currentMaxFrames = ((PlayState*)m_state)->isRunning ? RUNNING_MAX_FRAME_COUNT : IDLE_MAX_FRAME_COUNT;

	m_currentTime += _dt;
	if (m_currentTime >= m_animationSpeed)
	{
		m_frameIndex++;

		if (m_frameIndex > m_currentMaxFrames - 1)
			m_frameIndex = 0;

		m_currentTime = 0;
	}
}

void Player::Draw()
{
	Rectangle srcRect;
	srcRect.x = m_frameIndex * 80 + 8 * m_frameIndex;
	srcRect.y = 0;
	srcRect.width = 80;
	srcRect.height = 86;
	Rectangle destRect;
	destRect.x = m_pos.x;
	destRect.y = m_pos.y;
	destRect.width = srcRect.width * m_size.x;
	destRect.height = srcRect.height * m_size.x;

	RayGizmos::color = GREEN;
	RayGizmos::DrawRectCollider(destRect);
	DrawTexturePro(m_texture, srcRect, destRect, Vector2{ 0, 0 }, 0, RAYWHITE);
}

void Player::Unload()
{

}