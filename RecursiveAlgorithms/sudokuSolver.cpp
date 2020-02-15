# include <iostream>
using namespace std;

bool sudokuSolver(int *sudoku[9]);

void print(int *sudoku[9]) {

	for(int i =0 ; i<9; i++) {
		for(int j=0; j<9; j++) {
			cout << sudoku[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl << endl;
}

int main(void) {

	const int n = 9;
	int **sudoku = new int*[n];

	for(int i=0; i<n; i++) {
		sudoku[i] = new int[n];
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> sudoku[i][j];
		}
	}

	cout << endl << endl;
	sudokuSolver(sudoku);

	return 0;
}

bool findEmptySpace(int *sudoku[9], int &row, int &column) {

	int n = 9;
	
	for(int i=0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			if(sudoku[i][j] == 0) {
				row = i;
				column = j;
				return true;
			}
		}
	}

	return false;
}

bool isRowSafe(int *sudoku[9], int row, int number) {

	int n = 9;
	for(int i=0; i<n; i++) {
		if(sudoku[row][i] == number) {
			return false;
		}
	}

	return true;
}

bool isColumnSafe(int *sudoku[9], int column, int number) {

	int n = 9;

	for(int i=0; i<n; i++) {
		if(sudoku[i][column] == number) {
			return false;
		}
	}

	return true;
}

bool isGridSafe(int *sudoku[9], int row, int column, int number) {

	row = row - (row % 3);
	column = column - (column % 3);

	for(int i=0; i<3; i++) {
		for(int j = 0; j<3; j++) {
			if(sudoku[row + i][column + j] == number) {
				return false;
			}
		}
	}

	return true;
}

bool isSafe(int *sudoku[9], int row, int column, int number) {

	bool rowWise = isRowSafe(sudoku, row, number);
	bool columnWise = isColumnSafe(sudoku, column, number);
	bool gridWise = isGridSafe(sudoku, row, column, number);

	return rowWise && columnWise && gridWise;
}

bool sudokuSolver(int *sudoku[9]) {

	int row, column;

	// firstly, we will find the empty space

	if(findEmptySpace(sudoku, row, column) == false) {
		// then, this means, we have reached a stage where the sudoku is filled, so we have reached a solution
		print(sudoku);
		return true;
	}

	// otherwise, we will fill the stuff in it

	for(int i = 1; i <= 9 ;i++) {
	
		if(isSafe(sudoku, row, column, i)) {
			// findEmptySpace() will provide isSafe() the row and column which is empty, hence need to be filled by something
			sudoku[row][column] = i;
			if(sudokuSolver(sudoku)) {
				return true;
			}

			sudoku[row][column] = 0;
		}
	}

	return false;
}
