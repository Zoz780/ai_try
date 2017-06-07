#include "Enemy.h"

Enemy::Enemy()
{
	position.SetX(5);
	position.SetY(5);
	pathfinder.LoadWaypoints();
}

void Enemy::SetDestinaiton(float x, float y)
{
	/*destination.SetX(x);
	destination.SetY(y);*/

	Vec2 goal;
	goal = pathfinder.SearchClosestWaypoint(position.GetX(), position.GetY());
	destination.SetX(goal.GetX());
	destination.SetY(goal.GetY());
}

void Enemy::MoveToDestination()
{
	Vec2 diff;

	diff.SetX(destination.GetX() - position.GetX());
	diff.SetY(destination.GetY() - position.GetY());

	if (diff.GetLength() == 0)        
		return;

	const float speed = 2.0f;       

	diff.SetMagnitude(speed);

	float x = position.GetX();
	float y = position.GetY();

	x += diff.GetX();
	y += diff.GetY();

	position.SetX(x);
	position.SetY(y);
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
	pathfinder.DrawWaypoints();

	glPointSize(10);
	glBegin(GL_POINTS);
	glColor3f(1, 0, 0);
	glVertex2f(position.GetX(), position.GetY());
	glEnd();
}