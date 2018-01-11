#include "stdafx.h"

#include "Bullet.h"


void Bullet::update()
{
	Vector directionVector = Vector(direction);
	directionVector.scale(velocity);

	values = (TranslationMatrix(directionVector) * *this).values;

	lifetime--;
}
