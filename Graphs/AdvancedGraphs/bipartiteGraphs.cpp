# include <iostream>
# include <vector>
# include <queue>
# include <unordered_set>
using namespace std;

bool isBipartite(vector<int> *Edge, int vertices) {
		
	if(vertices == 0) {
		return true;
	}
	unordered_set<int> *sets = new unordered_set<int> [2];
	
	queue<int> pending;
	pending.push(0);			
	sets[0].insert(0);
	
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
		cout << "\n\nreached\n\n";

		for(int i = 0; i < edges; i++) {
			int source, destination;
			cin >> source >> destination;
			Edge[source].push_back(destination);
			Edge[destination].push_back(source);
		}

		bool answer = isBipartite(Edge, vertices);
		delete[] Edge;

		if(answer) {
			cout << "BICOLORABLE" << endl;
		} else {
			cout  << "NOT BICOLORABLE" << endl;
		}
	}

	return 0;
}
