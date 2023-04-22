#include "Interaction.h"

Graph* Interaction::buildGraphFromUser()
{
	Graph* graphFromUser;
	char isGraphDirected;
	int n; // numOfVertices
	int m; // numOfEdges

	std::cout << "Is the graph directed : y/n" << std::endl;
	std::cin >> isGraphDirected;
	std::cin >> n;
	std::cin >> m;

	if (n < 0 || m < 0) // check if valid
	{
		std::cout << "invalid input" << std::endl;
		exit(0);
	}

	if (isGraphDirected == 'y')
	{
		graphFromUser = new DirectedGraph(n, m);
	}
	else if (isGraphDirected == 'n') // is not directed
	{
		graphFromUser = new UndirectedGraph(n, m);
	}
	else 
	{
		std::cout << "invalid input" << std::endl;
		exit(0);
	}


	graphFromUser->addEdgesFromUser(m);

	graphFromUser->updateAllNextUnvisitedVertices();
	
	return graphFromUser;
}
