#include "stdafx.h"

#include "Planet.h"


void Planet::update()
{
	Vector mPoint = middlePoint();
	Vector zPoint = mPoint.negative();

	float scaling = (expanding) ? expansionStep : -expansionStep;
	float scaler = 0;

	if (expanding)
	{
		scaler = 1.f + scaling;
	}
	else
	{
		scaler = 1 / (1.f + -scaling);
	}

	TranslationMatrix translation{zPoint};
	TranslationMatrix translationM{mPoint};
	ScalingMatrix scalingM{dimension(), scaler};

	values = (translation * *this).values;
	values = (scalingM * *this).values;
	values = (translationM * *this).values;

	size += scaling;

	if (expanding && size > maxExpansion) expanding = false;
	else if (!expanding && size < minExpansion) expanding = true;

}
