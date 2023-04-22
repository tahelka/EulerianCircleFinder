#include "Graph.h"

// Constructors

Graph::Graph(int n, int m)
{
	setNumberOfVertices(n + 1); // plus one for dummy element so vertex 1 will be at place 1 in the vector
	setNumberOfEdges(m);
	InitVerticesVector(getNumberOfVertices());
	getColors().resize(getNumberOfVertices());
	getColors().at(0) = (int)eColor::BLACK;
}

Graph::~Graph()
{
	for (int i = 0; i < getNumberOfVertices(); i++)
	{
		delete getGraph().at(i);
	}
}

void Graph::InitVerticesVector(int numOfVertices)
{
	std::vector<AdjList*>& graph = getGraph();
	for (int i = 0; i < numOfVertices; i++)
	{
		graph.push_back(new AdjList());
	}
}

// Setters
void Graph::setNumberOfVertices(int n)
{
	this->n = n;
}

void Graph::setNumberOfEdges(int m)
{
	this->m = m;
}

void Graph::setGraph(std::vector<AdjList*>& vertices)
{
	this->graph = vertices;
}

// Getters
int Graph::getNumberOfVertices()
{
	return n;
}

int Graph::getNumberOfEdges()
{
	return m;
}

std::vector<AdjList*>& Graph::getGraph()
{
	return graph;
}

std::vector<int>& Graph::getColors()
{
	return colors;
}

// Methods

void Graph::addEdge(int vertex1, int vertex2)
{
	getGraph().at(vertex1)->getNeighborsList().push_back(vertex2);
}

void Graph::addEdgesFromUser(int numOfEdges)
{
	int v1, v2;
	for (int i = 0; i < numOfEdges; i++)
	{
		std::cin >> v1 >> v2;
		addEdge(v1, v2);
	}
}

void Graph::updateAllNextUnvisitedVertices()
{
	std::vector<AdjList*>& graph = getGraph();
	int numOfVertices = getNumberOfVertices();

	for (int i = FIRST_VERTEX; i < numOfVertices; i++)
	{
		if (!(graph.at(i)->getNeighborsList().empty())) // if list is not empty
		{
			graph.at(i)->setNextUnvisitedVertex(graph.at(i)->getNeighborsList().begin()); // update next unvisited vertex
		}
	}
}

// Euler Methods

bool Graph::isConnectedOrStronglyConnectedGraphXX()
{

	std::vector<int>::iterator itrG = colors.begin();
	std::vector<int>::iterator itrEndG = colors.end();

	std::fill(colors.begin() + 1, colors.end(), (int)eColor::WHITE); // initialize colors

	this->visit(FIRST_VERTEX);

	return checkColors();
}

void Graph::visit(int vertex)
{
	std::vector<AdjList*>& graph = getGraph();

	getColors().at(vertex) = (int)eColor::GRAY;

	std::list<Vertex>* neighborsList = &(graph.at(vertex)->getNeighborsList());

	for (Vertex v : *neighborsList)
	{
		if(getColors().at(v.getValue()) == (int)eColor::WHITE) // if the vertex is not visited
		{
			visit(v.getValue());
		}
	}

	getColors().at(vertex) = (int)eColor::BLACK;
}


bool Graph::checkColors()
{
	std::vector<int>::iterator itr = colors.begin(); // bc of the dummpy element
	std::advance(itr, FIRST_VERTEX);

	for (; itr != colors.end(); ++itr) 
	{
		if (*itr != (int)eColor::BLACK) // if there is a vertex that is not visited
		{
			return false;
		}
	}

	return true;
}

// Euler Methods:

void Graph::printEulerCircleIfExist()
{
	std::list<int>* eulerCircle = findEulerCircle();

	if (eulerCircle == nullptr ||(eulerCircle != nullptr && eulerCircle->empty())) // this graph is not an Euler graph
	{
		std::cout << "The graph is not aulerian" << std::endl;
	}
	else 
	{
		std::cout << "The graph is aulerian" << std::endl;
		printEulerCircle(eulerCircle);
		delete eulerCircle;
	}
}

std::list<int>* Graph::findEulerCircle()
{
	std::list<int>* eulerCircle = nullptr;

	// if the graph is Eulerian
	if (isConnectedOrStronglyConnectedGraphXX() && AreVerticesOnBasicConditionForEulerGraph()) // if the graph is connected and all vertices have even degree
	{
		eulerCircle = Euler();
		if (eulerCircle->front() != eulerCircle->back())
		{
			return nullptr;
		}
	}

	return eulerCircle;
}

std::list<int>* Graph::findCircuit(int vertex)
{
	std::vector<AdjList*>& graph = getGraph();
	std::list<int>* L = new std::list<int>();
	int v = vertex, itrVal;
	std::list<Vertex>::iterator itr;

	L->push_back(v);
	settingTheNextUnvisitedVertex(v);

	while ((itr = graph.at(v)->getNextUnvisitedVertex()) != graph.at(v)->getNeighborsList().end()) // while there is an unvisited vertex
	{
		markEdge(&*itr);
		itrVal = itr->getValue();
		L->push_back(itrVal);
		v = itrVal;
		settingTheNextUnvisitedVertex(v);

	}

	return L;
}

void Graph::settingTheNextUnvisitedVertex(int v)
{
	std::vector<AdjList*>& graph = getGraph();
	std::list<Vertex>::iterator itr = graph.at(v)->getNextUnvisitedVertex();

	while(itr != (graph.at(v)->getNeighborsList().end()) && itr->getVisited() == true)
	{
		std::advance(itr, 1); // next one
	}

	graph.at(v)->setNextUnvisitedVertex(itr);
}

void Graph::markEdge(Vertex* v)
{
	v->markVertex();
}

std::list<int>* Graph::Euler()
{
	std::list<int>* L = findCircuit(FIRST_VERTEX), *L1;
	std::list<int>::iterator* itr, *currItr;

	while ((itr = findVertexWithUnusedEdgeInList(L)) != nullptr) // while there is a vertex with an unused edge
	{
		L1 = findCircuit(**itr);
		L->splice(*itr, *L1, L1->begin(), L1->end());
		delete L1;
		//settingTheNextUnvisitedVertex(**itr);
		L->erase(*itr);
		delete itr;

	}
	
	return L;
}


std::list<int>::iterator* Graph::findVertexWithUnusedEdgeInList(std::list<int>* L)
{
	std::vector<AdjList*>& graph = getGraph();

	std::list<int>::iterator itr;

	for (itr = L->begin(); itr != L->end(); ++itr) { 
		settingTheNextUnvisitedVertex(*itr);
		if (graph.at(*itr)->getNextUnvisitedVertex() != graph.at(*itr)->getNeighborsList().end())
		{
			return new std::list<int>::iterator(itr);
		}
	}

	return nullptr;
}

bool Graph::AreVerticesOnBasicConditionForEulerGraph()
{
	int numOfVertices = getNumberOfVertices();

	for (int i = FIRST_VERTEX; i < numOfVertices; i++) 
	{
		if (isVertexOnBasicConditionForEulerGraph(i) == false)
		{
			return false;
		}
	}

	return true;
}

void Graph::printEulerCircle(std::list<int>* eulerCircle)
{
	std::list<int>::iterator itr;

	std::cout << "(";

	for (itr = eulerCircle->begin(); itr != eulerCircle->end(); ++itr) 
	{
		if (itr == eulerCircle->begin())
		{
			std::cout << *itr;
		}
		else
		{
			std::cout << "," << *itr;
		}
	}
	std::cout << ")" << std::endl;

}