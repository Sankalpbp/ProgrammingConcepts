# include <iostream>
# include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> *Edge, int startingVertex, bool *visited, unordered_set<int> *component) {
		
	visited[startingVertex] = true;
	component -> insert(startingVertex);

	for(int i = 0; i < Edge[startingVertex].size(); i++) {
		int next = Edge[startingVertex][i];
		if(visited[next] == false) {
			dfs(Edge, next, visited, component);
		}
	}
}

unordered_set<unordered_set<int>*>* getComponents(vector<int> *Edge, int vertices) {
		
	bool *visited = new bool[vertices]();
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*> ();

	for(int i = 0; i < vertices; i++) {
		
		if(visited[i] == false) {
			unordered_set<int>* component = new unordered_set<int> ();
			dfs(Edge, i, visited, component);
			output -> insert(component);
		}
	}

	delete[] visited;
	return output;
}

int main(void) {
		
	int vertices;
	cin >> vertices;

	vector<int> *Edge = new vector<int> [vertices];
	// kind of an adjacency list stuff for storing edges
	
	int edges;
	cin >> edges;

	for(int i = 0; i < edges; i++) {
		
		int first, second;
		cin >> first >> second;

		Edge[first - 1].push_back(second - 1);
		Edge[second - 1].push_back(first - 1);
	}

	unordered_set<unordered_set<int>*>* components = getComponents(Edge, vertices);

	unordered_set<unordered_set<int>*> :: iterator it1 = components -> begin();
	while(it1 != components -> end()) {
			
		unordered_set<int>* component = *it1;
		
		unordered_set<int> :: iterator it2 = component -> begin();
		while(it2 != component -> end()) {
				cout << *it2 + 1 << " ";
				it2++;
		}
		it1++;
		cout << endl;
	}

	cout << endl << endl;
	return 0;
}








