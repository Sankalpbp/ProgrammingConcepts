# include <iostream>
using namespace std;

void printSolution(int **solution, int n) {

	for(int i=0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			cout << solution[i][j] << " ";
		}
		cout << endl;
	}
}

void mazeHelp(int maze[][20], int n, int **solution, int x, int y) {

	if(x == n-1 && y == n-1) {
		solution[x][y] = 1;
		printSolution(solution, n);
		return;
	}

	if(x == n || x < 0 || y == n || y < 0 || maze[x][y] == 0 || solution[x][y] == 1) {
		return;
	}

	solution[x][y] = 1;
	// include yourself and EXPLORE

	mazeHelp(maze, n, solution, x - 1, y);
	mazeHelp(maze, n, solution, x + 1, y);
	mazeHelp(maze, n, solution, x, y - 1);
	mazeHelp(maze, n, solution, x, y + 1);
	solution[x][y] = 0;
}

void ratInaMaze(int maze[][20], int n) {

	int ** solution = new int*[n];

	for(int i = 0; i<n; i++) {
		solution[i] = new int[n];
	}

	mazeHelp(maze, n, solution, 0, 0);
}

int main(void) {

	int n;
	cin >> n;

	int maze[20][20];
	for(int i=0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			cin >> maze[i][j];
		}
	}

	ratInaMaze(maze, n);

	cout << endl << endl;
	return 0;
}
