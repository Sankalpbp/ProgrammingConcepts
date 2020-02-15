# include <iostream>
# include <climits>
using namespace std;

int getMinVertex(bool *visited, int * weight, int vertices) {
		
	int minVertex = -1;

	for(int i = 0; i < vertices; i++) {
		if(visited[i] == false && (minVertex == -1 || weight[minVertex] > weight[i])) {
			minVertex = i;
		}
	}

	return minVertex;
}

void prims(int ** Edges, int vertices) {
		
	bool *visited = new bool[vertices];
	for(int i = 0; i < vertices; i++) {
		visited[i] = false;
	}
	int *parent = new int[vertices];

	int *weight = new int[vertices];

	for(int i = 0; i < vertices; i++) {
		weight[i] = INT_MAX;
	}

	parent[0] = -1; // parent of the source is nobody
	weight[0] = 0; // the distance of the source from source is 0

	for(int j = 0; j < vertices - 1; j++) {
		
		// get minVertex, that is, unvisited vertex with minimum weight
		int minVertex = getMinVertex(visited, weight, vertices);
		visited[minVertex] = true;

		// explore all the neighbors of minVertex and update parent and weight array accordingly
		for(int j = 0; j < vertices; j++) {
			if(visited[j] == false && Edges[minVertex][j] != 0) {
				if(weight[j] > Edges[minVertex][j]) {
					weight[j] = Edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}

	for(int i = 1; i < vertices; i++) {
		if(parent[i] > i) {
			cout << i << " " << parent[i] << " " << weight[i] << endl;
		} else {
			cout << parent[i] << " " << i << " " << weight[i] << endl;
		}
	}
}

int main(void) {
		
	int vertices, edges;
	cin >> vertices >> edges;

	int ** Edge = new int* [vertices];
	for(int i = 0; i < vertices; i++) {
		Edge[i] = new int[vertices];
		for(int j = 0; j < vertices; j++) {
			Edge[i][j] = 0;
		}
	}

	for(int i = 0; i < vertices; i++) {
		int f, s, w;
		cin >> f >> s >> w;

		Edge[f][s] = w;
		Edge[s][f] = w;
	}

	cout << endl << endl;

	prims(Edge, vertices);

	for(int i = 0; i < vertices; i++) {
		delete[] Edge[i];
	}

	delete[] Edge;

	return 0;
}
