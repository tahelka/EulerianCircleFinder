#include "AdjList.h"

// Setters
void AdjList::setNeighborsList(const std::list<Vertex>& neighborsList) {
    this->neighborsList = neighborsList;
}

void AdjList::setNextUnvisitedVertex(std::list<Vertex>::iterator nextUnvisitedVertex) 
{
    this->nextUnvisitedVertex = nextUnvisitedVertex;
}

// Getters

std::list<Vertex>& AdjList::getNeighborsList()
{
    return neighborsList;
}

// Methods

// Euler Methods
std::list<Vertex>::iterator AdjList::getNextUnvisitedVertex()
{
    return nextUnvisitedVertex;
}
