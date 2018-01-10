#include "Spaceship.h"

#include "Space.h"

Spaceship::Spaceship(Vector position, int size)
{

	if (position.values.size() < 3) return;

	this->size = size;

	//float x = position.values[0];
	//float y = position.values[1];
	//float z = position.values[2];
	//
	//float w = size;
	//float h = size / 2;
	//float l = size;

	//float foldMargin = w/20;

	//model.addValue({ x, y+h, z });								
	//model.addValue({ x + (w / 2) - foldMargin, y + h, z });
	//model.addValue({ x + (w / 2), y, z });
	//model.addValue({ x + (w / 2) + foldMargin, y + h, z });
	//model.addValue({ x + w, y + h, z });
	//
	//model.addValue({ x + (w / 2), y+h, z+l });

	//// not being drawed, this is just a help point in the middle for determining the crosshair line
	//model.addValue({ x + (w / 2), y + h, z });


	//model.addEdge(0, 1);
	//model.addEdge(1, 2);
	//model.addEdge(2, 3);
	//model.addEdge(3, 4);

	//model.addEdge(0, 5);
	//model.addEdge(1, 5);
	//model.addEdge(2, 5);
	//model.addEdge(3, 5);
	//model.addEdge(4, 5);

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

	// middle coords
	model.addValue({ x + (size / 2), y + (size / 2), z }); // 8: back middle
	model.addValue({ x + (size / 2), y + (size / 2), zS }); // 9: front middle

	model.addValue({ x, y + (size / 2), z + (size / 2) }); // 10: left middle
	model.addValue({ xS, y + (size / 2), z + (size / 2) }); // 11: right middle

	model.addValue({ x + (size / 2), yS, z + (size / 2) }); // 12: up middle
	model.addValue({ x + (size / 2), y, z + (size / 2) }); // 13: down middle


	//model.addValue({ x ,y + (size / 2),z }); // 10
	//model.addValue({ xS,y + (size / 2),z }); // 11

	//model.addValue({ x ,y + (size / 2),zS }); // 12
	//model.addValue({ xS,y + (size / 2),zS }); // 13

	//model.addValue({ x + (size / 2),y,z }); // 14
	//model.addValue({ x + (size / 2),y + size,z }); // 15

	//model.addValue({ x + (size / 2),y,zS }); // 16
	//model.addValue({ x + (size / 2),y + size,zS }); // 17



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

void Spaceship::accelerate()
{
	if(velocity < maxVelocity)velocity += 0.5f;
}

void Spaceship::rollLeft() {
	Vector v{ backMiddle() - frontMiddle() };
	model = model.rotate(turnDegrees, v.normalize(), model.middlePoint());
}
void Spaceship::rollRight() {
	Vector v{ backMiddle() - frontMiddle() };
	model = model.rotate(-turnDegrees, v.normalize(), model.middlePoint());
}

void Spaceship::moveLeft() {
	Vector v{ upMiddle() - downMiddle() };
	model = model.rotate(turnDegrees, v.normalize(), model.middlePoint());
}
void Spaceship::moveRight() {
	Vector v{ upMiddle() - downMiddle() };
	model = model.rotate(-turnDegrees, v.normalize(), model.middlePoint());
}

void Spaceship::moveUp() {
	Vector v{ leftMiddle() - rightMiddle() };
	model = model.rotate(turnDegrees, v.normalize(), model.middlePoint());
}
void Spaceship::moveDown() {
	Vector v{ leftMiddle() - rightMiddle() };
	model = model.rotate(-turnDegrees, v.normalize(), model.middlePoint());
}


void Spaceship::input(InputManager& inputM, Space& space)
{
	if (inputM.isKeyDown("Left Shift")) accelerate();
	if (inputM.isKeyDown("Q")) rollLeft();
	if (inputM.isKeyDown("E")) rollRight();
	if (inputM.isKeyDown("A")) moveLeft();
	if (inputM.isKeyDown("D")) moveRight();
	if (inputM.isKeyDown("W")) moveUp();
	if (inputM.isKeyDown("S")) moveDown();
	if (inputM.isKeyDown("Space")) {
		if (bulletTimer >= bulletCooldown) {
			space.addBullet();
			bulletTimer = 0;
		}
	}
	if (inputM.isKeyDown("H")) crosshairVisible = !crosshairVisible;

	bulletTimer++;
}

void Spaceship::update()
{

	Vector rightPoint = backRight();
	Vector backPoint = backMiddle();
	Vector downPoint = backDown();

	direction = (backPoint - downPoint).out((backPoint - rightPoint));

	Vector directionVector = Vector(direction);
	directionVector.scale(velocity / 1500.f);

	model = model * directionVector.getTranslatableMatrix();

	if(velocity > minVelocity) velocity -= 0.1f;
}

Matrix Spaceship::getDrawable() const
{
	return model;
}

Vector Spaceship::getDrawableDirection() const
{
	return direction;
}

bool Spaceship::isCrosshairVisible() const
{
	return crosshairVisible;
}

Vector Spaceship::backMiddle()
{
	return Vector(model.values[8]);
}

Vector Spaceship::backRight()
{
	Vector dir = Vector(model.values[2]) - Vector(model.values[3]);
	dir.scale(0.5f);
	return Vector(Vector(model.values[2]) + dir);
}

Vector Spaceship::backLeft()
{
	Vector dir = Vector(model.values[1]) - Vector(model.values[0]);
	dir.scale(0.5f);
	return Vector(Vector(model.values[1]) + dir);
}

Vector Spaceship::backDown()
{
	Vector dir = Vector(model.values[0]) - Vector(model.values[3]);
	dir.scale(0.5f);
	return Vector(Vector(model.values[0]) + dir);
}

Vector Spaceship::backUp()
{
	Vector dir = Vector(model.values[1]) - Vector(model.values[2]);
	dir.scale(0.5f);
	return Vector(Vector(model.values[1]) + dir);
}

Vector Spaceship::rightMiddle()
{
	return Vector(model.values[11]);
}

Vector Spaceship::leftMiddle()
{
	return Vector(model.values[10]);
}

Vector Spaceship::upMiddle()
{
	return Vector(model.values[12]);
}

Vector Spaceship::downMiddle()
{
	return Vector(model.values[13]);
}

Vector Spaceship::frontMiddle()
{
	return Vector(model.values[9]);
}




