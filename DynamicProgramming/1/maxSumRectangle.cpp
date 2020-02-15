# include <iostream>
# include <limits.h>
using namespace std;

int maxSumRectangle(int **grid, int startX, int startY, int endX, int endY) {
		
	int sum = 0;
	int maxSum = INT_MIN;

	for(int i = startX; i <= endX; i++) {
		for(int j = startY; j <= endY; j++) {
			// find the top left point
				
			for(int k = i + 1; k <= endX; k++) {
				for(int l = j + 1; l <= endY; l++) {
				// find the right bottom point
			
					sum = 0;
					for(int m = i; m <= k; m++) {
						for(int n = j; n <= l; n++) {
						// find the sum of the rectangle formed
							
							sum += grid[m][n];
						}
					}

					if(sum > maxSum) {
						maxSum = sum;
					}
				}
			}
		}
	}

	return maxSum;
}

int kadanesAlgo(int *dp, int n) {
		
	int best = INT_MIN;
	int current = 0;

	for(int i = 0; i < n; i++) {
		
		current += dp[i];
		if(current < 0) {
			current = 0;
		}

		if(current > best) {
			best = current;
		}
	}

	return best;
}

int maxSumRectangleDP2(int **grid, int rows, int columns) {
		
	int kadane = 0;
	int max = INT_MIN;

	int *dp = new int[columns];

	for(int left = 0; left < rows; left++) {

		for(int j = 0; j < columns; j++) {
			dp[j] = grid[left][j];		
		}
	
		int kadane = kadanesAlgo(dp, columns);
		if(kadane > max) {
			max = kadane;
		}
		for(int right = left + 1; right < rows; right++) {
				
			for(int i = 0; i < columns; i++) {
				dp[i] += grid[right][i];
			}

			kadane = kadanesAlgo(dp, columns);
			if(kadane > max) {
				max = kadane;
			}
		}
	}

	return max;
}

int maxSumRectangleDP1(int startX, int startY, int endX, int endY, int **dp) {
	
	int sum = 0;
	int maxSum = INT_MIN;

	for(int i = startX; i < endX; i++) {
		for(int j = startY; j < endY; j++) {
			// choose a top left corner

			for(int k = i + 1; k <= endX; k++) {
				for(int l = j + 1; l <= endY; l++) {
					// choose a right bottom corner	

					if(k == endX and l == endY) {
						sum = dp[i][j];
					} else if(k == endX) {
						sum = dp[i][j] - dp[i][l + 1];
					} else if(l == endY) {
						sum = dp[i][j] - dp[k + 1][j];
					} else {
						sum = dp[i][j] - dp[k + 1][j] - dp[i][l + 1] + dp[k + 1][l + 1];	
					}				

					if(sum > maxSum) {
						maxSum = sum;
					}
				}
			}
		}
	}

	return maxSum;
}

void printDP(int **dp, int n, int m) {
	
	cout << endl << endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << dp[i][j] << "\t";
		}
		cout << "\n";
	}

	cout << endl << endl;
}

int maxSumRectangleDP1(int **grid, int n, int m) {
	
	int **dp = new int* [n];
	for(int i = 0; i < n; i++) {		
		dp[i] = new int[m];
	}

	dp[n - 1][m - 1] = grid[n - 1][m - 1];
	
	// fill last row
	for(int i = m - 2; i >= 0; i--) {
		dp[n - 1][i] = dp[n - 1][i + 1] + grid[n - 1][i];
	}

	// fill last column
	for(int i = n - 2; i >= 0; i--) {
		dp[i][m - 1] = dp[i + 1][m - 1] + grid[i][m - 1];	
	}

	// fill the remaining dp grid, column wise;

//	printDP(dp, n, m);
	for(int i = n - 2; i >= 0; i--) {
		for(int j = m - 2; j >= 0; j--) {
			
			dp[i][j] = dp[i + 1][j] + (dp[i][j + 1] - dp[i + 1][j + 1]) + grid[i][j];
		}
	}

//	printDP(dp, n, m);
	// this has completed the initial work

	int answer = maxSumRectangleDP1(0, 0, n - 1, m - 1, dp);

	for(int i = 0; i < n; i++) {
		delete[] dp[i];
	}

	delete[] dp;

	return answer;
}

int main(void) {
		
	int n, m;
	cin >> n >> m;

	int **grid = new int* [n];
	for(int i = 0; i < n; i++) {
		grid[i] = new int[m];
		for(int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	cout << maxSumRectangle(grid, 0, 0, n - 1, m - 1) << endl << endl;

	cout << maxSumRectangleDP1(grid, n, m) << endl << endl;

	cout << maxSumRectangleDP2(grid, n, m) << endl << endl;
	return 0;
}
