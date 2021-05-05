#include "pch.h"
#include "Graph.h"
#include <list>
#include <algorithm>

Graph::Graph() {}

Graph::Graph(vector<Vertex> _vertices, int** _adjList, int _xMax, int _yMax)
{
	vertices = _vertices;
	adjList = _adjList;
	xMax = _xMax;
	yMax = _yMax;
}

Graph::~Graph() {}

vector<Vertex> Graph::checkNearby(Vertex currentVertex, vector<Vertex> vertices, int** adjList)
{
	vector<Vertex> nearbyList;

	if (currentVertex.xPos + 1 < xMax) {
		if (adjList[currentVertex.xPos + 1][currentVertex.yPos] > 0)
		{
			int x = currentVertex.xPos + 1;
			int y = currentVertex.yPos;
			auto iter = find_if(vertices.begin(), vertices.end(), [&x, &y](const Vertex& vertex) {return vertex.xPos == x && vertex.yPos == y; });

			if (iter != vertices.end())
			{
				auto index = distance(vertices.begin(), iter);
				nearbyList.push_back(vertices[index]);
			}
		}
	}

	if (currentVertex.xPos - 1 >= 0) {
		if (adjList[currentVertex.xPos - 1][currentVertex.yPos] > 0)
		{
			int x = currentVertex.xPos - 1;
			int y = currentVertex.yPos;
			auto iter = find_if(vertices.begin(), vertices.end(), [&x, &y](const Vertex& vertex) {return vertex.xPos == x && vertex.yPos == y; });

			if (iter != vertices.end())
			{
				auto index = distance(vertices.begin(), iter);
				nearbyList.push_back(vertices[index]);
			}
		}
	}

	if (currentVertex.yPos + 1 < yMax) {
		if (adjList[currentVertex.xPos][currentVertex.yPos + 1] > 0)
		{
			int x = currentVertex.xPos;
			int y = currentVertex.yPos + 1;
			auto iter = find_if(vertices.begin(), vertices.end(), [&x, &y](const Vertex& vertex) {return vertex.xPos == x && vertex.yPos == y; });

			if (iter != vertices.end())
			{
				auto index = distance(vertices.begin(), iter);
				nearbyList.push_back(vertices[index]);
			}
		}
	}

	if (currentVertex.yPos - 1 >= 0) {
		if (adjList[currentVertex.xPos][currentVertex.yPos - 1] > 0)
		{
			int x = currentVertex.xPos;
			int y = currentVertex.yPos - 1;
			auto iter = find_if(vertices.begin(), vertices.end(), [&x, &y](const Vertex& vertex) {return vertex.xPos == x && vertex.yPos == y; });

			if (iter != vertices.end())
			{
				auto index = distance(vertices.begin(), iter);
				nearbyList.push_back(vertices[index]);
			}
		}
	}

	return nearbyList;
}

int Graph::heuristic(Vertex startVertex, Vertex endVertex) {
	int dx = abs(startVertex.xPos - endVertex.xPos);
	int dy = abs(startVertex.yPos - endVertex.yPos);
	int d = dx + dy;
	return d;
}

bool compareDistance(Vertex vertex1, Vertex vertex2)
{
	return (vertex1.lowestCost < vertex2.lowestCost);
}

//A Star
vector<Vertex> Graph::AStar(Graph graph, Vertex startVertex, Vertex endVertex, vector<Vertex> vertices, int** adjList)
{
	vector<Vertex> open_set;
	vector<Vertex> close_set;

	startVertex.heuristic = heuristic(startVertex, endVertex);
	open_set.push_back(startVertex);

	while (open_set.size() > 0) {
		sort(open_set.begin(), open_set.end(), compareDistance);

		Vertex currentVertex = open_set[0];
		open_set.erase(open_set.begin());

		close_set.push_back(currentVertex);

		//Check if is reach the end
		if (currentVertex.xPos == endVertex.xPos && currentVertex.yPos == endVertex.yPos)
		{
			auto iter = find_if(vertices.begin(), vertices.end(), [currentVertex](const Vertex& vertex) {return vertex.xPos == currentVertex.xPos && vertex.yPos == currentVertex.yPos; });
			auto index = distance(vertices.begin(), iter);

			while (vertices[index].previousVertex != NULL) {

				graph.path.insert(graph.path.begin(), vertices[index]);
				vertices[index] = *vertices[index].previousVertex;
			}

			return graph.path;
		}

		vector<Vertex> nearbyList = graph.checkNearby(currentVertex, vertices, adjList);

		for (int i = 0; i < nearbyList.size(); i++)
		{
			Vertex nearbyVertex = nearbyList[i];
			nearbyVertex.lowestCost = heuristic(startVertex, currentVertex) + heuristic(currentVertex, nearbyVertex) + heuristic(nearbyVertex, endVertex);
		}

		sort(nearbyList.begin(), nearbyList.end(), compareDistance);

		Vertex holdCurrentVertex = currentVertex;

		for (int i = 0; i < nearbyList.size(); i++)
		{
			Vertex nearbyVertex = nearbyList[i];
			int cost = heuristic(startVertex, currentVertex) + heuristic(currentVertex, nearbyVertex) + nearbyVertex.weight;
			int x = nearbyVertex.xPos;
			int y = nearbyVertex.yPos;

			auto iter = find_if(open_set.begin(), open_set.end(), [&x, &y](const Vertex& vertex) {return vertex.xPos == x && vertex.yPos == y; });

			bool found;

			if (iter != open_set.end()) {
				found = true;
			}
			else {
				found = false;
			}

			if (found && cost < heuristic(startVertex, nearbyVertex))
			{
				open_set.erase(iter);
			}

			bool cFound;
			auto citer = find_if(close_set.begin(), close_set.end(), [&x, &y](const Vertex& vertex) {return vertex.xPos == x && vertex.yPos == y; });
			if (citer != close_set.end()) {
				cFound = true;
			}
			else {
				cFound = false;
			}

			if (cFound && cost < heuristic(startVertex, nearbyVertex))
			{
				close_set.erase(citer);
			}

			iter = find_if(open_set.begin(), open_set.end(), [&x, &y](const Vertex& vertex) {return vertex.xPos == x && vertex.yPos == y; });
			citer = find_if(close_set.begin(), close_set.end(), [&x, &y](const Vertex& vertex) {return vertex.xPos == x && vertex.yPos == y; });
			if (iter != open_set.end()) {
				found = true;
			}
			else {
				found = false;
			}

			if (citer != close_set.end()) {
				cFound = true;
			}
			else {
				cFound = false;
			}

			if (!found && !cFound) {
				nearbyVertex.lowestCost = cost + heuristic(nearbyVertex, endVertex);
				open_set.push_back(nearbyVertex);
				auto hiter = find_if(vertices.begin(), vertices.end(), [holdCurrentVertex](const Vertex& vertex) {return vertex.xPos == holdCurrentVertex.xPos && vertex.yPos == holdCurrentVertex.yPos; });
				auto viter = find_if(vertices.begin(), vertices.end(), [nearbyVertex](const Vertex& vertex) {return vertex.xPos == nearbyVertex.xPos && vertex.yPos == nearbyVertex.yPos; });

				if (hiter != vertices.end())
				{
					auto pIndex = distance(vertices.begin(), hiter);
					auto vIndex = distance(vertices.begin(), viter);

					vertices[vIndex].previousVertex = &vertices[pIndex];
				}
				currentVertex = nearbyVertex;
			}
		}
	}
	vector<Vertex> nullPath;
	return nullPath;
}

