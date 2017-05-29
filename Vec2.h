#pragma once
class Vec2
{
public:
	Vec2();

	void SetX(float x);
	float GetX();

	void SetY(float y);
	float GetY();

private:
	float m_x;
	float m_y;
};

