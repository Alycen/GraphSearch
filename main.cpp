
#include <iostream>
#include <fstream>
#include <string>

#include "Graph.h"

using namespace std;


typedef GraphArc<pair<string, int>, int> Arc;
typedef GraphNode<pair<string, int>, int> Node;
/*
void visit( Node * pNode ) {
	cout << "Visiting: " << pNode->data() << endl;
}*/

int main(int argc, int *argv[]) {
   
    Graph<pair<string, int>, int> graph( 6 );
	string stringArray[6];
	string tempString;
	std::vector<Node*> path;
	ifstream myfile;
	myfile.open ("Nodeys.txt");

	int infinite = INT_MAX;

	pair<string, int> temp;
	temp.second = infinite;

	int i = 0;
	while (!myfile.eof()) {
		getline(myfile, tempString);
		stringArray[i] = tempString;		
		temp.first = stringArray[i];
		graph.addNode(temp, i);
		i++;
	}

	myfile.close();
	myfile.open("Arcys.txt");

	int from, to, weight;
	while ( myfile >> from >> to >> weight ) {
		graph.addArc(from, to, weight);
	}
    myfile.close();

	graph.UniformCostSearch(graph.nodeArray()[0], graph.nodeArray()[5], path);

	// Now traverse the graph.
	//graph.breadthFirst( graph.nodeArray()[0], visit );

	//graph.breadthFirstSearch( graph.nodeArray()[0], visit, 15);
	//cout<< "Target is : 15" << endl;
	 // cout<< "Path is : "<< "\n" << target << endl;
	/*
	Node* temp = graph.nodeArray()[15];
	  while (temp->getPreviousPointer() != NULL ) {
		  cout << temp->getPreviousPointer()->data() << endl;
		  temp = temp->getPreviousPointer();
	  }*/
	system("PAUSE");
	
}



class NodeSearchCostComparer {
public:
	bool operator()(Node * n1, Node * n2) {
		pair<string, int> p1 = n1->data();
		pair<string, int> p2 = n2->data();
		return p1.second > p2.second; 
	}
};

