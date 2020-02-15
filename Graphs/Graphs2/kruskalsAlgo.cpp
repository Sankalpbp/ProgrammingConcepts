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

int getParent(int *parent, int vertex) {
		
	// when we get parent[i] == i to be true, that is our topmost parent
	if(parent[vertex] == vertex) {
		return vertex;
	}

	int smallOutput = getParent(parent, parent[vertex]);
	return smallOutput;
}

Edge* kruskals(Edge *arr, int vertices, int edges) {
	
	// sort the edges array in increasing order
	sort(arr, arr + edges, compare);

	Edge *output = new Edge[vertices - 1];

	int *parent = new int[vertices];
	for(int i = 0; i < vertices; i++) {
		parent[i] = i;
	}

	int count = 0;

	int i = 0;
	while(count < vertices - 1) {
		// check the topmost parent of v1 and v2, v1 and v2 are vertices of current edge
		Edge currentEdge = arr[i];
		int sourceParent = getParent(parent, arr[i].source);
		int destinationParent = getParent(parent, arr[i].destination);

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

	Edge *arr = new Edge[edges];
	for(int i = 0; i < edges; i++) {
		cin >> arr[i].source;
		cin >> arr[i].destination;
		cin >> arr[i].weight;
	}

	Edge *output = kruskals(arr, vertices, edges);

	for(int i = 0; i < vertices - 1; i++) {
		if(output[i].source <= output[i].destination) {
			cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
		} else {
			cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
		}
	}

	cout << endl << endl;

	return 0;
}
