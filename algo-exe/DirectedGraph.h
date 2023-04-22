#pragma once
#include "Graph.h"

class DirectedGraph : public Graph
{
private:
	std::vector<int> outDegrees;
	std::vector<int> inDegrees;

public:
	// Constructors	
	DirectedGraph(int n, int m);

	// Setters
	// This method sets the out degrees of the vertices
	void setOutDegrees(std::vector<int> outDegree);
	// This method sets the in degrees of the vertices
	void setInDegrees(std::vector<int> inDegree);

	// Getters
	// This method returns the out degrees of the vertices
	std::vector<int>& getOutDegrees();
	// This method returns the in degrees of the vertices
	std::vector<int>& getInDegrees();

	// Methods
	// This method adds an edge between two vertices
	void addEdge(int vertex1, int vertex2);
	// This method creates a transpose graph
	DirectedGraph* createTransposeGraph();

	// Euler Methods
	// This method checks if the basic condition for Euler graph is satisfied
	bool isVertexOnBasicConditionForEulerGraph(int v);
	// This method updates the degrees of the vertices
	void updateVertiesDegree(int vertex1, int vertex2);
	// This method checks if the graph is connected or strongly connected
	bool isConnectedOrStronglyConnectedGraphGeneral();
};

