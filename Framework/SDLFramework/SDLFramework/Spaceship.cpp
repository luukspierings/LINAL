#include "stdafx.h"

#include "Spaceship.h"

#include "SpaceView.h"
#include "FWApplication.h"
#include "Colors.h"


Spaceship::Spaceship(Vector position, float size): size(size)
{
	if (position.values.size() < 3) return;

	Color color = Colors::yellow();

	model = Square{ position, size, color };

	float x = position.values[0];
	float y = position.values[1];
	float z = position.values[2];
	float xS = x + size;
	float yS = y + size;
	float zS = z + size;

	// middle coords
	model.addValue({ x + (size / 2), y + (size / 2), z }); // 8: back middle
	model.addValue({ x + (size / 2), y + (size / 2), zS }); // 9: front middle

	model.addValue({ x, y + (size / 2), z + (size / 2) }); // 10: left middle
	model.addValue({ xS, y + (size / 2), z + (size / 2) }); // 11: right middle

	model.addValue({ x + (size / 2), yS, z + (size / 2) }); // 12: up middle
	model.addValue({ x + (size / 2), y, z + (size / 2) }); // 13: down middle

	aabb = Square{ position, size };
}

void Spaceship::accelerate()
{
	if(velocity < maxVelocity) velocity += (velocityStep * FWApplication::GetInstance()->getDeltaTime()) + (velocityDecrease * FWApplication::GetInstance()->getDeltaTime());
}

void Spaceship::rollLeft() {
	Vector v{ backMiddle() - frontMiddle() };
	model = RotationMatrix(-turnDegrees, v.normalize(), model.middlePoint()) * model;
}
void Spaceship::rollRight() {
	Vector v{ backMiddle() - frontMiddle() };
	model = RotationMatrix(turnDegrees, v.normalize(), model.middlePoint()) * model;
}

void Spaceship::moveLeft() {
	Vector v{ upMiddle() - downMiddle() };
	model = RotationMatrix(turnDegrees, v.normalize(), model.middlePoint()) * model;
}
void Spaceship::moveRight() {
	Vector v{ upMiddle() - downMiddle() };
	model = RotationMatrix(-turnDegrees, v.normalize(), model.middlePoint()) * model;
}

void Spaceship::moveUp() {
	Vector v{ leftMiddle() - rightMiddle() };
	model = RotationMatrix(-turnDegrees, v.normalize(), model.middlePoint()) * model;
}
void Spaceship::moveDown() {
	Vector v{ leftMiddle() - rightMiddle() };
	model = RotationMatrix(turnDegrees, v.normalize(), model.middlePoint()) * model;
}


void Spaceship::input(InputManager& inputM, SpaceView& space)
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
			space.addBullet(velocity);
			bulletTimer = 0;
		}
	}
	if (inputM.isKeyPressed("H")) crosshairVisible = !crosshairVisible;

	bulletTimer++;
}

void Spaceship::update()
{
	Vector rightPoint = backRight();
	Vector backPoint = backMiddle();
	Vector downPoint = backDown();

	direction = (backPoint - rightPoint).out((backPoint - downPoint));

	Vector directionVector = Vector(direction);
	directionVector = directionVector.normalize();
	directionVector.scale(velocity * FWApplication::GetInstance()->getDeltaTime());

	model = TranslationMatrix(directionVector) * model;

	if(velocity > minVelocity) velocity -= (velocityDecrease * FWApplication::GetInstance()->getDeltaTime());
	if (velocity < minVelocity) velocity = minVelocity;
}

void Spaceship::setCameraPerspective(Camera & camera)
{
	Vector back = backMiddle();
	Vector front = frontMiddle();
	Vector left = backLeft();
	Vector right = backRight();
	Vector down = backDown();

	Vector up = (back - front).out(left - right);
	up = up.normalize();
	camera.setUp(up);

	Vector birdsEye = (back - right).out((down - back));
	birdsEye.scale(1.f / 2.2f);

	birdsEye = back + birdsEye;

	camera.setLookat(back);
	camera.setEye(birdsEye);
}

Matrix Spaceship::getDrawable() const
{
	return model;
}

Vector Spaceship::getDirection() const
{
	return direction;
}

bool Spaceship::isCrosshairVisible() const
{
	return crosshairVisible;
}

Matrix Spaceship::getDrawableCrosshair()
{
	return direction.getDrawableMatrix(frontMiddle());
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

Vector Spaceship::middle()
{
	return model.middlePoint();
}




