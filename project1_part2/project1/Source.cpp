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
int times;

bool isSetStarted;
bool isSetEnded;



__declspec(dllexport) char* GetTeam() {
	return memberName;
}

__declspec(dllexport) void SetMaze(const int** data, int width, int height) {
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

__declspec(dllexport) int** GetMaze(int& width, int& height) {
	width = mazeWidth;
	height = mazeHeight;
	return mazeData;
}

__declspec(dllexport) void GetNextPosition(int& xpos, int& ypos) {
	xpos = pos[0][times] = times;
	ypos = pos[1][times] = times;
	times++;
}

__declspec(dllexport) void SetStart(int xpos, int ypos) {
	startX = xpos;
	startY = ypos;
	isSetStarted = true;
}

__declspec(dllexport) void GetStart(int& xpos, int& ypos) {
	if (!isSetStarted) {
		xpos = -1;
		ypos = -1;
	}
	else
	{
		xpos = startX;
		ypos = startY;
	}
}

__declspec(dllexport) void SetEnd(int xpos, int ypos) {
	endX = xpos;
	endY = ypos;
	isSetEnded = true;
}


__declspec(dllexport) void GetEnd(int& xpos, int& ypos) {
	if (!isSetEnded) {
		xpos = -1;
		ypos = -1;
	}
	else {
		xpos = endX;
		ypos = endY;
	}
}