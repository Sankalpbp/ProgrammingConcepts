# include <iostream>
# include <climits>
using namespace std;

int getMinVertex(bool *visited, int *weight, int vertices) {
		
	int minVertex = -1;

	for(int i = 0; i < vertices; i++) {
		if(visited[i] == false && ((minVertex == -1) || weight[minVertex] > weight[i])) {
			minVertex = i;
		}
	}

	return minVertex;
}

void prims(int **edges, int vertices) {
		
	bool *visited = new bool[vertices]();
	int *parent = new int[vertices];
	
	int *weight = new int[vertices];

	for(int i = 0; i < vertices; i++) {
		weight[i] = INT_MAX;
	}

	parent[0] = -1;
	weight[0] = 0;

	for(int i = 0; i < vertices - 1; i++) {
		
		// get minVertex i.e. unvisited vertex with minimum weight
		int minVertex = getMinVertex(visited, weight, vertices);
		visited[minVertex] = true;

		// explore all the neighbors of minVertex and update parent and weight array accordingly

		for(int j = 0; j < vertices; j++) {
			if(edges[minVertex][j] != 0 && visited[j] == false) {
				if(weight[j] > edges[minVertex][j]) {
					weight[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}

	for(int i = 1; i < vertices; i++) {
		if(parent[i] < i) {
			cout << parent[i] << " " << i << " " << weight[i] << endl;
		} else {
			cout << i << " " << parent[i] << " " << weight[i] << endl;
		}
	}

	cout << endl << endl;

	delete[] parent;
	delete[] visited;
	delete[] weight;
}

int main(void) {
		
	int vertices, edges;
	cin >> vertices >> edges;

	int **Edge = new int* [vertices];
	for(int i = 0; i < vertices; i++) {
		Edge[i] = new int[vertices];
		for(int j = 0; j < vertices; j++) {
			Edge[i][j] = 0;
		}
	}

	for(int i = 0; i < vertices; i++) {
		int first, second, weight;
		cin >> first >> second >> weight;
		Edge[first][second] = weight;
		Edge[second][first] = weight;
	}

	cout << endl << endl;

	prims(Edge, vertices);

	for(int i = 0; i < vertices; i++) {
		delete[] Edge[i];
	}

	delete[] Edge;
	return 0;
}
