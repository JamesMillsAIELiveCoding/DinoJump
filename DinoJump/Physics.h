#pragma once

#include <vector>

using std::vector;

class IEntity;
struct Rectangle;

typedef vector<IEntity*> EntityArray;

class Physics
{
public:
	static void AddEntity(IEntity* _entity);
	static void UpdateCollisions();
	static void Cleanup();

private:
	static bool DidCollide(Rectangle& _first, Rectangle& _second);
	static EntityArray m_entities;
};