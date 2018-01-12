#include "stdafx.h"

#include "Camera.h"

#define PI 3.14159265358979323846


Camera::Camera(float pWW, float pWH)
{
	wW = pWW;
	wH = pWH;

	eye = Vector({ 0,0,0,1 });
	lookAt = Vector({ 0,0,1,1 });
	up = Vector({ 0,1,0,1 });

	near = 10.f;
	fov = 110.f;
	far = 20.f;

	calculate();
}


void Camera::setEye(Vector v)
{
	eye = Vector({ v.values[0],v.values[1],v.values[2], 1 });

	calculate();
}

void Camera::setLookat(Vector v)
{
	lookAt = Vector({ v.values[0],v.values[1],v.values[2], 1 });

	calculate();
}

void Camera::setUp(Vector v) {

	v = v.normalize();

	up = Vector({ v.values[0], v.values[1], v.values[2], 1});

	calculate();
}

void Camera::calculate()
{
	z = Vector((eye - lookAt).normalize());
	y = Vector(up.normalize());
	x = Vector(y.out(z).normalize());
	y = z.out(x).normalize();

	float xcam = x.in(eye);
	float ycam = y.in(eye);
	float zcam = z.in(eye);

	if (xcam != 0.f) xcam *= -1;
	if (ycam != 0.f) ycam *= -1;
	if (zcam != 0.f) zcam *= -1;

	camera = Matrix({
		{ x.values[0], y.values[0], z.values[0], 0 },
		{ x.values[1], y.values[1], z.values[1], 0 },
		{ x.values[2], y.values[2], z.values[2], 0 },
		{ xcam,ycam,zcam,1 }
	});

	float scale = near * tan(((PI / 180) * fov) / 2);

	float value1 = ((far * -1) / (far - near));
	float value2 = ((far * -1 * near) / (far - near));

	projection = Matrix({
		{ scale, 0, 0, 0 },
		{ 0, scale, 0, 0 },
		{ 0, 0, value1, value2 },
		{ 0, 0, -1, 0 }
	});

}

void Camera::initiateBirdsEyeView(Vector lookat)
{
	setEye(lookAt - Vector({0,20,0,0}));
}

void Camera::input(InputManager & inputM)
{
	if (inputM.isKeyDown("Left"));
	if (inputM.isKeyDown("Right"));
	if (inputM.isKeyDown("Up"));
	if (inputM.isKeyDown("Down"));
	if (inputM.isKeyDown("Right Shift"));
	if (inputM.isKeyDown("Keypad 1"));
}


Matrix Camera::toDraw(Matrix m)
{
	if (m.dimension() < 3) return m;

	Matrix view{ m };
	view.fitToDimension(camera.amount());

	view = view * camera * projection;

	for (float Vcolumn = 0.f; Vcolumn < view.values.size(); Vcolumn++) {

		float w = view.values[Vcolumn][3];
		view.values[Vcolumn][0] = (wW / 2) + (((view.values[Vcolumn][0] + 1.f) / w) * (wW * 0.5f));
		view.values[Vcolumn][1] = (wH / 2) + (((view.values[Vcolumn][1] + 1.f) / w) * (wH * 0.5f));
		if(view.values[Vcolumn][2] != 0.f) view.values[Vcolumn][2] = (view.values[Vcolumn][2] * -1.f);
	}

	//view.fitToDimension(m.dimension()); Let de w-row stay in the matrix, so we can see if it should be drawn or not.
	return view;
}
