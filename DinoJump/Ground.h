#pragma once

#include "IEntity.h"

class Ground : public IEntity
{
public:
	Ground(Vector2 _start, Vector2 _size, Texture2D _texture, IGameState* _state);
	virtual void Load();
	virtual void Update(float _dt);
	virtual void Draw();
	virtual void Unload();

private:
	float m_animationSpeed = 0;

};

