# include <iostream>
# include <limits.h>
using namespace std;

int minCost(int **input, int startingX, int startingY, int endingX, int endingY) {
		
	if(startingX == endingX && startingY == endingY) {
		return input[endingX][endingY];
	}

	if(startingX > endingX || startingY > endingY) {
		return INT_MAX;
	}

	int firstWay = minCost(input, startingX + 1, startingY, endingX, endingY);
	int secondWay = minCost(input, startingX + 1, startingY + 1, endingX, endingY);
	int thirdWay = minCost(input, startingX, startingY + 1, endingX, endingY);

	return input[startingX][startingY] + min(firstWay , min(secondWay, thirdWay));
}

int minCost(int **input, int startingX, int startingY, int endingX, int endingY, int **memo) {
		
	if(startingX == endingX && startingY == endingY) {
			
		return input[endingX][endingY];
	}

	if(startingX > endingX || startingY > endingY) {
			
		return INT_MAX;
	}

	if(memo[startingX][startingY] > 0) {
		return memo[startingX][startingY];
	}

	int firstWay = minCost(input, startingX + 1, startingY, endingX, endingY);
	int secondWay = minCost(input, startingX + 1, startingY + 1, endingX, endingY);
	int thirdWay = minCost(input, startingX, startingY + 1, endingX, endingY);

	int output = input[startingX][startingY] + min(firstWay, min(secondWay, thirdWay));
	memo[startingX][startingY] = output;

	return output;
}

int minCostDP(int **input, int rows, int columns) {
	
	int **dp = new int* [rows];
	for(int i = 0; i < rows; i++) {
		dp[i] = new int[columns];
	}

	dp[rows - 1][columns - 1] = input[rows - 1][columns - 1];

	for(int i = rows - 2; i >= 0; i--) {
		dp[i][columns - 1] = input[i][columns - 1] + dp[i + 1][columns - 1];
	}

	for(int i = columns - 2; i >= 0; i--) {
		dp[rows - 1][i] = input[rows - 1][i] + dp[rows - 1][i + 1];
	}

	for(int i = 0; i < rows; i ++) {
			for(int j = 0; j < columns ; j++) {
					cout << dp[i][j] << "  ";
			}
			cout << endl;
	}

	for(int i = rows - 2; i >= 0; i--) {
		for(int j = columns - 2; j >= 0; j--) {
			
			dp[i][j] = input[i][j] + min(dp[i + 1][j], min(dp[i + 1][j + 1], dp[i][j + 1]));
		}
	}

	int ans = dp[0][0];
	
	cout << endl << endl;
	for(int i = 0; i < rows; i++) {
		delete[] dp[i];
	}

	delete[] dp;
	return ans;
}

int main(void) {
		
	int n, m; 
	cin >> m >> n;

	int ** input = new int* [m];
	for(int i = 0; i < m; i++) {
		input[i] = new int[n];
		for(int j = 0; j < n; j++) {
			cin >> input[i][j];
		}
	}

	cout << minCost(input, 0, 0, m - 1, n - 1) << endl << endl;

	int **memo = new int* [m];
	for(int i = 0; i < m; i++) {
		memo[i] = new int[n];
	}

	cout << minCost(input, 0, 0, m - 1, n - 1, memo) << endl << endl;

	cout << minCostDP(input, m, n) << endl << endl;
	for(int i = 0; i < m; i++) {
			
		delete[] input[i];
	}

	delete[] input;
	return 0;
}
