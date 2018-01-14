#include "stdafx.h"

#include "Planet.h"


void Planet::update()
{
	Vector mPoint = middlePoint();
	Vector zPoint = mPoint.negative();

	float scaling = (expanding) ? expansionStep : -expansionStep;

	TranslationMatrix translation{zPoint};
	ScalingMatrix scalingM{ dimension(), 1.f + scaling };

	TranslationMatrix translationM{mPoint};

	values = (translation * *this).values;
	values = (scalingM * *this).values;
	values = (translationM * *this).values;

	size += scaling;

	if (expanding && size > maxExpansion) expanding = false;
	else if (!expanding && size < minExpansion) expanding = true;

}
