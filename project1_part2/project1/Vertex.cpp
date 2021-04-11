#include "pch.h"
#include "Vertex.h"

Vertex::Vertex(int _xPos, int _yPos, bool _visited)
{
    xPos = _xPos;
    yPos = _yPos;
    visited = _visited;
    heuristic = 0;
    lowesCost = INT_MAX;
}
