#pragma once
#include "Graph.h"

class UndirectedGraph : public Graph
{
public:

	// Constructors
	UndirectedGraph(int n, int m) : Graph(n, m) {};

	// Methods
	// This method adds an edge between two vertices to the graph
	void addEdge(int vertex1, int vertex2);
	// This method marks an edge between two vertices
	void markEdge(Vertex* v);
	// This method returns the degree of a vertex
	int getVertexDegree(int v);

	// Euler Methods
	// This method checks if the basic condition for an Euler graph is met
	bool isVertexOnBasicConditionForEulerGraph(int v);

};

