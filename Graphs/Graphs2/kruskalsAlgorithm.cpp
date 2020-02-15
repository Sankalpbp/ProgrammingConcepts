# include <iostream>
# include <algorithm>
using namespace std;

class Edge {
		
	public:
		int source;
		int destination;
		int weight;
};

bool compare(Edge e1, Edge e2) {
	
	return e1.weight < e2.weight;
}

int getParent(int vertex, int *parent) {
	
	if(parent[vertex] == vertex) {
		return vertex;
	}

	return getParent(parent[vertex], parent);
}

Edge * kruskals(Edge *e, int vertices, int edges) {
		
	// sort the edges array in increasing order
	sort(e, e + edges, compare);

	// we will return this as an output
	Edge *output = new Edge[vertices - 1];

	// we will maintain a parent matrix to have a way to check the connected component
	int *parent = new int[vertices];
	for(int i = 0; i < vertices; i++) {
		parent[i] = i;
	}

	int count = 0;
	int i = 0;

	while(count < vertices - 1) {
		
		// check the topmost parent of v1 and v2, where v1 and v2 are neighbors of current edge
		Edge currentEdge = e[i];
		int sourceParent = getParent(currentEdge.source, parent);
		int destinationParent = getParent(currentEdge.destination, parent);

		if(sourceParent != destinationParent) {
			output[count] = currentEdge;
			count++;
			parent[sourceParent] = destinationParent;
		}
		i++;
	}

	return output;
}

int main(void) {
		
	int vertices, edges;
	cin >> vertices >> edges;

	Edge *e = new Edge[edges];

	for(int i = 0; i < edges; i++) {
		cin >> e[i].source;
		cin >> e[i].destination;
		cin >> e[i].weight;
	}

	Edge *output = kruskals(e, vertices, edges);

	for(int i = 0; i < vertices - 1; i++) {
		if(output[i].source < output[i].destination) {
			cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
		} else {
			cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
		}
	}

	cout << endl << endl;

	return 0;
}
