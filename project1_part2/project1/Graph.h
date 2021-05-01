#pragma once
#include <vector>
#include "Vertex.h"

class Graph
{
public:
	int xMax;
	int yMax;
	int** adjList;

	vector<Vertex> vertices;
	vector<Vertex> path;

	Graph();
	Graph(vector<Vertex> _vertices, int** _adjList, int _xMax, int _yMax);
	~Graph();

	int heuristic(Vertex startVertex, Vertex endVertex);
	vector<Vertex> checkNearby(Vertex currentVertex, vector<Vertex> vertices, int** adjList);
	vector<Vertex> AStar(Graph graph, Vertex startVertex, Vertex endVertex, vector<Vertex> vertices, int** adjList);
};

