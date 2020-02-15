# include <iostream>
# include <string.h>
using namespace std;

int board[11][11];

bool checkPossible(int totalRows, int row, int column) {

	for(int i=0; i<row; i++) {
		if(board[i][column] == 1) {
			return false;
		}
	}

	for(int i = row - 1, j = column - 1; i >=0 && j >=0; i--, j--) {

		if(board[i][j] == 1) {
			return false;
		}
	}

	for(int i = row - 1, j = column + 1; i >=0 && j < totalRows; i--, j++) {
		if(board[i][j] == 1) {
			return false;
		}
	}

	return true;
}

void nQueenHelper(int n, int row) {

	if(row == n) {

		// we have reached the solution. Print it.
		for(int i=0; i<n; i++) {
			for(int j= 0; j<n; i++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl << endl;
		return;
	}

	// place to all possible positions and move to smaller problem

	for(int column = 0; column < n; column++) {

		if(checkPossible(n, row, column)) {
			board[row][column] = 1;
			nQueenHelper(n, row + 1);
			board[row][column] = 0;
		}
	}

	return;
}

void placeNQueens(int n) {

	memset(board, 0, 11 * 11 * sizeof(int));
	nQueenHelper(n, 0);
}


int main(void) {

	int n;
	cin >> n;

	placeNQueens(n);
	cout << endl;

	return 0;
}
