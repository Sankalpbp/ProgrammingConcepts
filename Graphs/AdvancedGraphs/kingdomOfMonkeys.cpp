# include <iostream>
using namespace std;

void dfs(int ** adjacencyList, int vertices, int startingVertex, int &b, int *bananas, bool *visited) {
	
	visited[startingVertex] = true;
	b += bananas[startingVertex];
	for(int i = 0; i < vertices; i++) {
		if(visited[i] == false && adjacencyList[startingVertex][i] == 1) {
			dfs(adjacencyList, vertices, i, b, bananas, visited);
		}
	}
}
		
int maximumCoins(int ** adjacencyList, int vertices, int *bananas) {
		
	// we gotta do a disconnectedDFS
	
	int max = 0;

	bool *visited = new bool[vertices];
	for(int i = 0; i < vertices; i++) {
		visited[i] = false;
	}

	for(int i = 0; i < vertices; i++) {
		if(visited[i] == false) {
			int b = 0;
			dfs(adjacencyList, vertices, i, b, bananas, visited);
			if(b > max) {
				max = b;
			}
		}
	}

	return max;
}

int main(void) {
		
	int testcases;
	cin >> testcases;

	while(testcases--) {
			
		int n, m;
		cin >> n >> m;

		int **adjacencyList = new int* [n];
		for(int i = 0; i < n; i++) {
			adjacencyList[i] = new int[n];
		}

		for(int i = 0; i < m; i++) {
			int source, destination;
			cin >> source >> destination;
			adjacencyList[source - 1][destination - 1] = 1;
			adjacencyList[destination - 1][source - 1] = 1;
		}

		int *bananas = new int[n];
		for(int i = 0; i < n; i++) {
			cin >> bananas[i];
		}

		cout << maximumCoins(adjacencyList, n, bananas) << endl << endl;

		for(int i = 0; i < n; i++) {
			delete[] adjacencyList[i];
		}

		delete[] adjacencyList;
		delete[] bananas;
	}

	return 0;
}
