#include "Spaceship.h"

Spaceship::Spaceship(Vector position, int size)
{

	if (position.values.size() < 3) return;

	float x = position.values[0];
	float y = position.values[1];
	float z = position.values[2];
	
	float w = size;
	float h = size / 2;
	float l = size;

	float foldMargin = w/20;

	model.addValue({ x, y+h, z });								
	model.addValue({ x + (w / 2) - foldMargin, y + h, z });
	model.addValue({ x + (w / 2), y, z });
	model.addValue({ x + (w / 2) + foldMargin, y + h, z });
	model.addValue({ x + w, y + h, z });
	
	model.addValue({ x + (w / 2), y+h, z+l });


	model.addEdge(0, 1);
	model.addEdge(1, 2);
	model.addEdge(2, 3);
	model.addEdge(3, 4);

	model.addEdge(0, 5);
	model.addEdge(1, 5);
	model.addEdge(2, 5);
	model.addEdge(3, 5);
	model.addEdge(4, 5);

}

void Spaceship::accelerate()
{
}

void Spaceship::rollLeft() {
	model = model.rotate(turnDegrees, 'z');
}
void Spaceship::rollRight() {
	model = model.rotate(-turnDegrees, 'z');
}

void Spaceship::moveLeft() {
	model = model.rotate(turnDegrees, 'y');
}
void Spaceship::moveRight() {
	model = model.rotate(-turnDegrees, 'y');
}

void Spaceship::moveUp() {
	model = model.rotate(-turnDegrees, 'x');
}
void Spaceship::moveDown() {
	model = model.rotate(turnDegrees, 'x');
}

void Spaceship::shoot()
{
}

void Spaceship::input(InputManager& inputM)
{

	if (inputM.isKeyDown("Shift")) accelerate();
	if (inputM.isKeyDown("Q")) rollLeft();
	if (inputM.isKeyDown("E")) rollRight();
	if (inputM.isKeyDown("A")) moveLeft();
	if (inputM.isKeyDown("D")) moveRight();
	if (inputM.isKeyDown("W")) moveUp();
	if (inputM.isKeyDown("S")) moveDown();
	if (inputM.isKeyDown("Space")) shoot();

}

Matrix Spaceship::getDrawable() const
{
	return model;
}



