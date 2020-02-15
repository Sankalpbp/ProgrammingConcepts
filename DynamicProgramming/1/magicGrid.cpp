# include <iostream>
# include <limits.h>
using namespace std;

int magicGrid(int **grid, int startX, int startY, int endX, int endY) {

	if(startX > endX || startY > endY) {
		return INT_MAX;
	}

	if(startX == endX and startY == endY) {
		return 1;
	}

	if(startX == endX - 1 and startY == endY) {
		return 1;
	}

	if(startX == endX and startY == endY - 1) {
		return 1;
	}

	int firstWay = magicGrid(grid, startX + 1, startY, endX, endY);
	if(startX + 1 <= endX) {
		firstWay -= grid[startX + 1][startY];
	}
	
	int secondWay = magicGrid(grid, startX, startY + 1, endX, endY);
	if(startY + 1 <= endY) {
		secondWay -= grid[startX][startY + 1];
	}


	int answer = min(firstWay, secondWay);

	if(answer > 1) {
		return answer;
	}

	return 1;
}

int magicGrid(int **grid, int startX, int startY, int endX, int endY, int **memo) {
		
	if(startX > endX or startY > endY) {
		return INT_MAX;
	}

	if(startX == endX and startY == endY) {
		return 1;
	}

	if(startX == endX and startY == endY - 1) {
		return 1;
	}

	if(startX == endX - 1 and startY == endY) {
		return 1;
	}

	if(memo[startX][startY] > 0) {
		return memo[startX][startY];
	}

	int firstWay = magicGrid(grid, startX + 1, startY, endX, endY, memo);
	if(startX + 1 <= endX) {
		firstWay -= grid[startX + 1][startY];
	}

	int secondWay = magicGrid(grid, startX, startY + 1, endX, endY, memo);
	if(startY + 1 <= endY) {
		secondWay -= grid[startX][startY + 1];
	}

	int answer = min(firstWay, secondWay);
	if(answer > 1) {
		memo[startX][startY] = answer;
		return answer;
	}

	memo[startX][startY] = 1;
	return memo[startX][startY];
}

int magicGridDP(int **grid, int rows, int columns) {
		
	int **dp = new int* [rows];
	for(int i = 0 ; i < rows; i++) {
			
		dp[i] = new int[columns];
		for(int j = 0; j < columns; j++) {
			dp[i][j] = 0;
		}
	}

	dp[rows - 1][columns - 1] = 1;
	dp[rows - 1][columns - 2] = 1;
	dp[rows - 2][columns - 1] = 1;

	for(int i = rows - 3; i >= 0; i--) {
		dp[i][columns - 1] = dp[i + 1][columns - 1] - grid[i + 1][columns - 1];
		
		if(dp[i][columns - 1] < 0) {
			dp[i][columns - 1] = 1;
		}
	}

	for(int i = columns - 3; i >= 0; i--) {
		dp[rows - 1][i] = dp[rows - 1][i + 1] - grid[rows - 1][i + 1];

		if(dp[rows - 1][i] < 0) {
			dp[rows - 1][i] = 1;
		}
	}

	for(int i = rows - 2; i >= 0; i--) {
		for(int j = columns - 2; j >= 0; j--) {
			dp[i][j] = min(dp[i + 1][j] - grid[i + 1][j], dp[i][j + 1] - grid[i][j + 1]);	

			if(dp[i][j] < 0) {
				dp[i][j] = 1;
			}
		}
	}

	int answer = dp[0][0];

	for(int i = 0; i < rows; i++) {
		delete[] dp[i];	
	}
	
	delete dp;

	return answer;
}

int main(void) {
		
	int t;
	cin >> t;

	while(t--) {
			
		int n, m;
		cin >> n >> m;

		int **grid = new int* [n];
		for(int i = 0; i < n; i++) {
			grid[i] = new int[m];
			
			for(int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}

		cout << magicGrid(grid, 0, 0, n - 1, m - 1) << endl << endl;

		int **memo = new int* [n];
		for(int i = 0; i < n; i++) {
			memo[i] = new int[m];
			for(int j = 0; j < m; j++) {
				memo[i][j] = 0;
			}
		}
		cout << magicGrid(grid, 0, 0, n - 1, m - 1, memo) << endl << endl;
		cout << magicGridDP(grid, n, m) << endl << endl;

		for(int i = 0; i < n; i++) {
			delete[] grid[i];
		}

		delete[] grid;	
	}

	cout << endl << endl;
	return 0;
}
