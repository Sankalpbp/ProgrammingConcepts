# include <iostream>
# include <set>
# include <vector>
# include <unordered_set>
using namespace std;

void dfs(bool *visited, unordered_set<int> *component, int startingVertex, vector<int> *Edges) {
		
	visited[startingVertex] = true;
	component -> insert(startingVertex);
	
	for(int i = 0; i < Edges[startingVertex].size(); i++) {
		int next = Edges[startingVertex][i];
		if(visited[next] == false) {
			dfs(visited, component, next, Edges);
		}
	}
}

unordered_set<unordered_set<int> *>* getComponent(vector<int> *Edges, int vertices) {
		
	bool *visited = new bool[vertices];
	for(int i = 0; i < vertices; i++) {
		visited[i] = false;
	}

	unordered_set<unordered_set<int> *>* output = new unordered_set<unordered_set<int> *> ();

	for(int i = 0; i < vertices; i++) {
			
		if(visited[i] == false) {
			unordered_set<int> *component = new unordered_set<int> ();
			dfs(visited, component, i, Edges);
			output -> insert(component);
		}
	}

	delete[] visited;
	return output;
}

int main(void) {
		
	int testcases;
	cin >> testcases;

	while(testcases--) {
			
		int n, m;
		cin >> n >> m;

		int *p = new int[n];
		int *q = new int[n];

		for(int i = 0; i < n; i++) {
			cin >> p[i];
		}

		for(int i = 0; i < n; i++) {
			cin >> q[i];
		}

		vector<int> *Edges = new vector<int> [n];
		for(int i = 0; i < m; i++) {
			int source, destination;
			cin >> source >> destination;
			Edges[source - 1].push_back(destination - 1);
			Edges[destination - 1].push_back(source - 1);
		}

		cout << endl << endl;

		unordered_set<unordered_set<int> *> * components = getComponent(Edges, n);
		unordered_set<unordered_set<int> *> :: iterator it = components -> begin();
		
		bool getOut = false;
		while(it != components -> end()) {
			
			unordered_set<int> * component = *it;
			unordered_set<int> :: iterator itt = component -> begin();

			set<int> pSet;
			set<int> qSet;

			while(itt != component -> end()) {
				int i = *itt;
				pSet.insert(p[i]);
				qSet.insert(q[i]);
				itt++;
			}

			set<int> :: iterator itr1 = pSet.begin();
			set<int> :: iterator itr2 = qSet.begin();
			
			it++;
			for(auto itr = pSet.begin(); itr != pSet.end(); itr++) {
				if(qSet.count(*itr) == 0) {
					cout << "\nNO\n";
					getOut = true;
					break;
				}
			}

			if(getOut == true) {
				break;
			}
		}

		if(getOut == false) {
			cout << "\nYES\n";
		}
		
		cout << endl << endl;
	}

	return 0;
}
