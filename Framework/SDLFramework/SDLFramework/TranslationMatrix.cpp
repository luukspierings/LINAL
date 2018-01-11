
#include "stdafx.h"

#include "TranslationMatrix.h"

TranslationMatrix::TranslationMatrix(int size, float translation)
{
	for (int dimensionX = 0; dimensionX <= size; dimensionX++) {
		vector<float> c{};
		for (int dimensionY = 1; dimensionY <= size; dimensionY++) {
			if (dimensionX == size && dimensionY != size) c.push_back(translation);
			else if (dimensionX == dimensionY) c.push_back(1);
			else c.push_back(0);
		}
		translationM.addValue(c);
	}
}

TranslationMatrix::TranslationMatrix(vector<float> translations)
{
	for (int dimensionX = 0; dimensionX <= translations.size(); dimensionX++) {
		vector<float> c{};
		for (int dimensionY = 0; dimensionY <= translations.size(); dimensionY++) {
			if (dimensionX == translations.size() && dimensionY != translations.size()) c.push_back(translations[dimensionY]);
			else if (dimensionX == dimensionY) c.push_back(1);
			else c.push_back(0);
		}
		translationM.addValue(c);
	}
}

Matrix TranslationMatrix::operator*(const Matrix & m)
{
	Matrix newM{ m };
	int helpRows = 0;
	while (newM.dimension() < translationM.dimension()) {
		newM.addRow();
		helpRows++;
	}
	newM = newM * translationM;
	while (helpRows > 0) {
		newM.removeRow();
		helpRows--;
	}
	return newM;
}