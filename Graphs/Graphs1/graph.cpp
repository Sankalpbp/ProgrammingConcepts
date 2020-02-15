# include <iostream>
using namespace std;

void print(int **Edge, int vertices, int startingVertex, bool *visited) {
		
	cout << startingVertex << endl;
	visited[startingVertex] = true;

	for(int i = 0; i < vertices; i++) {
		if(i == startingVertex) {
			continue;
		}
		if(Edge[startingVertex][i] == 1) {
			if(visited[i] == true) {
				continue;
			}
			print(Edge, vertices, i, visited);
		}
	}
}

int main(void) {
		
	int vertices;
	int edges;

	cin >> vertices >> edges;

	int **Edge = new int* [edges];
	for(int i = 0; i < vertices; i++) {
		Edge[i] = new int[vertices];
		for(int j = 0; j < vertices; j++) {
			Edge[i][j] = 0;
		}
	}

	for(int i = 0; i < edges; i++) {
		int firstVertex, secondVertex;
		cin >> firstVertex >> secondVertex;

		Edge[firstVertex][secondVertex] = 1;
		Edge[secondVertex][firstVertex] = 1;
	}

	bool *visited = new bool[vertices];
	for(int i = 0; i < vertices; i++) {
		visited[i] = false;
	}

	print(Edge, vertices, 0, visited);
	
	return 0;
}
