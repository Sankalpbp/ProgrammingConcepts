# include <iostream>
# include <climits>
using namespace std;

int maxSquareWithAllZeroes(int **grid, int rows, int columns) {
		
	int len = 0;
	int maxLen = INT_MIN;

	bool flag = true;

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
		// choose the top left corner
	
			for(int length = 1; length <= min(rows - i, columns - j); length++) {
			// choose a valid length

				flag = true;
				for(int k = 0; k < length; k++) {
					for(int l = 0; l < length; l++) {
					// check if all are zeroes in the grid

						if(grid[k + i][l + j] != 0) {
							flag = false;		
						}
					}
				}

				if(flag == true) {
					if(maxLen < length) {
						maxLen = length;
					}
				}
			}
		}
	}

	return maxLen;
}

void printDP(int **dp, int rows, int columns) {
		
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			cout << dp[i][j] << " ";
		} 

		cout << endl;
	}
	
	cout << endl << endl;
}

void fillRowsColumnsDP(int **grid, int rows, int columns, int **dp) {
		
	if(grid[0][0] == 0) {
		dp[0][0] = 1;
	} else {
		dp[0][0] = 0;
	}

	// fill for the rows when the column is at 0 
	for(int i = 1; i < rows; i++) {
		if(grid[i][0] == 0) {
			dp[i][0] = 1;
		} else {
			dp[i][0] = 0;
		}
	}

	// fill for columns when the rows is at 0
	for(int i = 1; i < columns; i++) {
		if(grid[0][i] == 0) {
			dp[0][i] = 1;
		} else {
			dp[0][i] = 0;
		}
	}

	return;
}

int maxSquareWithAllZeroesDP(int **grid, int rows, int columns) {
		
	// we will find the largest square ending at [i,j] starting from [0, 0]

	int maxLength = INT_MIN;
	int **dp = new int* [rows];
	for(int i = 0; i < rows; i++) {
		dp[i] = new int[columns];
	}

	// fill for first possible square of length 1

	fillRowsColumnsDP(grid, rows, columns, dp);

	for(int i = 1; i < rows; i++) {
		for(int j = 1; j < columns; j++) {
			
			if(grid[i][j] == 1) {
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				
				int horizontalLength = 1;
				int verticalLength = 1;

				for(int k = i - 1; k >= 0; k--) {
					if(grid[k][j] == 0) {
						verticalLength++;
					} else {
						break;
					}
				}

				for(int k = j - 1; k >= 0; k--) {
					if(grid[i][k] == 0) {
						horizontalLength++;
					} else {
						break;
					}
				}
			
				int length = min(horizontalLength, verticalLength);
				dp[i][j] = min(dp[i - 1][j - 1], length) + 1;	
			}
		}
	} 

	int max = INT_MIN;
	for(int i = 0; i < rows; i++) {
			
		for(int j = 0; j < columns; j++) {
		
			if(max < dp[i][j]) {
				max = dp[i][j];			
			}
		}
	}

	for(int i = 0; i < rows; i++) {
		delete[] dp[i];
	}

	delete dp;
	return max;
}

int maxSquareWithAllZeroesBetterDP(int **grid, int rows, int columns) {
		
	int **dp = new int *[rows];
	for(int i = 0; i < rows; i++) {
		dp[i] = new int[columns];
	}

	fillRowsColumnsDP(grid, rows, columns, dp);

	for(int i = 1; i < rows; i++) {	
		for(int j = 1; j < columns; j++) {	
		
			if(grid[i][j] == 1) {
				dp[i][j] = dp[i - 1][j - 1];
			} else {

				int length = min(dp[i - 1][j], dp[i][j - 1]);
				dp[i][j] = min(length, dp[i - 1][j - 1]) + 1;
			}
		}
	}

	int max = INT_MIN;

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
				
			if(max < dp[i][j]) {
				max = dp[i][j];
			}
		}
	}

	for(int i = 0; i < rows; i++) {
		delete[] dp[i];
	}
	
	delete[] dp;
	return max;
}

int main(void) {
		
	int n, m;
	cin >> n >> m;

	int ** grid = new int* [n];
	for(int i = 0; i < n; i++) {
		grid[i] = new int[m];
		for(int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	cout << maxSquareWithAllZeroes(grid, n, m) << endl << endl;

	cout << maxSquareWithAllZeroesDP(grid, n, m) << endl << endl;

	cout << maxSquareWithAllZeroesBetterDP(grid, n, m) << endl << endl;

	for(int i = 0; i < n; i++) {
		delete[] grid[i];
	}
	
	delete[] grid;
	return 0;
}
