#include "Vec2.h"



Vec2::Vec2()
{
	m_x = 0.0f;
	m_y = 0.0f;
}


void Vec2::SetX(float x)
{
	m_x = x;
}

float Vec2::GetX()
{
	return m_x;
}

void Vec2::SetY(float y)
{
	m_y = y;
}

float Vec2::GetY()
{
	return m_y;
}
