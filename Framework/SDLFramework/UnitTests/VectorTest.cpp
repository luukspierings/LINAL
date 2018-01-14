#include "stdafx.h"
#include "CppUnitTest.h"

#include "../SDLFramework/Matrix.h"
#include "../SDLFramework/TranslationMatrix.h"
#include "../SDLFramework/Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(VectorTest)
	{
	public:

		TEST_METHOD(Vector_Creation)
		{
			Vector vector({ 1.f, 4.f, 8.f });
			Assert::AreEqual(vector.values[0], 1.f);
			Assert::AreEqual(vector.values[1], 4.f);
			Assert::AreEqual(vector.values[2], 8.f);
		}

		TEST_METHOD(Vector_Length)
		{
			Vector vector({ 3.f, 4.f });
			Assert::AreEqual(vector.length(), 5.f);

		}

		TEST_METHOD(Vector_Normalize)
		{
			Vector vector({ 64.f, 44.f });
			vector = vector.normalize();
			Assert::AreEqual(vector.length(), 1.f);
		}

		TEST_METHOD(Vector_Negative)
		{
			Vector vector({ 64.f, 44.f });
			vector = vector.negative();
			Assert::AreEqual(vector.values[0], -64.f);
			Assert::AreEqual(vector.values[1], -44.f);
		}

		TEST_METHOD(Vector_Scale)
		{
			Vector vector({ 5.f, 3.f });
			vector.scale(4);
			Assert::AreEqual(vector.values[0], 20.f);
			Assert::AreEqual(vector.values[1], 12.f);
		}

		TEST_METHOD(Vector_AngleWithout)
		{
			Vector vector1({ 2.f, 3.f });
			Vector vector2({ 2.f, 3.f });
			float angle = vector1.angle(vector2);
			Assert::AreEqual(angle, 0.f);
		}

		TEST_METHOD(Vector_AngleWith)
		{
			Vector vector1({ 2.f, 3.f });
			Vector vector2({ -5.f, 8.f });
			float angle = vector1.angle(vector2);
			Assert::AreEqual(angle, 65.7f, 0.1f);
		}

		TEST_METHOD(Vector_In)
		{
			Vector vector1({1.f, 2.f, 3.f});
			Vector vector2({4.f, -5.f, 6.f});
			float in = vector1.in(vector2);
			Assert::AreEqual(in, 12.f);
		}

		TEST_METHOD(Vector_Out)
		{
			Vector vector1({0.f, 0.f, 5.f});
			Vector vector2({5.f, 0.f, 5.f});
			Vector out = vector1.out(vector2);
			Assert::AreEqual(out.values[0], 0.f);
			Assert::AreEqual(out.values[1], 25.f);
			Assert::AreEqual(out.values[2], 0.f);
		}
	};
}