#pragma once
#include <iostream>
#pragma warning (disable: 4996)
#include <vector>
#include <list>
#include "Vertex.h"
#include "AdjList.h"

enum class eColor{ WHITE, GRAY, BLACK};
constexpr int FIRST_VERTEX = 1;

class Graph 
{
private: 
	std::vector<AdjList*> graph;
	std::vector<int> colors;
	int n; // numOfVertices
	int m; // numOfEdges

public:
	// Constructors
	Graph(int n, int m);
	// Destructor
	~Graph();

	// Setters
	// This method sets the number of vertices in the graph
	void setNumberOfVertices(int n);
	// This method sets the number of edges in the graph
	void setNumberOfEdges(int m);
	// This method sets the graph
	void setGraph(std::vector<AdjList*>& graph);

	// Getters
	// This method returns the number of vertices in the graph
	int getNumberOfVertices();
	// This method returns the number of edges in the graph
	int getNumberOfEdges();
	// This method returns the graph
	std::vector<AdjList*>& getGraph();
	// This method returns the colors of the vertices in the graph
	std::vector<int>& getColors();

	// Methods
	// This method initializes the vertices vector
	void InitVerticesVector(int numOfVertices);

	// This method checks if the graph is connected or strongly connected
	virtual bool isConnectedOrStronglyConnectedGraphXX();
	// This method adds an edge to the graph
	virtual void addEdge(int vertex1, int vertex2);
	// This method gets edges to the graph from the user
	void addEdgesFromUser(int numOfEdges);
	// This methods returns the next unvisited vertex
	void settingTheNextUnvisitedVertex(int v);


	// Euler Methods
	// This method visits a vertex
	void visit(int vertex);
	// This method checks the colors of the vertices in the graph
	bool checkColors();
	// This methods finds an Euler circuit in the graph
	std::list<int>* findEulerCircle();
	// This method marks an edge
	virtual void markEdge(Vertex* v);
	// This method finds an unused edge in the list
	std::list<int>::iterator* findVertexWithUnusedEdgeInList(std::list<int>* L);
	// This method returns the euler circuit
	std::list<int>* Euler();
	// This method checks the basic condition for Eulerian graph
	virtual bool isVertexOnBasicConditionForEulerGraph(int v) = 0;
	// This method checks the basic condition for Eulerian graph for all vertices are met 
	bool AreVerticesOnBasicConditionForEulerGraph();
	// This method checks if the graph is Eulerian and prints the circle if it is
	void printEulerCircleIfExist();
	// This method updates all the next unvisited vertices
	void updateAllNextUnvisitedVertices();
	// This method gets the next unvisited vertex
	std::list<Vertex>::iterator gettingTheNextUnvisitedVertex();

private:
	// This method prints the Euler circle
	void printEulerCircle(std::list<int>* eulerCircle);
	// This method finds an Euler circuit in the graph
	std::list<int>* findCircuit(int vertex);
};
