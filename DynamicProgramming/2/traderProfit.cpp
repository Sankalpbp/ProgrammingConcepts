# include <iostream>
using namespace std;

int profit(int n, int k, int *arr, bool ongoing) {
		
	if(n == 0) {
		return 0;
	}

	// ignore doing anything with the stock, neither buy, nor sell
	int option1 = 0;
	int option2 = 0;
	int option3 = 0;

	option1 = profit(n - 1, k, arr + 1, ongoing);

	// transaction will only end, when the stock will be sold, not when bought
	// if the transaction was already alive
	if(ongoing) {
		option2 = profit(n - 1, k - 1, arr + 1, !ongoing) + arr[0];
	} else {
		if(k > 0) {
			option3 = profit(n - 1, k, arr + 1, !ongoing) - arr[0];
		}
	}

//	cout << option1 << " " << option2 << "  " << option3 << endl << endl;
	return max(option1, max(option2, option3));
}

int profit(int n, int k, int *arr, int ongoing, int ***memo) {
		
	if(n == 0) {
		return 0;
	}

	if(memo[n][k][ongoing] > -1) {
		return memo[n][k][ongoing];
	}

	int option1 = 0;
	int option2 = 0;
	int option3 = 0;

	option1 = profit(n - 1, k, arr + 1, ongoing, memo);

	// transaction will only end, when the stock will be sold, not when bought
	// if the transaction was already alive
	if(ongoing) {
		option2 = profit(n - 1, k - 1, arr + 1, !ongoing, memo) + arr[0];
	} else {
		if(k > 0) {
			option3 = profit(n - 1, k, arr + 1, !ongoing, memo) - arr[0];
		}
	}
	
	memo[n][k][ongoing] = max(option1, max(option2, option3));
	cout << option1 << " " << option2 << "  " << option3 << endl << endl;
	return memo[n][k][ongoing];
}

void print(int ***dp, int n, int k) {
	
	for(int l = 0; l < 2; l++) {
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= k; j++) {
			cout << dp[i][j][l] << "  ";
		}

		cout << endl;
	}
		cout << endl << endl;
	}
}

int profitDP(int n, int k, int *arr) {
		
	int ***dp = new int** [n + 1];
	for(int i = 0; i <= n; i++) {
		dp[i] = new int* [k + 1];
		for(int j = 0; j <= k; j++) {
			dp[i][j] = new int[2];
			for(int l = 0; l < 2; l++) {
				dp[i][j][l] = 0;
			}
		}
	}

	// for if the days are over, there can be no profit to be earned
	for(int i = 0; i <= k; i++) {
		for(int j = 0; j < 2; j++) {
			dp[0][i][j] = 0;
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			for(int l = 0; l < 2; l++) {

				dp[i][j][l] = dp[i - 1][j][l];

				if(l == 0) {
					dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][!l] - arr[i - 1]);
				} 

				if(l == 1) {
					dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - 1][!l] + arr[i - 1]);
				}
			}
		}
	}

	print(dp, n, k);
	cout << dp[n][k][0] << "  " << dp[n][k][1] << endl << endl;
	int answer = max(dp[n][k][0], dp[n][k][1]);

	return answer;
}

int main(void) {

	int k;
	cin >> k;

	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// as any transaction hasn't started yet
	cout << profit(n, k, arr, false) << endl << endl;

	int ***memo = new int** [n + 1];
	for(int i = 0; i <= n; i++) {
		memo[i] = new int* [k + 1];
		for(int j = 0; j <= k; j++) {
			memo[i][j] = new int[2];
			for(int l = 0; l < 2; l++) {
				memo[i][j][l] = -1;
			}
		}
	}

	cout << profit(n, k, arr, 0, memo) << endl << endl;

	print(memo, n, k);
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= k; j++) {
			delete[] memo[i][j];
		}
		delete[] memo[i];
	}
	delete[] memo;

	cout << profitDP(n, k, arr) << endl << endl;
	delete[] arr;
	return 0;
}
