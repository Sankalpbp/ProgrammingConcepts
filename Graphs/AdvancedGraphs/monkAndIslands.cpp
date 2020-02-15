# include <iostream>
# include <queue>
using namespace std;

int returnMinPath(int ** adjacencyList, int vertices) {
		
	bool *visited = new bool[vertices];
	for(int i = 0; i < vertices; i++) {
		visited[i] = false;
	}

	int *level = new int[vertices];
	queue<int> pendingVertices;
	pendingVertices.push(0);
	visited[0] = true;

	while(pendingVertices.empty() == false) {
		int vertex = pendingVertices.front();
		pendingVertices.pop();

		for(int i = 0; i < vertices; i++) {
			if(adjacencyList[vertex][i] == 1 && visited[i] == false) {
				level[i] = level[vertex] + 1;
				pendingVertices.push(i);
				if(i == vertices - 1) {
					return level[i];
				}
				visited[i] = true;
			}
		}
	}

	return level[vertices - 1];
}

int main(void) {
		
	int n, m;
	cin >> n >> m;

	int **adjacencyList = new int *[n];
	for(int i = 0; i < n; i++) {
		adjacencyList[i] = new int[n];
	}

	for(int i = 0; i < m; i++) {
		int source, destination;
		cin >> source >> destination;
		adjacencyList[source - 1][destination - 1] = 1;
		adjacencyList[destination - 1][source - 1] = 1;
	}

	cout << returnMinPath(adjacencyList, n);

	return 0;
}
