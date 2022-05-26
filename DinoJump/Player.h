#pragma once

#include "IEntity.h"

class IGameState;

#define GRAVITY 9.1f

class Player : public IEntity
{
public:
	Player(Vector2 _start, Vector2 _size, Texture2D _texture, IGameState* _state);
	virtual void Load();
	virtual void Update(float _dt);
	virtual void Draw();
	virtual void Unload();

private:
	void UpdateVerticalVelocity(float _dt);
	void UpdateAnimation(float _dt);

	float m_speed = 0;
	float m_animationSpeed = 0;
	float m_currentAnimTime = 0;
	int m_frameIndex = 0;
	int m_currentMaxFrames = 0;
	bool m_grounded = true;

	float m_groundHeight = 0;
	float m_jumpPower = 0;
	float m_yVelocity = 0;

	const int RUNNING_MAX_FRAME_COUNT = 3;
	const int IDLE_MAX_FRAME_COUNT = 1;

};