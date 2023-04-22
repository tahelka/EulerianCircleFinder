#include "DirectedGraph.h"

// Constructors

DirectedGraph::DirectedGraph(int n, int m) : Graph(n, m)
{
	getOutDegrees().resize(getNumberOfVertices());
	getInDegrees().resize(getNumberOfVertices());
}

// Setters

void DirectedGraph::setOutDegrees(std::vector<int>outDegrees)
{
	this->outDegrees = outDegrees;
}

void DirectedGraph::setInDegrees(std::vector<int> inDegrees)
{
	this->inDegrees = inDegrees;
}
// Getters

std::vector<int>& DirectedGraph::getOutDegrees()
{
	return outDegrees;
}

std::vector<int>& DirectedGraph::getInDegrees()
{
	return inDegrees;
}

// Methods

void DirectedGraph::addEdge(int vertex1, int vertex2)
{
	Graph::addEdge(vertex1, vertex2);
	updateVertiesDegree(vertex1, vertex2);
}

// Euler Methods

void DirectedGraph::updateVertiesDegree(int vertex1, int vertex2)
{
	getOutDegrees().at(vertex1)++;
	getInDegrees().at(vertex2)++;
}

bool DirectedGraph::isVertexOnBasicConditionForEulerGraph(int v)
{
	std::vector<AdjList*>& graph = Graph::getGraph();

	return getInDegrees().at(v) == getOutDegrees().at(v); // if out degree is equal to in degree

}

bool DirectedGraph::isConnectedOrStronglyConnectedGraphGeneral()
{
	bool res;
	if (Graph::isConnectedOrStronglyConnectedGraphXX())
	{
		DirectedGraph* gTranspose = createTransposeGraph();
		res = gTranspose->isConnectedOrStronglyConnectedGraphXX();

		delete gTranspose;
		return res;
	}
	return false;
}


DirectedGraph* DirectedGraph::createTransposeGraph()
{
	int numOfVertices = getNumberOfVertices(); // bc in ctor we add for dummy element
	DirectedGraph* gTranspose = new DirectedGraph(numOfVertices, getNumberOfEdges()); 
	std::vector<AdjList*>& graph = getGraph();
	std::list<Vertex>* neighborsList;
	

	for (int i = FIRST_VERTEX; i < numOfVertices; i++) // for each vertex
	{
		neighborsList = &(graph.at(i)->getNeighborsList());

		for (Vertex& v : *neighborsList) // for each neighbor of vertex
		{
			gTranspose->addEdge(v.getValue(), i);
		}
	}

	*(gTranspose->getColors().end() - 1) = (int)eColor::BLACK;
	return gTranspose;
}

