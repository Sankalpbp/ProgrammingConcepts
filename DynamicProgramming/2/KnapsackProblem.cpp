# include <iostream>
using namespace std;

int knapsack(int maxWeight, int *weight, int *value, int n) {
		
	if(maxWeight == 0) {
		return 0;
	}

	if(n == 0) {
		return 0;
	}

	if(weight[n - 1] > maxWeight) {
		return knapsack(maxWeight, weight, value, n - 1);
	}

	return max(value[n - 1] + knapsack(maxWeight - weight[n - 1], weight, value, n - 1), knapsack(maxWeight, weight, value, n - 1));
}

int knapsack(int maxWeight, int *weight, int *value, int n, int **memo) {
		
	if(maxWeight == 0) {
		return 0;
	}

	if(n == 0) {
		return 0;
	}

	if(memo[n][maxWeight] > -1) {
		return memo[n][maxWeight];
	}
		
	if(weight[n - 1] > maxWeight) {
		memo[n][maxWeight] = knapsack(maxWeight, weight, value, n -1, memo);
		return memo[n][maxWeight]; 
	}

	memo[n][maxWeight] = max(value[n - 1] + knapsack(maxWeight - weight[n - 1], weight, value, n - 1), knapsack(maxWeight, weight, value, n - 1));
	return memo[n][maxWeight];
}

void print(int **dp, int n, int w) {
		
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= w; j++) {
			cout << dp[i][j] << "  ";
		}

		cout << endl;
	}

	cout << endl << endl;
}

int knapsackDP(int maxWeight, int *weight, int *value, int n) {
		
	int **dp = new int* [n + 1];

	for(int i = 0; i <= n; i++) {
		dp[i] = new int[maxWeight + 1];
	}

	// as for no items, there would be no profit and for 0 weight of the knapsack, there would be no profit
	
	for(int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}

	for(int i = 0; i <= maxWeight; i++) {
		dp[0][i] = 0;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= maxWeight; j++) {
			
			dp[i][j] = dp[i - 1][j];
			if(weight[i - 1] <= j) {
				dp[i][j] = max(dp[i][j], value[i - 1] + dp[i - 1][maxWeight - weight[i - 1]]);
			}
		}
	}

	print(dp, n, maxWeight);
	int answer = dp[n][maxWeight];

	for(int i = 0; i <= n; i++) {
		delete[] dp[i];
	}

	delete[] dp;

	return answer;
}

int main(void) {
		
	int n;
	cin >> n;

	int *weight = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> weight[i];
	}

	int *value = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> value[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(maxWeight, weight, value, n) << endl << endl;

	int **memo = new int* [n + 1];
	for(int i = 0; i <= n; i++) {
		memo[i] = new int[maxWeight + 1];

		for(int j = 0; j <= maxWeight; j++) {
			memo[i][j] = -1;
		}
	}
	
	cout << knapsack(maxWeight, weight, value, n, memo) << endl << endl;

	for(int i = 0; i <= n; i++)  {
		delete[] memo[i];
	}
	delete[] memo;

	cout << knapsackDP(maxWeight, weight, value, n) << endl << endl;

	delete[] weight;
	delete[] value;
	return 0;
}
