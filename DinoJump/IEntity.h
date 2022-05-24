#pragma once

#include <raylib.h>

class IGameState;

class IEntity
{
public:
	IEntity(Vector2 _pos, Vector2 _size, Texture2D _color, IGameState* _state) 
		: m_pos(_pos), m_size(_size), m_texture(_color), m_state(_state) {}

	virtual void Load() = 0;
	virtual void Update(float _dt) = 0;
	virtual void Draw() = 0;
	virtual void Unload() = 0;

protected:
	Vector2 m_pos;
	Vector2 m_size;
	Texture2D m_texture;
	IGameState* m_state;

};