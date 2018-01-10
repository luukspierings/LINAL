#include "Bullet.h"

Bullet::Bullet(Vector position, Vector direction): direction(direction)
{
	if (position.values.size() < 3) return;

	float x = position.values[0];
	float y = position.values[1];
	float z = position.values[2];
	float xS = x + size;
	float yS = y + size;
	float zS = z + size;

	// corner coords
	model.addValue({ x,y,z }); // 0: leftdown
	model.addValue({ x,yS,z }); // 1: leftup
	model.addValue({ xS,yS,z }); // 2: rightup
	model.addValue({ xS,y,z }); // 3: rightdown

	model.addValue({ x,y,zS });
	model.addValue({ x,yS,zS });
	model.addValue({ xS,yS,zS });
	model.addValue({ xS,y,zS });


	// front lines
	model.addEdge(0, 1);
	model.addEdge(1, 2);
	model.addEdge(2, 3);
	model.addEdge(3, 0);

	// back lines
	model.addEdge(4, 5);
	model.addEdge(5, 6);
	model.addEdge(6, 7);
	model.addEdge(7, 4);

	// lines between front and back
	model.addEdge(0, 4);
	model.addEdge(1, 5);
	model.addEdge(2, 6);
	model.addEdge(3, 7);

}

void Bullet::update()
{
	Vector directionVector = Vector(direction);
	directionVector.scale(velocity / 100.f);

	model = model * directionVector.getTranslatableMatrix();

	lifetime--;
}

Matrix Bullet::getDrawable() const
{
	return model;
}