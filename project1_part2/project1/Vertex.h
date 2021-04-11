#pragma once
class Vertex
{
public:
	int xPos;
	int yPos;
	int lowesCost = INT_MAX;
	int heuristic;
	bool visited;

	Vertex* previousVertex;
	Vertex(int _xPos, int _yPos, bool _visited);
};

