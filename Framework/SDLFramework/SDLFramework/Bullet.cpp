#include "Bullet.h"


void Bullet::update()
{
	Vector directionVector = Vector(direction);
	directionVector.scale(velocity);

	values = (*this * directionVector.getTranslatableMatrix()).values;

	lifetime--;
}
