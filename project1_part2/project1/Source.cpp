#include "pch.h"
#include "Vertex.h"
#include "Graph.h"
#include <iostream> 
#include <vector> 
using namespace std;

char* memberName = (char*)"John Zhang Frank Luo";

const int** mazeData;
int mazeWidth;
int mazeHeight;

int** adjList;
vector<Vertex> vertices;
Graph graph;

vector<Vertex> path;
int times = 0;

int startX;
int startY;
int endX;
int endY;


bool isSetStarted = false;

__declspec(dllexport) char* GetTeam() {
	return memberName;
}

__declspec(dllexport) bool SetMaze(const int** data, int width, int height) {

	try
	{
		isSetStarted = false;

		mazeWidth = width;
		mazeHeight = height;
		mazeData = data;

		adjList = new int* [mazeWidth];

		for (int i = 0; i < mazeWidth; ++i) {
			adjList[i] = new int[mazeHeight];
		}


		for (int i = 0; i < mazeWidth; i++) {
			for (int j = 0; j < mazeHeight; j++) {
				adjList[i][j] = mazeData[i][j];

				if (adjList[i][j] == 0) {
					Vertex temp = Vertex(i, j, 0, 0);
					vertices.push_back(temp);
				}
			}
		}

		graph = Graph(vertices, adjList, mazeWidth, mazeHeight);
	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}

__declspec(dllexport) int** GetMaze(int& width, int& height) {
	width = mazeWidth;
	height = mazeHeight;
	if (mazeData == NULL)
	{
		return nullptr;
	}
	else
	{
		int** tempMaze = new int* [mazeWidth];

		for (int i = 0; i < mazeWidth; ++i) {
			tempMaze[i] = new int[mazeHeight];
		}

		for (int i = 0; i < mazeWidth; i++) {
			for (int j = 0; j < mazeHeight; j++) {
				tempMaze[i][j] = mazeData[i][j];
			}
		}

		return tempMaze;
	}
}

__declspec(dllexport) bool GetNextPosition(int& xpos, int& ypos) {

	if (!isSetStarted)
	{
		times = 0;
		path = graph.AStar(graph, Vertex(startX, startY, 0, 0), Vertex(endX, endY, 0, 0), vertices, adjList);
		isSetStarted = true;

		for (int i = 0; i < mazeWidth; i++) {
			delete[] adjList[i];
		}
		delete[] adjList;
	}

	if (times < path.size()) {
		xpos = path[times].xPos;
		ypos = path[times].yPos;
		times++;
		return true;
	}
	else {
		return false;
	}
}

__declspec(dllexport) bool SetStart(int xpos, int ypos) {
	if (xpos < mazeWidth && ypos < mazeHeight && xpos >= 0 && ypos >= 0) {
		startX = xpos;
		startY = ypos;
		isSetStarted = false;

		return true;
	}
	else {
		return false;
	}
}

__declspec(dllexport) bool GetStart(int& xpos, int& ypos) {
	if (startX != NULL && startY != NULL) {
		xpos = startX;
		ypos = startY;
		return true;
	}
	else {
		return false;
	}
}

__declspec(dllexport) bool SetEnd(int xpos, int ypos) {
	if (xpos < mazeWidth && ypos < mazeHeight && xpos >= 0 && ypos >= 0) {
		endX = xpos;
		endY = ypos;
		isSetStarted = false;

		return true;
	}
}


__declspec(dllexport) bool GetEnd(int& xpos, int& ypos) {
	if (endX != NULL && endY != NULL) {
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
		times = 0;
	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}