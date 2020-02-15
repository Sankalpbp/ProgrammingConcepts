# include <iostream>
# include <stack>
# include <unordered_set>
# include <vector>
using namespace std;

void dfs(vector<int> *Edge, unordered_set<int> &visited, int startingVertex, stack<int> &finishedStack) {
	
	visited.insert(startingVertex);
	for(int i = 0; i < Edge[startingVertex].size(); i++) {
		int adjacent = Edge[startingVertex][i];
		if(visited.count(adjacent) == 0) {
			dfs(Edge, visited, adjacent, finishedStack);
		}
	}
	finishedStack.push(startingVertex);
}

void dfsTranspose(vector<int> *transposeEdge, int startingVertex, unordered_set<int> *component, unordered_set<int> &visited) {
		
	visited.insert(startingVertex);
	component -> insert(startingVertex);

	for(int i = 0; i < transposeEdge[startingVertex].size(); i++) {
		int adjacent = transposeEdge[startingVertex][i];
		if(visited.count(adjacent) == 0) {
			dfsTranspose(transposeEdge, adjacent, component, visited);
		}
	}
}

unordered_set<unordered_set<int> *> *getStronglyConnectedComponents(vector<int> *Edge, vector<int> *transposeEdge, int vertices) {
		
	unordered_set<int> visited;
	stack<int> finishedVertices;
	
	for(int i = 0; i < vertices; i++) {
		if(visited.count(i) == 0) {
			dfs(Edge, visited, i, finishedVertices);
		}
	}

	unordered_set<unordered_set<int> *>* output = new unordered_set<unordered_set<int> *> ();
	
	visited.clear();
	while(finishedVertices.empty() == false) {
		
		int element = finishedVertices.top();
		finishedVertices.pop();

		if(visited.count(element) == 0) {
			unordered_set<int> *component = new unordered_set<int> ();
			dfsTranspose(transposeEdge, element, component, visited);
			output -> insert(component);
		}
	}

	return output;
}

int main(void) {
		
	int vertices, edges;
	cin >> vertices;
	while(vertices != 0) {
		cin >> edges;
		
		vector<int> *Edge = new vector<int> [vertices];
		vector<int> *transposeEdge = new vector<int> [vertices];
		for(int i = 0; i < edges; i++) {
			int source, destination;
			cin >> source >> destination;
			Edge[source - 1].push_back(destination - 1);
			transposeEdge[destination - 1].push_back(source - 1);
		}

		unordered_set<unordered_set<int> *> *components = getStronglyConnectedComponents(Edge, transposeEdge, vertices);

		unordered_set<unordered_set<int> *> :: iterator it = components -> begin();

		while(it != components -> end()) {
				
			unordered_set<int> *component = *it;
			unordered_set<int> :: iterator itt = component -> begin();
			
			bool notBottom = false;
			while(itt != component -> end()) {
				for(int i = 0; i < Edge[*itt].size(); i++) {
					int neighbor = Edge[*itt][i];
					if(component -> count(neighbor) == 0) {
						notBottom = true;	
						break;
					}
				}
				if(notBottom == true) {
					break;
				}
				itt++;
			}

			if(notBottom == false) {
				itt = component -> begin();
				while(itt != component -> end()) {
					cout << *itt + 1 << " ";
					itt++;
				}
				cout << endl << endl;
			}
			it++;	
		}

		cin >> vertices;
	}	

	return 0;
}
