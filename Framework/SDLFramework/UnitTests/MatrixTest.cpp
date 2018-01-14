#include "stdafx.h"
#include "CppUnitTest.h"

#include "../SDLFramework/Matrix.h"
#include "../SDLFramework/TranslationMatrix.h"
#include "../SDLFramework/RotationMatrix.h"
#include "../SDLFramework/ScalingMatrix.h"
#include "../SDLFramework/Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(MatrixTest)
	{
	public:

		TEST_METHOD(Matrix_Copy)
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

		TEST_METHOD(Matrix_Translation)
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

		TEST_METHOD(Matrix_Rotation)
		{
			Vector vector({0.f, 1.f, 0.f});

			Matrix matrix1;
			matrix1.addValue({3.f, 3.f, 3.f});
			matrix1.addValue({4.f, 4.f, 4.f});

			RotationMatrix rotationMatrix(90, vector);

			matrix1 = rotationMatrix * matrix1;

			Assert::AreEqual(matrix1.values[0][0], 3.f, 0.001f);
			Assert::AreEqual(matrix1.values[0][1], 3.f, 0.001f);
			Assert::AreEqual(matrix1.values[0][2], -3.f, 0.001f);

			Assert::AreEqual(matrix1.values[1][0], 4.f, 0.001f);
			Assert::AreEqual(matrix1.values[1][1], 4.f, 0.001f);
			Assert::AreEqual(matrix1.values[1][2], -4.f, 0.001f);
		}

		TEST_METHOD(Matrix_Scaling)
		{
			Vector vector({0.f, 1.f, 0.f});

			Matrix matrix1;
			matrix1.addValue({3.f, 3.f, 3.f});
			matrix1.addValue({4.f, 4.f, 4.f});

			ScalingMatrix scalingMatrix(3, 5);

			matrix1 = scalingMatrix * matrix1;

			Assert::AreEqual(matrix1.values[0][0], 15.f, 0.001f);
			Assert::AreEqual(matrix1.values[0][1], 15.f, 0.001f);
			Assert::AreEqual(matrix1.values[0][2], 15.f, 0.001f);

			Assert::AreEqual(matrix1.values[1][0], 20.f, 0.001f);
			Assert::AreEqual(matrix1.values[1][1], 20.f, 0.001f);
			Assert::AreEqual(matrix1.values[1][2], 20.f, 0.001f);
		}

		TEST_METHOD(Matrix_Scaling_Translation)
		{
			Vector vectorTranslation({2.f, 2.f, 2.f});

			Matrix matrix1;
			matrix1.addValue({3.f, 3.f, 3.f});
			matrix1.addValue({4.f, 4.f, 4.f});

			ScalingMatrix scalingMatrix(3, 5);
			TranslationMatrix translationMatrix(vectorTranslation);
			
			matrix1 = scalingMatrix * matrix1;
			matrix1 = translationMatrix * matrix1;

			Assert::AreEqual(matrix1.values[0][0], 17.f);
			Assert::AreEqual(matrix1.values[0][1], 17.f);
			Assert::AreEqual(matrix1.values[0][2], 17.f);

			Assert::AreEqual(matrix1.values[1][0], 22.f);
			Assert::AreEqual(matrix1.values[1][1], 22.f);
			Assert::AreEqual(matrix1.values[1][2], 22.f);
		}

		TEST_METHOD(Matrix_Rotation_Translation)
		{
			Vector vectorRotation({0.f, 1.f, 0.f});
			Vector vectorTranslation({2.f, 2.f, 2.f});


			Matrix matrix1;
			matrix1.addValue({3.f, 3.f, 3.f});
			matrix1.addValue({4.f, 4.f, 4.f});

			TranslationMatrix translationMatrix(vectorTranslation);
			RotationMatrix rotationMatrix(90, vectorRotation);

			matrix1 = rotationMatrix * matrix1;
			matrix1 = translationMatrix * matrix1;

			Assert::AreEqual(matrix1.values[0][0], 5.f, 0.001f);
			Assert::AreEqual(matrix1.values[0][1], 5.f, 0.001f);
			Assert::AreEqual(matrix1.values[0][2], -1.f, 0.001f);

			Assert::AreEqual(matrix1.values[1][0], 6.f, 0.001f);
			Assert::AreEqual(matrix1.values[1][1], 6.f, 0.001f);
			Assert::AreEqual(matrix1.values[1][2], -2.f, 0.001f);
		}

		TEST_METHOD(Matrix_Rotation_Scaling_Translation)
		{
			Vector vectorRotation({0.f, 1.f, 0.f});
			Vector vectorTranslation({2.f, 2.f, 2.f});


			Matrix matrix1;
			matrix1.addValue({3.f, 3.f, 3.f});
			matrix1.addValue({4.f, 4.f, 4.f});

			TranslationMatrix translationMatrix(vectorTranslation);
			RotationMatrix rotationMatrix(90, vectorRotation);
			ScalingMatrix scalingMatrix(3, 4);

			matrix1 = rotationMatrix * matrix1;
			matrix1 = scalingMatrix * matrix1;
			matrix1 = translationMatrix * matrix1;

			Assert::AreEqual(matrix1.values[0][0], 14.f, 0.001f);
			Assert::AreEqual(matrix1.values[0][1], 14.f, 0.001f);
			Assert::AreEqual(matrix1.values[0][2], -10.f, 0.001f);

			Assert::AreEqual(matrix1.values[1][0], 18.f, 0.001f);
			Assert::AreEqual(matrix1.values[1][1], 18.f, 0.001f);
			Assert::AreEqual(matrix1.values[1][2], -14.f, 0.001f);
		}
	};
}