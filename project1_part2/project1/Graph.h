#pragma once
#include <vector>
#include "Vertex.h"

class Graph
{
public:
	vector<Vertex*> vertices;
	vector<vector<Vertex*>> ajList;
	void printVertices();
	void printAjList();
	void addVertices(Vertex* vertex);
	void addEdge(Vertex* firstVertex, Vertex* secondVertex);
	int find(Vertex* vertex);
};

