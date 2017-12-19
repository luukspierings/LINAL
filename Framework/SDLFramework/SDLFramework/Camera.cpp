#include "Camera.h"

#define PI 3.14159265358979323846


Camera::Camera(float pWW, float pWH)
{
	wW = pWW;
	wH = pWH;

	eye = Vector({ 0,0,0,1 });
	lookAt = Vector({ 0,0,1,1 });
	up = Vector({ 0,-1,0,1 });

	near = 1.f;
	fov = 110.f;
	far = 20.f;

	calculate();
}


void Camera::moveCamera(Vector v)
{
	eye = eye + v;
	lookAt = eye + Vector({0,0,1,0});

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
		{ x.values[0], x.values[1], x.values[2], xcam },
		{ y.values[0], y.values[1], y.values[2], ycam },
		{ z.values[0], z.values[1], z.values[2], zcam },
		{ 0,0,0,1 }
	});

	float pi = PI;
	float scale = near * tan(((PI / 180) * fov) / 2);

	float value1 = ((far * -1) / (far - near));
	float value2 = ((far * -1 * near) / (far - near));

	projection = Matrix({
		{ scale, 0, 0, 0 },
		{ 0, scale, 0, 0 },
		{ 0, 0, value1, -1 },
		{ 0, 0, value2, 0 }
	});
}


Matrix Camera::toDraw(Matrix m)
{
	Matrix view{ m };

	// translate projection over camera
	view = projection.x(camera);

	// translate view over real points
	view = m.x(view);


	//// naberekening
	for (float Vcolumn = 0.f; Vcolumn < view.values.size(); Vcolumn++) {

		float w = view.values[Vcolumn][3];
		if (w <= 0.f) {
			view.values[Vcolumn][0] = -1.f;
			view.values[Vcolumn][1] = -1.f;
		}
		else {
			view.values[Vcolumn][0] = (wW / 2) + (((view.values[Vcolumn][0] + 1.f) / w) * (wW * 0.5f));
			view.values[Vcolumn][1] = (wH / 2) + (((view.values[Vcolumn][1] + 1.f) / w) * (wH * 0.5f));
			if(view.values[Vcolumn][2] != 0.f) view.values[Vcolumn][2] = (view.values[Vcolumn][2] * -1.f);
		}
	}

	return view;
}
