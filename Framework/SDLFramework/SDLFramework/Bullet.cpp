#include "stdafx.h"

#include "Bullet.h"
#include "FWApplication.h"


void Bullet::update()
{
	Vector directionVector = Vector(direction);
	direction = directionVector.normalize();
	directionVector.scale((velocity+relativeVelocity) * FWApplication::GetInstance()->getDeltaTime());

	values = (TranslationMatrix(directionVector) * *this).values;

	lifetime -= FWApplication::GetInstance()->getDeltaTime();
}
