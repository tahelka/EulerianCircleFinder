#pragma once

class Vertex
{
	int value;
	bool visited;
	Vertex* parallelEdge = nullptr; // pointer to parallelEdge for undirected graph

public:
	// Constructors
	Vertex(int value);

	// Setters
	void setValue(int value);
	void setVisited(bool visited);
	void setParallelEdge(Vertex* parallelEdge);

	// Getters
	int getValue();
	bool getVisited();
	Vertex* getParallelEdge();

	// Methods

	// Euler Methods
	void markVertex();
};

