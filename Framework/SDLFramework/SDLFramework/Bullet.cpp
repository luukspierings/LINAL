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

bool Bullet::collidesWith(Matrix * col)
{
	for (auto polygon : polygons) {
		if (polygon.collidesWith(this, middlePoint(), direction)) {

			Vector intersection = polygon.collisionIntersection(this, middlePoint(), direction);

			Vector intersectionToBullet = intersection - middlePoint();

			float bulletToIntersectionLength = intersectionToBullet.length();

			if (closestPolygon == nullptr) {
				closestPolygon = &polygon;
			}
			else if (&polygon != closestPolygon) {
				if (lastCollisionDistance > bulletToIntersectionLength) {
					closestPolygon = &polygon;
				}
			}
			else {
				if (closestCollision == nullptr) {
					closestCollision = col;
					lastCollisionDistance = bulletToIntersectionLength;
				}
				else if (col != closestCollision) {
					if (lastCollisionDistance > bulletToIntersectionLength) {
						closestCollision = col;
						lastCollisionDistance = bulletToIntersectionLength;
					}
				}
				else {
					if (lastCollisionDistance < bulletToIntersectionLength) {
						return true;
					}
					lastCollisionDistance = bulletToIntersectionLength;
				}
			}
		}
	}
	return false;
}
