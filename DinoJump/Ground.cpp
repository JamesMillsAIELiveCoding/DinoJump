#include "Ground.h"

#include "Config.h"
#include "PlayState.h"

Ground::Ground(Vector2 _start, Vector2 _size, Texture2D _texture, IGameState* _state)
	: IEntity(_start, _size, _texture, _state, 0)
{
}

void Ground::Load()
{
	m_animationSpeed = config.GetFloatValue("Ground", "scrollSpeed");
}

void Ground::Update(float _dt)
{
	if (((PlayState*)m_state)->isRunning)
	{
		m_pos.x -= m_animationSpeed * _dt;
	}
}

void Ground::Draw()
{
	Rectangle srcRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.width = m_texture.width;
	srcRect.height = m_texture.height;
	Rectangle destRect;
	destRect.x = m_pos.x;
	destRect.y = m_pos.y;
	destRect.width = srcRect.width * m_size.x;
	destRect.height = srcRect.height * m_size.x;

	DrawTexturePro(m_texture, srcRect, destRect, Vector2{ 0, 0 }, 0, RAYWHITE);
}

void Ground::Unload()
{
}
