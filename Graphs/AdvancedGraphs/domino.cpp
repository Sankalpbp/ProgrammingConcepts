# include <iostream>
# include <vector>
using namespace std;

void countComponentsDFS(vector<int> *adjacencyList, int startingVertex, bool *visited) {
		
	visited[startingVertex] = true;
	for(int i = 0; i < adjacencyList[startingVertex].size(); i++) {
		int adjacent = adjacencyList[startingVertex][i];
		if(visited[adjacent] == false) {
			countComponentsDFS(adjacencyList, adjacent, visited);
		}
	}
}

int minimumEffort(vector<int> *adjacencyList, int vertices) {
		
	bool *visited = new bool[vertices];
	for(int i = 0; i < vertices; i++) {
		visited[i] = false;
	}

	int count = 0;

	for(int i = 0; i < vertices; i++) {
		if(visited[i] == false) {
			count += 1;
			countComponentsDFS(adjacencyList, i, visited);  
		}
	}

	delete[] visited;
	return count;
}

int main(void) {
		
	int vertices, edges;
	cin >> vertices >> edges;

	vector<int> *adjacencyList = new vector<int> [vertices];
	for(int i = 0; i < edges; i++) {
		int source, destination;
		cin >> source >> destination;
		adjacencyList[source - 1].push_back(destination - 1);
		adjacencyList[destination - 1].push_back(source - 1);
	}

	cout << minimumEffort(adjacencyList, vertices) << endl << endl;
	
	return 0;
}
