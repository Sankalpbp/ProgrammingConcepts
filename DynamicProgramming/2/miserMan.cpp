# include <iostream>
# include <climits>
using namespace std;

int minimumCost(int **grid, int iCity, int eCity, int iBus, int eBus) {

//	cout << "Calling (" << iCity << " " << iBus << endl;
	if(iCity == eCity) {
		return 0;
	}

	if(iBus == eBus + 1) {
		return INT_MAX;
	}

	if(iBus < 0) {
		return INT_MAX;
	}

	int option1 = minimumCost(grid, iCity + 1, eCity, iBus + 1, eBus);
	int option2 = minimumCost(grid, iCity + 1, eCity, iBus - 1, eBus);
	int option3 = minimumCost(grid, iCity + 1, eCity, iBus, eBus);
	return grid[iCity][iBus] + min(option3, min(option1, option2));
}

int minimumCost(int **grid, int iCity, int eCity, int iBus, int eBus, int **memo) {
		
	if(iCity == eCity) {
		return 0;
	}

	if(iBus == eBus + 1) {
		return INT_MAX;
	}

	if(iBus < 0) {
		return INT_MAX;
	}

	if(memo[iCity][iBus] > -1) {
		return memo[iCity][iBus];
	}

	int option1, option2, option3;
	option1 = minimumCost(grid, iCity + 1, eCity, iBus + 1, eBus, memo);
	option2 = minimumCost(grid, iCity + 1, eCity, iBus - 1, eBus, memo);
	option3 = minimumCost(grid, iCity + 1, eCity, iBus, eBus, memo);

	memo[iCity][iBus] = grid[iCity][iBus] + min(option1, min(option2, option3));
	return memo[iCity][iBus];
}

int minimumCostDP(int **grid, int n, int m) {
		
	int **dp = new int* [n + 1];
	for(int i = 0; i <= n; i++) {
		dp[i] = new int[m];

		for(int j = 0; j < m; j++) {
			dp[i][j] = 0;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
				
			dp[i + 1][j] = grid[i][j] + dp[i][j];

			if(j > 0) {
				dp[i + 1][j] = min(dp[i + 1][j], grid[i][j] + dp[i][j - 1]);
			}

			if(j < m - 1) {
				dp[i + 1][j] = min(dp[i + 1][j], grid[i][j] + dp[i][j + 1]);
			}
		}
	}

	int answer = INT_MAX;
	for(int i = 0; i < m; i++) {
		if(answer > dp[n][i]) {
			answer = dp[n][i];
		}
	}

	for(int i = 0; i <= n; i++) {
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

	cout << endl << endl;
	cout << minimumCost(grid, 0, n - 1, 0, m - 1) << endl << endl;
	int **memo = new int* [n];
	for(int i = 0; i < n; i++) {
		memo[i] = new int[m];
		for(int j = 0; j < m; j++) {
			memo[i][j] = -1;
		}
	}
	cout << minimumCost(grid, 0, n -1, 0, m - 1, memo) << endl << endl;
	cout << minimumCostDP(grid, n, m) << endl << endl;
	return 0;
}
