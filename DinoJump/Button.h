#pragma once

#include <string>
#include <functional>

using std::string;
using std::function;

struct Image;
struct Color;
struct Rectangle;
struct Vector2;

typedef function<void()> OnClickEvent;

class Button
{
public:
	Button(string _text, Rectangle* _rect, Color* _color, OnClickEvent _onClick);

	void Update(float _dt);
	void Draw();

private:
	string m_text;
	Vector2* m_textPos;
	Rectangle* m_rect;
	Color* m_color;
	OnClickEvent m_clickEvent;

	float m_fontSize;

};