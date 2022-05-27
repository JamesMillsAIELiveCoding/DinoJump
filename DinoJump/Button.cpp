#include "Button.h"

#include <raylib.h>

#include "FontRegistry.h"
#include "Physics.h"

Button::Button(string _text, Rectangle* _rect, Color* _color, OnClickEvent _onClick)
	: m_text(_text), m_rect(_rect), m_color(_color), m_clickEvent(_onClick)
{
	m_fontSize = 100.0f / _text.size();

	m_textPos = new Vector2();
	m_textPos->x = m_rect->x + m_rect->width / (_text.size() / 3);
	m_textPos->y = m_rect->y + m_rect->height / (_text.size() / 3);
}

void Button::Update(float _dt)
{
	Vector2 mousePos = GetMousePosition();

	if (Physics::OverlapsPoint(mousePos, *m_rect))
	{
		m_clickEvent();
	}
}

void Button::Draw()
{
	DrawRectangleRounded(*m_rect, 1.0f, 1, *m_color);
	DrawTextEx(fontRegistry.GetAsset("Roboto-Regular"), m_text.c_str(), *m_textPos, m_fontSize, 1.0f, BLACK);
}
