#include "stdafx.h"

#include "Planet.h"


void Planet::update()
{

	float scaling = (expanding) ? expansionStep : -expansionStep;

	ScalingMatrix scalingM{ dimension(), 1.f + scaling };
	TranslationMatrix translationM{ dimension(), -(scaling*2) };

	values = (scalingM * *this).values;
	values = (translationM * *this).values;

	size += scaling;


	if (expanding && size > maxExpansion) expanding = false;
	else if (!expanding && size < minExpansion) expanding = true;

}
