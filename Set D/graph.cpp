#include <iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
public:
	Graph(int numVertices);
	void addEdge(int fromVertex, int toVertex);
	int countAllPaths(int startVertex, int endVertex);

private:
	int totalVertices;
	list<int>* adjacencyList;
	void pathCountingHelper(int startVertex, int endVertex, int& pathCount, vector<bool>& visitedNodes);
};

Graph::Graph(int numVertices) {
	totalVertices = numVertices;
	adjacencyList = new list<int>[numVertices];
}

void Graph::addEdge(int fromVertex, int toVertex) {
	adjacencyList[fromVertex].push_back(toVertex);
}

int Graph::countAllPaths(int startVertex, int endVertex) {
	int pathCount = 0;
	vector<bool> visitedNodes(totalVertices, false);
	pathCountingHelper(startVertex, endVertex, pathCount, visitedNodes);
	return pathCount;
}

void Graph::pathCountingHelper(int startVertex, int endVertex, int& pathCount, vector<bool>& visitedNodes) {
	visitedNodes[startVertex] = true;
	if (startVertex == endVertex) {
		pathCount++;
	} else {
		for (auto neighbor : adjacencyList[startVertex]) {
			if (!visitedNodes[neighbor]) {
				pathCountingHelper(neighbor, endVertex, pathCount, visitedNodes);
			}
		}
	}
	visitedNodes[startVertex] = false;
}

int main() {
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 4);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 4);
	g.addEdge(3, 2);
	

	cout << g.countAllPaths(0, 4);

	return 0;
}
