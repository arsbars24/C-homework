#include <iostream>
#include <vector>
#include <map>
#include <list>

class Graph {
private:
	int graphSize;
	std::vector<int> nodeArray;
	std::vector<int> edge1Array;
	std::vector<int> edge2Array;
	void addEdge(int node1, int node2);
	void deleteEdge(int node1, int node2);
public:
	void addNode(int node);
	void addUEdge(int node1, int node2);
	int connectedComponents(void);
	int checkNode(int node);
	int checkEdge(int node1, int node2);
	void deleteNode(int node);
	void deleteUEdge(int node1, int node2);
	void printNodeList(void);
	Graph(int size); //Constructor of the class
};

Graph::Graph(int size) {
	graphSize = size;
}

void Graph::addNode(int node) {
	nodeArray.push_back(node);
	std::cout << "adding node" << std::endl;
}

void Graph::addEdge(int node1, int node2) {
	edge1Array.push_back(node1);
	edge2Array.push_back(node2);
	std::cout << "adding edge" << node1 << node2 << "\n";
}
void Graph::addUEdge(int node1, int node2) {
	addEdge(node1, node2);
	addEdge(node2, node1);
}

int Graph::checkNode(int node) {
	/*
	Checks the node
	Returns 1 if the node is found 0 otherwise
	*/

	for (int i = 0; i < nodeArray.size(); i++) {
		if (nodeArray[i] == node) {
			std::cout << "The node exists\n";
			return 1;
		}
	}
	return 0;
}
int Graph::checkEdge(int node1, int node2) {
	/*
	Checks the edge (node1,node2)
	Returns 1 if the edge is found 0 otherwise
	*/
	for (int i = 0; i < edge1Array.size(); i++) {
		if (edge1Array[i] == node1 && edge2Array[i] == node2) {
			return 1;
		}
	}
	return 0;
}

void Graph::deleteNode(int node) {
	/*
	Deletes the node from the nodeArray
	*/
	int out;
	out = checkNode(node);
	if (out == 1) {
		int count = 0;
		//find the node and delete it
		//Using an iterator to go through the vector
		for (std::vector<int>::const_iterator i = nodeArray.begin(); i != (nodeArray.end()); i++) {
			if (*i == node) {
				nodeArray.erase(nodeArray.begin() + count);
			}
			count++;
		}

	}
	else {
	}
}

void Graph::printNodeList(void) {
	/*
	Prints the node list
	*/
	for (std::vector<int>::const_iterator i = nodeArray.begin(); i != (nodeArray.end()); i++) {
		std::cout << "Node :" << (*i) << std::endl;
	}
}

void Graph::deleteUEdge(int node1, int node2) {
	/*
	Delete the edge (node1, node2)
	(node2, node1)
	*/
	deleteEdge(node1, node2);
	deleteEdge(node2, node1);
}

void Graph::deleteEdge(int node1, int node2) {
	/*
	Deletes the edge (node1, node2)
	If the edge does not exist, then nothing is done.
	*/

	int out;
	out = checkEdge(node1, node2);
	if (out == 1) { //The edge exists
		int count = 0;
		//find the node and delete it
		//Using an iterator to go through the vector
		for (std::vector<int>::const_iterator i = edge1Array.begin(); i != (edge1Array.end()); i++) {
			if (*((edge1Array.begin() + count)) == node1 && *((edge1Array.begin() + count)) == node2) {
				edge1Array.erase(edge1Array.begin() + count);
				edge2Array.erase(edge2Array.begin() + count);
			}
			count++;
		}

	}
	else { //The edge does not exist. Dont do anything.
	}
}

int Graph::connectedComponents(void) {
	/*
	Computes the connected compoonents of the UNDIRECTED graph
	stores the components in an map :(node, component_number)
	private data: connected_components
	Suggestion: Maybe this is the update function!
	And we need another function that can access the connected components and give it
	to you
	*/


	//Create an adjacency list
	std::map< int, std::vector<int> > adjacency_list;
	int count = 0;
	//Go through the edge list and create the adjacency list
	for (std::vector<int>::const_iterator i = edge1Array.begin(); i != (edge1Array.end()); i++) {
		adjacency_list[edge1Array[count]].push_back(edge2Array[count]);
		count++;
	}
	// print the connected components
	for (std::map< int, std::vector<int> >::iterator it = adjacency_list.begin(); it != adjacency_list.end(); it++) {
		std::vector<int> value_list = it->second;
		for (int i = 0; i < value_list.size(); i++) {
		}
	}

	// Create a map from node to components
	std::map<int, int> component_number;
	count = 0;
	for (int k = 0; k < nodeArray.size(); k++) {
		if (component_number.find(count) == component_number.end()) {
			//if not assigned a component_number - start a BFS
			int node = nodeArray[k];
			int original_node = node;
			std::vector<int> first_nodes = adjacency_list[node];
			for (int i = 0; i < first_nodes.size(); i++) {
			}
			while (!first_nodes.empty()) {
				int curr_node = first_nodes.back();
				first_nodes.pop_back();
				if (component_number.find(curr_node) == component_number.end()) {
					//If current node is not assigned a component number
					component_number[curr_node] = original_node;
					std::vector<int> curr_node_list = adjacency_list[curr_node];
					for (int l = 0; l < curr_node_list.size(); l++) {
					}
					int node_list_len = curr_node_list.size();
					for (int j = 0; j < node_list_len; j++) {
						first_nodes.push_back(curr_node_list.back());
						curr_node_list.pop_back();
					}

				}

			}

		}
		else {
			//The node is assigned a component number

		}
		count++;
	}
	std::cout << "\n\nConnected Components\n";
	for (int l = 0; l < nodeArray.size(); l++) {
		int node = nodeArray[l];
		std::cout << "node is:" << node << "  connected_component:" << component_number[node] << std::endl;

	}
	return 1;
}

int main() {
	using namespace std;
	int count;
	Graph firstGraph(10);

	firstGraph.addNode(1);

	firstGraph.addNode(2);
	firstGraph.addNode(3);
	firstGraph.addNode(4);
	firstGraph.addNode(5);
	firstGraph.addNode(6);
	firstGraph.addNode(7);
	firstGraph.addNode(8);
	firstGraph.addNode(9);
	firstGraph.addNode(10);
	firstGraph.addNode(11);

	// firstGraph.addUEdge(1,2);
	firstGraph.addUEdge(1, 3);
	firstGraph.addUEdge(2, 4);
	firstGraph.addUEdge(2, 5);
	firstGraph.addUEdge(6, 7);
	firstGraph.addUEdge(7, 8);
	// firstGraph.addUEdge(8,9);
	firstGraph.addUEdge(9, 10);
	firstGraph.addUEdge(10, 11);


	// firstGraph.addUEdge(3,4);

	// firstGraph.deleteEdge(1,3);
	firstGraph.deleteUEdge(1, 100);
	firstGraph.checkNode(1);

	firstGraph.checkNode(2);
	firstGraph.checkEdge(1, 2);
	firstGraph.checkEdge(1, 3);
	firstGraph.checkEdge(2, 4);

	// firstGraph.deleteNode(1);
	firstGraph.checkNode(1);
	firstGraph.printNodeList();
	firstGraph.deleteNode(100);
	cout << "\n\n\nDONE!!!" << endl;

	count = firstGraph.connectedComponents();
	return 0;
}


// write a dijkstra 
// write priority_queue