#pragma once
#include "Entity.h"
#include "Vec2.h"
#include <glut.h>

class Enemy : public Entity
{
public:
	Enemy();

	void SetDestinaiton(float x, float y);

	void FollowPlayer();

	void SetPosX(float x);
	float GetPosX();

	void SetPosY(float y);
	float GetPosY();

	void Draw();

private:
	Vec2 destination;

};

