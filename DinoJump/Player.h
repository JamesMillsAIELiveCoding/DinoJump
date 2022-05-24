#pragma once

#include "IEntity.h"

class IGameState;

class Player : public IEntity
{
public:
	Player(Vector2 _start, Vector2 _size, Texture2D _texture, IGameState* _state);
	virtual void Load();
	virtual void Update(float _dt);
	virtual void Draw();
	virtual void Unload();

private:
	float m_speed = 0;
	float m_animationSpeed = 0;
	float m_currentTime = 0;
	int m_frameIndex = 0;
	int m_currentMaxFrames = 0;
	bool m_grounded = true;

	float m_groundHeight = 0;

	const int RUNNING_MAX_FRAME_COUNT = 3;
	const int IDLE_MAX_FRAME_COUNT = 1;

};