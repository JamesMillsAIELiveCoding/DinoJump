#ifndef RAY_GIZMOS
#define RAY_GIZMOS

#include <raylib.h>

struct RayGizmos
{
	static void DrawRectCollider(Rectangle _rect)
	{
		DrawRectCollider(Vector2{ _rect.x, _rect.y }, Vector2{ _rect.width, _rect.height });
	}

	static void DrawRectCollider(Vector2 _position, Vector2 _size)
	{
		if (draw)
		{
			Rectangle colliderRect;
			colliderRect.x = _position.x;
			colliderRect.y = _position.y;
			colliderRect.width = _size.x;
			colliderRect.height = _size.y;
			DrawRectanglePro(colliderRect, Vector2{0, 0}, 0, color);

			colliderRect.x = _position.x + borderSize;
			colliderRect.y = _position.y + borderSize;
			colliderRect.width = _size.x - borderSize * 2;
			colliderRect.height = _size.y - borderSize * 2;
			DrawRectanglePro(colliderRect, Vector2{ 0, 0 }, 0, RAYWHITE);
		}
	}

	static void DrawCircleCollider(Vector2 _position, float _radius)
	{
		if (draw)
		{
			DrawCircle((int)_position.x, (int)_position.y, _radius, color);
			DrawCircle((int)_position.x + borderSize, (int)_position.y + borderSize, _radius - borderSize * 2, RAYWHITE);
		}
	}

	static void Draw()
	{
		if (showFPS && draw)
			DrawFPS(0, 0);

		if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_D))
			draw = !draw;

		if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_F))
			showFPS = !showFPS;

		color = RAYWHITE;
	}

	static Color color;

private:
	static bool showFPS;
	static bool draw;
	static int borderSize;

};

#endif // !RAY_GIZMOS