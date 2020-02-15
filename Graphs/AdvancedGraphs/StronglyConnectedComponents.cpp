# include <iostream>
# include <stack>
# include <vector>
# include <unordered_set>
using namespace std;

void dfs(vector<int> *Edge, int startingVertex, unordered_set<int> &visited, stack<int> &finishedStack) {
		
	visited.insert(startingVertex);
	for(int i = 0; i < Edge[startingVertex].size(); i++) {
		int next = Edge[startingVertex][i];
		if(visited.count(next) == 0) {
			dfs(Edge, next, visited, finishedStack);
		}
	}

	cout << startingVertex << endl;
	finishedStack.push(startingVertex);
}

void dfsTranspose(vector<int> *transposeEdge, int startingVertex, unordered_set<int> &visited, unordered_set<int> *component) {
		
	visited.insert(startingVertex);
	component -> insert(startingVertex);
	for(int i = 0; i < transposeEdge[startingVertex].size(); i++) {
		int adjacent = transposeEdge[startingVertex][i];
		if(visited.count(adjacent) == 0) {
			dfsTranspose(transposeEdge, adjacent, visited, component);
		}
	}
}

unordered_set<unordered_set<int> *>* getStronglyConnectedComponents(vector<int> *Edge, vector<int> *transposeEdge, int vertices) {
		
	unordered_set<int> visited;
	stack<int> finishedVertices;
	for(int i = 0; i < vertices; i++) {
		if(visited.count(i) == 0) {
			dfs(Edge, i, visited, finishedVertices);
		}
	}

	unordered_set<unordered_set<int> *>* output = new unordered_set<unordered_set<int> *> ();
	visited.clear();

	while(finishedVertices.empty() == false) {
		
		int element = finishedVertices.top();
		finishedVertices.pop();

		if(visited.count(element) != 0) {
			continue;
		}

		unordered_set<int> *component = new unordered_set<int> ();
		dfsTranspose(transposeEdge, element, visited, component);
		output -> insert(component);
	}

	return output;
}

int main(void) {
		
	int vertices, edges;
	cin >> vertices >> edges;

	vector<int> *Edge = new vector<int> [vertices];
	vector<int> *transposeEdge = new vector<int> [vertices];
	
	for(int i = 0; i< edges; i++) {
		int source, destination;
		cin >> source >> destination;
		Edge[source - 1].push_back(destination - 1);
		transposeEdge[destination - 1].push_back(source -  1);
	}

	unordered_set<unordered_set<int> *>* components = getStronglyConnectedComponents(Edge, transposeEdge, vertices);

	unordered_set<unordered_set<int> *> ::iterator it = components -> begin();

	while(it != components -> end()) {
			
		unordered_set<int> *component = *it;
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
