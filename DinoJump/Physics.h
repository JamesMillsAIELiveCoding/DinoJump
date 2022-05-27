#pragma once

#include <vector>

using std::vector;

class IEntity;
struct Rectangle;
struct Vector2;

typedef vector<IEntity*> EntityArray;

class Physics
{
public:
	static void AddEntity(IEntity* _entity);
	static void UpdateCollisions();
	static void Cleanup();

	static bool OverlapsPoint(Vector2 _point, Rectangle& _rect);

private:
	static bool DidCollide(Rectangle& _first, Rectangle& _second);
	static EntityArray m_entities;
};