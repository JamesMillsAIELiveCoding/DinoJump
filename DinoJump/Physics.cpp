#include "Physics.h"

#include "IEntity.h"
#include "RayGizmos.h"

#include <raylib.h>

EntityArray Physics::m_entities;

void Physics::AddEntity(IEntity* _entity)
{
	m_entities.push_back(_entity);
}

void Physics::Cleanup()
{
	for (IEntity* entity : m_entities)
	{
		delete entity;
	}

	m_entities.clear();
}

bool Physics::OverlapsPoint(Vector2 _point, Rectangle& _rect)
{
	return _point.x < _rect.x + _rect.width &&
		_point.x > _rect.x &&
		_point.y < _rect.y + _rect.height &&
		_point.y > _rect.y;
}

void Physics::UpdateCollisions()
{
	for (size_t i = 0; i < m_entities.size(); i++)
	{
		IEntity* first = m_entities.at(i);
		RayGizmos::color = GREEN;
		RayGizmos::DrawRectCollider(*first->GetCollider());

		for (size_t j = 0; j < m_entities.size(); j++)
		{
			IEntity* second = m_entities.at(j);

			if (first == second)
				continue;

			if (DidCollide(*first->GetCollider(), *second->GetCollider()))
			{
				first->OnCollision(second);
			}
		}
	}
}

bool Physics::DidCollide(Rectangle& _first, Rectangle& _second)
{
	return _first.x < _second.x + _second.width &&
		_first.x + _first.width > _second.x && 
		_first.y < _second.y + _second.height &&
		_first.y + _first.height > _second.y;
}