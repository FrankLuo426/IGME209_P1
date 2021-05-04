#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" __declspec(dllimport) char* GetTeam();
extern "C" __declspec(dllimport) bool SetStart(int xpos, int ypos);
extern "C" __declspec(dllimport) bool SetMaze(const int** tempData, int width, int height);
extern "C" __declspec(dllimport) int** GetMaze(int& width, int& height);
extern "C" __declspec(dllimport) bool GetNextPosition(int& xpos, int& ypos);
extern "C" __declspec(dllimport) bool SetEnd(int xpos, int ypos);
extern "C" __declspec(dllimport) bool GetEnd(int& xpos, int& ypos);
extern "C" __declspec(dllimport) bool GetStart(int& xpos, int& ypos);
extern "C" __declspec(dllimport) bool Restart();

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestTeamName)
		{

			Assert::IsTrue(strcmp(GetTeam(), "John Zhang Frank Luo") == 0);
		}

		TEST_METHOD(TestSetMaze)
		{
			try
			{
				int** tempData = new int* [10];

				for (int i = 0; i < 10; i++)
				{
					tempData[i] = new int[10];
				}

				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						tempData[i][j] = 1;
					}
				}

				const int** data = (const int**)tempData;
				SetMaze(data, 10, 10);
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"set start threw exception");
			}
		}

		TEST_METHOD(TestGetMaze)
		{
			try
			{
				int x = 1;
				int y = 1;
				int& xA = x;
				int& yA = y;
				GetMaze(xA, yA);
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"set start threw exception");
			}
		}

		TEST_METHOD(TestGetNextPosition)
		{
			try
			{
				int x = 1;
				int y = 1;
				int& xA = x;
				int& yA = y;
				GetNextPosition(xA,yA);
				
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"set start threw exception");
			}
		}

		TEST_METHOD(TestSetStart)
		{
			try
			{
				SetStart(1, 2);
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"set start threw exception");
			}
		}

		TEST_METHOD(TestGetStart)
		{
			try
			{
				int x = 1;
				int y = 1;
				int& xA = x;
				int& yA = y;
				GetStart(xA, yA);
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"set start threw exception");
			}
		}

		TEST_METHOD(TestSetEnd)
		{
			try
			{
				SetEnd(3, 6);
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"set start threw exception");
			}
		}

		TEST_METHOD(TestGetEnd)
		{
			try
			{
				int x = 1;
				int y = 1;
				int& xA = x;
				int& yA = y;
				GetEnd(xA, yA);
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"set start threw exception");
			}
		}
		TEST_METHOD(TestRestart)
		{
			try
			{
				Restart();
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"set start threw exception");
			}
		}
	};
}
