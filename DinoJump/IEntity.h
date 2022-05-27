#pragma once

#include <raylib.h>
#include "Physics.h"

class IGameState;

class IEntity
{
public:
	IEntity(Vector2 _pos, Vector2 _size, Texture2D _color, IGameState* _state, float _rotation) 
		: m_pos(_pos), m_size(_size), m_texture(_color), m_state(_state), m_rotation(_rotation) 
	{
	}

	virtual void Load() = 0;
	virtual void Update(float _dt) = 0;
	virtual void Draw() = 0;
	virtual void Unload() = 0;

	virtual void OnCollision(IEntity* _other) {}

	virtual Rectangle* GetCollider() 
	{
		return new Rectangle
		{
			m_pos.x,
			m_pos.y,
			m_texture.width * m_size.x,
			m_texture.height * m_size.y
		};
	}

	Vector2 GetPos() const { return m_pos; }
	Vector2 GetSize() const { return m_size; }
	Texture2D GetTexture() const { return m_texture; }

protected:
	Vector2 m_pos;
	Vector2 m_size;
	float m_rotation;
	Texture2D m_texture;
	IGameState* m_state;

};