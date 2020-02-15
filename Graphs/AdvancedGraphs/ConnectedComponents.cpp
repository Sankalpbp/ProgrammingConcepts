# include <iostream>
# include <vector>
# include <unordered_set>
using namespace std;

void dfs(vector<int> *Edges, int startingVertex, bool *visited, unordered_set<int> *component) {
		
	visited[startingVertex] = true;
	component -> insert(startingVertex);

	for(int i = 0; i < Edges[startingVertex].size(); i++) {
		int next = Edges[startingVertex][i];
		if(visited[next] == false) {
			dfs(Edges, next, visited, component);
		}
	}
}

unordered_set<unordered_set<int> *> * getComponent(vector<int> *Edges, int vertices) {
		
	bool *visited = new bool[vertices];
	for(int i = 0; i < vertices; i++ ){
		visited[i] = false;
	}

	unordered_set<unordered_set<int> *> * output = new unordered_set<unordered_set<int>*> ();

	for(int i = 0; i < vertices; i++) {
		
		if(visited[i] == false) {
			unordered_set<int> *component = new unordered_set<int> ();
			dfs(Edges, i, visited, component);
			output -> insert(component);
		}
	}

	return output;
}

int main(void) {

	int vertices, edges;
	cin >> vertices >> edges;

	vector<int> *Edges = new vector<int> [vertices];
	
	for(int i = 0; i < edges; i++) {
		int source, destination;
		cin >> source >> destination;

		Edges[source - 1].push_back(destination - 1);
		Edges[destination - 1].push_back(source - 1);
	}

	unordered_set<unordered_set<int> *> * components = getComponent(Edges, vertices);

	unordered_set<unordered_set<int> *> :: iterator it = components -> begin();

	while(it != components -> end()) {
			
		unordered_set<int> *component = *it;
		unordered_set<int> :: iterator itt = component -> begin();
		while(itt != component -> end()) {
			cout << *itt + 1 << " ";
			itt++;
		}

		cout << endl;
		it++;
	}

	cout << endl << endl;
		
	return 0;
}
