# include <iostream>
# include <climits>
using namespace std;

int getMinVertex(bool *visited, int *distance, int vertices) {
		
	int minVertex = -1;
	
	for(int i = 0; i < vertices; i++) {
			
		if(visited[i] == false && ((minVertex == -1) || (distance[minVertex] > distance[i]))) {
			minVertex = i;
		}
	}

	return minVertex;
}

void dijkstra(int **Edges, int vertices) {
		
	bool *visited = new bool[vertices]();
	int *distance = new int[vertices];

	for(int i = 0; i < vertices; i++) {
		distance[i] = INT_MAX;
	}

	int source;
	cin >> source;

	distance[source] = 0;

	for(int i = 0; i < vertices - 1; i++) {
		
		// get vertex with minimum vertex and not visited
		int minVertex = getMinVertex(visited, distance, vertices);

		visited[minVertex] = true;
		// explore all the neighbors of minVertex which are unvisited and update the distance array if required

		for(int j = 0; j < vertices; i++) {
			if(Edges[minVertex][j] != 0 && visited[j] == false) {
				int currentDistance = distance[minVertex] + Edges[minVertex][j];
				if(distance[j] > currentDistance) {
					distance[j] = currentDistance;
				}
			}
		}
	}

	for(int i = 0; i < vertices; i++) {
		cout << i << " " << distance[i] << endl;
	}

	delete[] visited;
	delete[] distance;
}

int main(void) {

	int vertices, edges;
	cin >> vertices >> edges;

	int **Edges = new int* [vertices];
	for(int i = 0; i < vertices; i++) {
		Edges[i] = new int[vertices];
		for(int j = 0; j < vertices; j++) {
			Edges[i][j] = 0;
		}
	}

	for(int i = 0; i < edges; i++) {
		int first, second, weight;
		cin >> first >> second >> weight;

		Edges[first][second] = weight;
		Edges[second][first] = weight;
//		cout << Edges[first][second] << " ";
	}
		
	cout << endl << endl;
	dijkstra(Edges, vertices);

	for(int i = 0; i < vertices; i++) {
		delete[] Edges[i];
	}

	delete[] Edges;
		
	return 0;
}
