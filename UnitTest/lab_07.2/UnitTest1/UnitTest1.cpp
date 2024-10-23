#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_07.2/lab_07.2.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForMatrixProcessing
{
	TEST_CLASS(UnitTestForMatrixProcessing)
	{
	public:
		TEST_METHOD(TestSumMinEvenColumns)
		{
			
			const int k = 3;
			const int n = 4;

			
			int** matrix = new int* [k];
			for (int i = 0; i < k; i++) {
				matrix[i] = new int[n];
			}

			
			matrix[0][0] = 10; matrix[0][1] = 20; matrix[0][2] = 30; matrix[0][3] = 40;
			matrix[1][0] = 15; matrix[1][1] = 25; matrix[1][2] = 35; matrix[1][3] = 45;
			matrix[2][0] = 5;  matrix[2][1] = 22; matrix[2][2] = 33; matrix[2][3] = 44;

			
			int expectedSum = 5 + 30;

			
			int actualSum = SumMinEvenColumns(matrix, k, n);

			
			Assert::AreEqual(expectedSum, actualSum);

			
			for (int i = 0; i < k; i++) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}

		TEST_METHOD(TestEmptyMatrix)
		{
			
			const int k = 0;
			const int n = 0;

			
			int** matrix = nullptr;

			
			int expectedSum = 0;

			
			int actualSum = SumMinEvenColumns(matrix, k, n);

			
			Assert::AreEqual(expectedSum, actualSum);
		}

		TEST_METHOD(TestSingleColumnMatrix)
		{
			
			const int k = 3;
			const int n = 1;

			
			int** matrix = new int* [k];
			for (int i = 0; i < k; i++) {
				matrix[i] = new int[n];
			}

			
			matrix[0][0] = 10;
			matrix[1][0] = 15;
			matrix[2][0] = 5;

			
			int expectedSum = 5;

			
			int actualSum = SumMinEvenColumns(matrix, k, n);

			
			Assert::AreEqual(expectedSum, actualSum);

			
			for (int i = 0; i < k; i++) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}
	};
}
