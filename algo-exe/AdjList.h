#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Vertex.h"

class AdjList
{
private:
	std::list<Vertex> neighborsList;
	std::list<Vertex>::iterator nextUnvisitedVertex;

public:
    // Setters
    // This method sets the neighbors list of the vertex
    void setNeighborsList(const std::list<Vertex>& neighborsList);
    // This method sets the next unvisited vertex of the vertex
    void setNextUnvisitedVertex(std::list<Vertex>::iterator nextUnvisitedVertex);

    // Getters
    // This method returns the neighbors list of the vertex
    std::list<Vertex>& getNeighborsList();
    
    // Methods

    // Euler Methods
    // This method returns the next unvisited vertex of the vertex
    std::list<Vertex>::iterator getNextUnvisitedVertex();
};

