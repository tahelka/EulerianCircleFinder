#include "UndirectedGraph.h"

// Methods

void UndirectedGraph::addEdge(int vertex1, int vertex2)
{
	std::vector<AdjList*>& graph = getGraph();

	Graph::addEdge(vertex1, vertex2);
	Graph::addEdge(vertex2, vertex1);

	// setting pointers to parallelEdge for undirected graph
	Vertex* v1, * v2;
	v2 = &(graph.at(vertex1)->getNeighborsList().back());
	v1 = &(graph.at(vertex2)->getNeighborsList().back());

	v1->setParallelEdge(v2);
	v2->setParallelEdge(v1);

}

void UndirectedGraph::markEdge(Vertex* v)
{
	Graph::markEdge(v);
	v->getParallelEdge()->markVertex();
}

int UndirectedGraph::getVertexDegree(int v)
{
	return getGraph().at(v)->getNeighborsList().size();
}

// Euler Methods

bool UndirectedGraph::isVertexOnBasicConditionForEulerGraph(int v)
{
	return getGraph().at(v)->getNeighborsList().size() % 2 == 0; // even
}