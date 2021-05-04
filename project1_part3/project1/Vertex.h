#pragma once
class Vertex
{
public:
	int xPos;
	int yPos;
	int lowestCost;
	int heuristic;
	int weight;

	Vertex* previousVertex;
	
	Vertex();
	Vertex(int _xPos, int _yPos, int _heuristic, int _lowestCost, int _weight);
	~Vertex();
};

