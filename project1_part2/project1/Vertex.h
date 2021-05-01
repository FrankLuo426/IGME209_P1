#pragma once
class Vertex
{
public:
	int xPos;
	int yPos;
	int lowestCost;
	int heuristic;

	Vertex* previousVertex;
	
	Vertex();
	Vertex(int _xPos, int _yPos, int _heuristic, int _lowestCost);
	~Vertex();
};

