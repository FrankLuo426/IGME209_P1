#include "pch.h"
#include "Vertex.h"

Vertex::Vertex() {}

Vertex::Vertex(int _xPos, int _yPos, int _heuristic, int _lowestCost, int _weight)
{
	xPos = _xPos;
	yPos = _yPos;
	heuristic = _heuristic;
	lowestCost = _lowestCost;
	weight = _weight;
}

Vertex::~Vertex() {};
