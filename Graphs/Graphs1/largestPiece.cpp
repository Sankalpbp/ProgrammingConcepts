# include <iostream>
using namespace std;

int countHelper(int **matrix, bool **visited, int i, int j, int rows, int cols) {
	
	if(i == rows || j == cols || i < 0 || j < 0) {
		return 0;
	}

	if(matrix[i][j] == 0) {
		return 0;
	}

	if(visited[i][j] == true) {
		return 0;
	}

	visited[i][j] = true;
	int count = 1;

	count += countHelper(matrix, visited, i + 1, j, rows, cols);
	count += countHelper(matrix, visited, i, j + 1, rows, cols);
	count += countHelper(matrix, visited, i - 1, j, rows, cols);
	count += countHelper(matrix, visited, i, j - 1, rows, cols);

	return count;
}

int countMaxOnes(int **matrix, int n) {
	
	int count = 0;	

	bool **visited = new bool* [n];
	for(int i = 0; i < n; i++) {
		visited[i] = new bool[n];
		for(int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}

	int max = 0;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(matrix[i][j] == 1 && visited[i][j] == false) {
				count = countHelper(matrix, visited, i, j, n, n);
				if(count > max) {
					max = count;
				}
			}
		}
	}

	return max;
}

int main(void) {
		
	int n;
	cin >> n;

	int **matrix = new int* [n];
	for(int i = 0; i < n; i++) {
		matrix[i] = new int[n];
		for(int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << countMaxOnes(matrix, n) << endl << endl;

	return 0;
}
