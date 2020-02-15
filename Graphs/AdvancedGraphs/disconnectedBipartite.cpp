# include <iostream>
# include <unordered_set>
# include <queue>
# include <vector>

using namespace std;

bool isBipartite(vector<int> *Edge, int vertices, int startingVertex, bool *visited) {
		
	visited[startingVertex] = true;

	queue<int> pending;
	pending.push(startingVertex);
	unordered_set<int> *sets = new unordered_set<int> [2];
	sets[0].insert(startingVertex);

	while(pending.empty() == false) {
			
		int current = pending.front();
		pending.pop();

		int currentSet = sets[0].count(current);
		if(currentSet > 0) {
			currentSet = 0;
		} else {
			currentSet = 1;
		}

		for(int i = 0; i < Edge[current].size(); i++) {
			int neighbor = Edge[current][i];
			if(sets[0].count(neighbor) == 0 && sets[1].count(neighbor) == 0) {
				sets[1 - currentSet].insert(neighbor);
				pending.push(neighbor);
			} else if(sets[currentSet].count(neighbor) > 0) {
				return false;
			}
		}
	}

	return true;
}

bool isBipartite(vector<int> *Edge, int vertices) {
	
	bool *visited = new bool[vertices];

	bool answer = true;
	for(int i = 0; i < vertices; i++) {
		if(visited[i] == false) {
			answer = answer && isBipartite(Edge, vertices, i, visited);
		}
	}

	return answer;
}

using namespace std;

int main(void) {
		
	while(true) {
		int vertices;
		cin >> vertices;

		if(vertices == 0) {
			break;
		}

		vector<int> *Edge = new vector<int> [vertices];
		int edges;
		cin >> edges;

		for(int i = 0; i < edges; i++) {
			int source, destination;
			cin >> source >> destination;
			Edge[source].push_back(destination);
			Edge[destination].push_back(source);
		}

		bool answer = isBipartite(Edge, vertices);

		if(answer) {
			cout << "BICOLORABLE\n";
		} else {
			cout << "NON BICOLORABLE\n";
		}
		cout << endl << endl;
	}

	return 0;
}
