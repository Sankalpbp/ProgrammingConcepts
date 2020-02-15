# include <iostream>
# include <queue>
using namespace std;

void bfs(int **adjacencyList, int startingVertex, bool *visited, int vertices) {
		
	queue<int> q;
	q.push(startingVertex);
	visited[startingVertex] = true;

	while(q.empty() == false) {
			
		int x = q.front();
		q.pop();

		for(int i = 0; i < vertices; i++) {
			if(adjacencyList[x][i] == 1 && visited[i] == false) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int returnNumberOfIslands(int **adjacencyList, int startingVertex, int vertices) {

	int number = 0;
	bool *visited = new bool[vertices];

	for(int i = 0; i < vertices; i++) {
		visited[i] = false;
	}

	for(int i = 0; i < vertices; i++) {
		if(visited[i] == false) {
			bfs(adjacencyList, i, visited, vertices);
			number++;
		}
	}
	
	return number;
}

int main(void) {
		
	int n, m;
	cin >> n >> m;

	int *u = new int[m];
	int *v = new int[m];

	for(int i = 0; i < m; i++) {
		cin >> u[i];
	}

	for(int i = 0; i < m; i++) {
		cin >> v[i];
	}

	//building adjacency list
	
	int **adjacencyList = new int* [n];
	for(int i = 0 ; i < n; i++) {
		adjacencyList[i] = new int[n];
	}

//	for(int i = 0; i < n; i++) {
//		for(int j = 0; j < n; j++) {
//			cout << adjacencyList[i][j] << " ";
//		}
//		cout << endl;
//	}

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < m; j++) {
			adjacencyList[u[i] - 1][v[i] - 1] = 1;
			adjacencyList[v[i] - 1][u[i] - 1] = 1;
		}
	}

	cout << endl << returnNumberOfIslands(adjacencyList, 0, n) << endl << endl;
	return 0;
}
