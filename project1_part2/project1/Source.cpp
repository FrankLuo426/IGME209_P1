#include "pch.h"

char* memberName = (char*)"John Zhang Frank Luo";

int** mazeData;
int mazeWidth;
int mazeHeight;
int startX;
int startY;
int endX;
int endY;

int pos[2][100];
int timesX;
int timesY;

bool isSetStarted;
bool isSetEnded;

__declspec(dllexport) char* GetTeam() {
	return memberName;
}

__declspec(dllexport) bool SetMaze(const int** data, int width, int height) {

	try
	{
		mazeWidth = width;
		mazeHeight = height;
		mazeData = new int* [width];

		for (int i = 0; i < width; i++) {
			mazeData[i] = new int[height];
		}


		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				mazeData[i][j] = (int)data[i][j];
			}
		}

	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}

__declspec(dllexport) int** GetMaze(int& width, int& height) {
	if (mazeData == NULL)
	{
		return nullptr;
	}
	width = mazeWidth;
	height = mazeHeight;
	return mazeData;
}

__declspec(dllexport) bool GetNextPosition(int& xpos, int& ypos) {

	if (pos[0][timesX] != NULL && pos[1][timesY] != NULL)
	{
		xpos = pos[0][timesX] = 1;
		ypos = pos[1][timesY] = 1;
		timesX++;
		timesY++;
		return true;
	}
	else
	{
		return false;
	}
}

__declspec(dllexport) bool SetStart(int xpos, int ypos) {
	if (xpos != NULL && ypos != NULL)
	{
		startX = xpos;
		startY = ypos;
		isSetStarted = true;
		return true;
	}
	else
	{
		return false;
	}
}

__declspec(dllexport) bool GetStart(int& xpos, int& ypos) {
	if (!isSetStarted) {
		xpos = startX;
		ypos = startY;
		return true;
	}
	else
	{
		return false;
	}
}

__declspec(dllexport) bool SetEnd(int xpos, int ypos) {
	if (xpos != NULL && ypos != NULL) {
		endX = xpos;
		endY = ypos;
		isSetEnded = true;
		return true;
	}
	else
	{
		return false;
	}
}


__declspec(dllexport) bool GetEnd(int& xpos, int& ypos) {
	if (isSetEnded) {
		xpos = endX;
		ypos = endY;
		return true;
	}
	else {
		return false;
	}
}

__declspec(dllexport) bool Restart()
{
	try
	{
		//Type here
		timesX = 0;
		timesY = 0;
	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}