#include "Enemy.h"

Enemy::Enemy()
{
	position.SetX(5);
	position.SetY(5);
}

void Enemy::SetDestinaiton(float x, float y)
{
	destination.SetX(x);
	destination.SetY(y);
}

void Enemy::FollowPlayer()
{

	float x, y;
	if (position.GetX() > destination.GetX())
	{
		x = position.GetX();
		x -= 2.0f;
		position.SetX(x);
	}
	else if (position.GetX() < destination.GetX())
	{
		x = position.GetX();
		x += 2.0f;
		position.SetX(x);
	}
	if (position.GetY() > destination.GetY())
	{
		y = position.GetY();
		y -= 2.0f;
		position.SetY(y);

	}
	else if (position.GetY() < destination.GetY())
	{
		y = position.GetY();
		y += 2.0f;
		position.SetY(y);
	}
}

void Enemy::SetPosX(float x)
{
	position.SetX(x);
}

float Enemy::GetPosX()
{
	return position.GetX();
}

void Enemy::SetPosY(float y)
{
	position.SetY(y);
}

float Enemy::GetPosY()
{
	return position.GetY();
}

void Enemy::Draw()
{
	glPointSize(10);
	glBegin(GL_POINTS);
	glColor3f(1, 0, 0);
	glVertex2f(position.GetX(), position.GetY());
	glEnd();
}

