# include <iostream>
# include <vector>
# include <stack>
# include <unordered_set>
using namespace std;

void dfs(vector<int> *Edge, int startingVertex, unordered_set<int> &visited, stack<int> &finishedStack) {

	visited.insert(startingVertex);
		
	for(int i = 0; i < Edge[startingVertex].size(); i++) {
		int adjacentVertex = Edge[startingVertex][i];
		if(visited.count(adjacentVertex) == 0) {
			dfs(Edge, adjacentVertex, visited, finishedStack);
		}
	}

	finishedStack.push(startingVertex);
}

void dfs2(vector<int> *transposeEdge, int startingVertex, unordered_set<int> *component, unordered_set<int> &visited) {
		
	visited.insert(startingVertex);
	component -> insert(startingVertex);

	for(int i = 0; i < transposeEdge[startingVertex].size(); i++) {
		
		int adjacentVertex = transposeEdge[startingVertex][i];
		if(visited.count(adjacentVertex) == 0) {
			dfs2(transposeEdge, adjacentVertex, component, visited);
		}
	}
}

// this is basically Kosaraju's algorithm

unordered_set<unordered_set<int>*>* getStrongComponents(vector<int> *Edge, vector<int> *transposeEdge, int vertices) {
		
	unordered_set<int> visited;
	stack<int> finishedVertices;

	for(int i = 0; i < vertices; i++) {
		if(visited.count(i) == 0) {
			// if it hasn't been visited yet, then, we will call dfs
			dfs(Edge, i, visited, finishedVertices);
		}
	}

	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*> ();
	visited.clear();

	while(finishedVertices.empty() == false) {
			
		int element = finishedVertices.top();
		finishedVertices.pop();

		if(visited.count(element) != 0) {
			continue;
		}

		unordered_set<int> *component = new unordered_set<int> ();
		dfs2(transposeEdge, element, component, visited);
		output -> insert(component);
	}

	return output;
}

int main(void) {
		
	int vertices;
	cin >> vertices;

	int edges; 
	cin >> edges;

	vector<int> *Edge = new vector<int> [vertices];
	vector<int> *transposeEdge = new vector<int> [vertices];

	for(int i = 0; i < edges; i++) {
			
		int first, second;
		cin >> first >> second;

		Edge[first - 1].push_back(second - 1);
		transposeEdge[second - 1].push_back(first - 1);
	}

	unordered_set<unordered_set<int>*>* components = getStrongComponents(Edge, transposeEdge, vertices);

	unordered_set<unordered_set<int>*> :: iterator it = components -> begin();
	
	cout << endl << endl;
	while(it != components -> end()) {
			
		unordered_set<int> * component = *it;
		unordered_set<int> :: iterator itt = component -> begin();
		
		while(itt != component -> end()) {
			cout << *itt + 1<< " ";
			itt++;
		}

		cout << endl;
		delete component;
		it++;
	}

	delete[] Edge;
	delete[] transposeEdge;
	
	return 0;
}
