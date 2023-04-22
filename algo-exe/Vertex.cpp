#include "Vertex.h"

// Constructors
Vertex::Vertex(int value)
{
	setValue(value);
	setVisited(false);
}

// Setters
void Vertex::setValue(int value)
{
	this->value = value;
}

void Vertex::setVisited(bool visited)
{
	this->visited = visited;
}

void Vertex::setParallelEdge(Vertex* parallelEdge)
{
	this->parallelEdge = parallelEdge;
}

// Getters
int Vertex::getValue()
{
	return value;
}

bool Vertex::getVisited()
{
	return visited;
}

Vertex* Vertex::getParallelEdge() 
{
	return parallelEdge;
}

// Methods

// Euler Methods
void Vertex::markVertex()
{
	setVisited(true);
}