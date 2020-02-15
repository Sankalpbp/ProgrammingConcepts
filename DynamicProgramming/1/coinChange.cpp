# include <iostream>
using namespace std;

int coinChange(int money, int *denominations, int numberOfDenominations) {
		
	if(money == 0) {
		return 1;
	}

	if(numberOfDenominations == 0) {
		return 0;
	}

	if(money < 0) {
		return 0;
	}

	int firstWay = coinChange(money - denominations[0], denominations, numberOfDenominations);
	int secondWay = coinChange(money, denominations + 1, numberOfDenominations - 1);

	return firstWay + secondWay;
}

int coinChange(int money, int *denominations, int numberOfDenominations, int **memo) {
		
	if(money == 0) {
		return 1;
	}

	if(numberOfDenominations == 0) {
		return 0;
	}

	if(money < 0) {
		return 0;
	}
	if(memo[money][numberOfDenominations] > -1) {
		return memo[money][numberOfDenominations];
	}

	int firstWay = coinChange(money - denominations[0], denominations, numberOfDenominations, memo);
	int secondWay = coinChange(money, denominations + 1, numberOfDenominations - 1, memo);

	memo[money][numberOfDenominations] = firstWay + secondWay;
	return firstWay + secondWay;
}

int coinChangeDP(int money, int *denominations, int numberOfDenominations) {
	
	int **dp = new int* [money + 1];
	for(int i = 0; i <= money; i++) {
		dp[i] = new int[numberOfDenominations + 1];
	}

	for(int i = 0; i <= numberOfDenominations; i++) {
		dp[0][i] = 1;
	}

	for(int i = 1; i <= money; i++) {
		dp[i][0] = 0;
	}

	for(int i = 1; i <= money; i++) {
		for(int j = 1; j <= numberOfDenominations; j++) {
			dp[i][j] = dp[i][j - 1];
			
			if(i - j >= 0) {
				dp[i][j] += dp[i - j][j];
			}
		}
	}

	for(int i =0; i<= money; i++) {
		for(int j = 0; j <= numberOfDenominations; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n\n";
	}
	int ans = dp[money][numberOfDenominations];

	for(int i = 0; i <= money; i++) {
		delete[] dp[i];
	}

	delete[] dp;

	return ans;
}

int main(void) {
		
	int money;
	cin >> money;

	int numberOfDenominations;
	cin >> numberOfDenominations;

	int *denominations = new int[numberOfDenominations];
	for(int i = 0; i < numberOfDenominations; i++) {
			
		cin >> denominations[i];
	}

	cout << coinChange(money, denominations, numberOfDenominations) << endl << endl;

	int **memo = new int* [money + 1];
	for(int i = 0; i <= money; i++) {
		memo[i] = new int[numberOfDenominations + 1];
		for(int j = 0; j <= numberOfDenominations; j++) {
			memo[i][j] = -1;
		}
	}

	cout << coinChange(money, denominations, numberOfDenominations, memo) << endl << endl;

	cout << coinChangeDP(money, denominations, numberOfDenominations) << endl << endl;
	return 0;
}
