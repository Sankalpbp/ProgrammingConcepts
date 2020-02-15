# include <iostream>
using namespace std;

int staircase(int n) {
		
	if(n == 0 || n == 1) {
		return 1;
	}
	
	if(n == 2) {
		return 2;
	}

	if(n == 3) {
		return 4;
	}

	return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
}

int staircase(int n, int *memo) {
		
	if(n == 0 || n == 1) {
			
		return 1;
	}

	if(n == 2) {
			
		return 2;
	}

	if(n == 3) {
			
		return 4;
	}

	if(memo[n] > 0) {
		return memo[n];
	}

	int output = staircase(n - 1, memo) + staircase(n - 2, memo) + staircase(n - 3, memo);
	memo[n] = output;

	return memo[n];
}

int staircaseDP(int n) {
		
	int *dp = new int[n + 1];
	for(int i=0; i <= n; i++) {
		dp[i] = 0;
	}

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for(int i = 4; i <= n; i++) {
			
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	int output = dp[n];
	
	delete[] dp;

	return output;
}

int main(void) {
		
	int n;
	cin >> n;

	int *memo = new int[n];
	for(int i=0; i<n; i++) {
		memo[i] = 0;
	}
	cout << staircase(n) << endl << endl;
	cout << staircase(n, memo) << endl << endl;
	cout << staircaseDP(n) << endl << endl;

	delete[] memo;
	return 0;
}
