#include "pch.h"
#include "Graph.h"

using namespace std;

void Graph::printVertices()
{
	for (int i = 0; i < vertices.size(); i++)
	{
		cout << "X-pos: " << vertices[i]->xPos << "Y-pos: " << vertices[i]->yPos << "Heuristic: " << vertices[i]->heuristic << endl;
	}
}

void Graph::printAjList()
{
	for (int i = 0; i < ajList.size(); i++)
	{
		for (int j = 0; j < ajList[i].size(); j++)
		{
			cout << "X-pos: " << ajList[i][j]->xPos << "Y-pos: " << ajList[i][j]->yPos << "Heuristic: " << ajList[i][j]->heuristic << endl;

		}
	}
}

void Graph::addVertices(Vertex* vertex)
{
	vertices.push_back(vertex);
}

void Graph::addEdge(Vertex* firstVertex, Vertex* secondVertex)
{
	//ajList[firstVertex.xPos][firstVertex.yPos].push_back(secondVertex);
	ajList[find(firstVertex)].push_back(secondVertex);
	ajList[find(secondVertex)].push_back(firstVertex);
}

int Graph::find(Vertex* vertex)
{
	for (size_t i = 0; i < vertices.size(); i++)
	{
		if (vertices[i] == vertex)
		{
			return i;
		}
	}
	return -1;
}




//A Star
void AStar()
{


}

//int heuristic(vertrix)
//{
//
//	dx = abs(node.x - goal.x)
//		dy = abs(node.y - goal.y)
//		return D * (dx + dy)
//}