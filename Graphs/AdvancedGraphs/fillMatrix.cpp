# include <iostream>
# include <unordered_set>
# include <queue>
# include <vector>
# include <set>
using namespace std;

bool isBipartite(vector<int> *adjacencyList, int vertices) {
		
	if(vertices == 0) {
		return true;
	}

	queue<int> pending;
	unordered_set<int> *sets = new unordered_set<int> [2];
	pending.push(0);

	sets[0].insert(0);

	while(pending.empty() == false) {
		
		int element = pending.front();
		pending.pop();

		int currentSet = sets[0].count(element);
		if(currentSet > 0) {
			currentSet = 0;
		} else {
			currentSet = 1;
		}

		for(int i = 0; i < adjacencyList[element].size(); i++) {
			int neighbor = adjacencyList[element][i];

			if(sets[0].count(neighbor) == 0 && sets[1].count(neighbor)) {
				sets[1 - currentSet].insert(neighbor);
				pending.push(neighbor);
			} else if(sets[currentSet].count(neighbor) > 0) {
				return false;
			}
		}
	}

	return true;
}

int makeParents(int *parent, int **matrix, int n) {
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {

			if(matrix[i][j] == -1) {
				continue;
			} else if(matrix[i][j] == 0) {
				if(parent[i] < parent[j]) {
					parent[j] = parent[i];
				} else {
					parent[i] = parent[j];
				}
			}

		}
	}

	set<int> ParentsNumber;
	for(int i = 0; i < n; i++) {
		ParentsNumber.insert(parent[i]);
	}

	return ParentsNumber.size();
}


bool arrayBPossible(int **matrix, int n) {
		
	// firstly, basic sanity checking
	// if any of the matrix[i][i] = 1, that is b[i] and b[i] aren't equal, that's vague

	for(int i = 0; i < n; i++) {
		if(matrix[i][i] != 0 || matrix[i][i] != -1) {
			return false;
		}
	}

	// second sanity check, if matrix[i][j] exists, then, either matrix[i][j] shouldn't exist, or both should be equal

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(matrix[i][j] == -1 || matrix[j][i] == -1) {
				continue;
			} else if(matrix[i][j] != matrix[j][i]) {
				return false;
			}
		}
	}

	// now, assume the given matrix as an adjacency matrix and figure out the edges and the vertices
	// all the elements with like matrix[i][j] = 0 would form one vertex
	// example : lets say, we have matrix[i][j] = 0 and matrix[j][k] = 0, then, one vertex, contains (i, j, k)
	// this can be done using union find algorithm, isn't it

	int *parent = new int[n];
	for(int i = 0; i < n; i++) {
		parent[i] = i;
	}

	// this procedure will form the components which satisfies the condition for B to exist and hence, they will be in a separate component,
	// and they act as our vertices for the new graph
	int vertices = makeParents(parent, matrix, n);	// essentially components;
	cout << vertices << endl << endl;

	// now that our vertices are over, we will make our edges

	vector<int> *adjacencyList = new vector<int> [vertices];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(matrix[i][j] == 1) {
				if(parent[i] == parent[j]) {
					return false;
				}
			}

			int source, destination;
			if(parent[i] < parent[j]) {
				source = parent[i];
				destination = parent[j];
			} else {
				source = parent[j];
				destination = parent[i];
			}
			adjacencyList[source].push_back(destination);
			adjacencyList[destination].push_back(source);
		}
	}

	// the question wants that we can't have any 
	bool answer = isBipartite(adjacencyList, vertices);

	return answer;
}

int main(void) {
		
	int testcases;
	cin >> testcases;

	while(testcases) {
			
		int n;
		cin >> n;

		int **matrix = new int* [n];
		for(int i = 0; i < n; i++) {
			matrix[i] = new int[n];
			for(int j = 0; j < n; j++) {
				matrix[i][j] = -1;
			}
		}

		int q;
		cin >> q;

		for(int i = 0; i < q; i++) {
			int x, y, value;
			cin >> x >> y >> value;
			matrix[x - 1][y - 1] = value;
		}

		if(arrayBPossible(matrix, n)) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}
	return 0;
}
