# include <iostream>
using namespace std;

int return_3_cycles(int ** adjacencyList, int n) {
		
	int count = 0;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(adjacencyList[i][j] == 1) {
				// first edge
				for(int k = 0; k < n; k++) {
					if(adjacencyList[j][k] == 1 && adjacencyList[k][i] == 1) {
						// second to third vertex andd third to first
						count += 1;
					}
				}
			}
		}
	}

	return (count / 6);
}

int main(void) {
		
	int n, m;
	cin >> n >> m;

	int *u = new int[m];
	int *v = new int[m];

	for(int i = 0; i < m; i++) {
		cin >> u[i];
	}

	for(int i = 0; i < m; i++) {
		cin >> v[i];
	}

	int **adjacencyList = new int* [n];
	for(int i = 0; i < n; i++) {
		adjacencyList[i] = new int[n];
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			adjacencyList[u[i] - 1][v[i] - 1] = 1;
			adjacencyList[v[i] - 1][u[i] - 1] = 1;
		}
	}

	cout << return_3_cycles(adjacencyList, n) << endl << endl;

	return 0;
}
