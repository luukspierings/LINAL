#include "stdafx.h"
#include "CppUnitTest.h"

#include "../SDLFramework/Matrix.h"
#include "../SDLFramework/TranslationMatrix.h"
#include "../SDLFramework/Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(MatrixTest)
	{
	public:

		TEST_METHOD(MatrixCopy)
		{
			Matrix matrix1;
			matrix1.addValue({ 2.f, 3.f });
			matrix1.addValue({ 5.f, 7.f });

			Matrix matrix2(matrix1);

			Assert::AreEqual(matrix1.values[0][0], matrix2.values[0][0]);
			Assert::AreEqual(matrix1.values[0][1], matrix2.values[0][1]);
			Assert::AreEqual(matrix1.values[1][0], matrix2.values[1][0]);
			Assert::AreEqual(matrix1.values[1][1], matrix2.values[1][1]);
		}

		TEST_METHOD(MatrixTranslation)
		{
			Vector vector({ 2.f, 2.f });

			Matrix matrix1;
			matrix1.addValue({ 3.f, 3.f });
			matrix1.addValue({ 4.f, 4.f });

			TranslationMatrix translationMatrix(vector);

			matrix1 = translationMatrix *  matrix1;
			Assert::AreEqual(matrix1.values[0][0], 5.f);
			Assert::AreEqual(matrix1.values[1][0], 6.f);
			Assert::AreEqual(matrix1.values[0][1], 5.f);
			Assert::AreEqual(matrix1.values[1][1], 6.f);
		}
	};
}