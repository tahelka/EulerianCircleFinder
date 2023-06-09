// This program finds an Euler circle in a graph if it exists 
// (the graph can be directed or undirected, depending on the user's choice - y if directed, or no if undirected).
// Then, the program asks the user for the number of vertices in the graph (n), then for the number of edges (m), 
// and then for the edges themselves (a sequence of pairs of vertices {1, ... , n}).

#include "Interaction.h"

int main()
{	
	try
	{
		Graph* graph = Interaction::buildGraphFromUser();
		graph->printEulerCircleIfExist();
		delete graph;	
	}
	catch (...) 
	{
		std::cout << "invalid input" << std::endl;
	}

}