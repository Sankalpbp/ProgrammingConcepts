# include <iostream>
using namespace std;

int max(int *dp, int n) {
		
	int m = dp[0];

	for(int i = 1; i  < n; i++) {
		if(dp[i] > m) {
			m = dp[i];
		}
	}

	return m;
}

void printArray(int *arr, int n) {
		
	for(int i = 0; i < n; i++) {
			
		cout << arr[i] << "  ";
	}

	cout << endl << endl;
}

void coinBoxes(int *frequencyStart, int *frequencyEnd, int n) {
		
	int *dp = new int[n + 1];

	dp[0] = 0;
	dp[1] = frequencyStart[1];

	// this dp array contains the number of coins in the box denoted by the index
	for(int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + frequencyStart[i] - frequencyEnd[i - 1];
	}

	// another array will contain the number of boxes containing index number of coins, that is, number of coins denoted by the index
	int maxCoins = max(dp, n + 1);
	int *anotherDP = new int[maxCoins + 1];

	for(int i = 0; i <= n; i++) {
		anotherDP[dp[i]]++;
	}

//	delete[] dp;
	// now we have an array which contains the number of boxes with certain number of coins
	// from here, we can extract the number of coins with atleast certain number of coins
	
	for(int i = maxCoins - 2; i >= 0; i--) {
		anotherDP[i] += anotherDP[i + 1];
	}

	printArray(dp, n);
	printArray(anotherDP, maxCoins);
	int coins;
	cin >> coins;

	while(coins != 0) {
		cout << dp[coins] << endl;
		cin >> coins;
	}
}


int main(void) {
		
	int n;
	cin >> n;

	int *arr = new int[n + 1];

	int m;
	cin >> m;

	int left, right;

	int *frequencyStart = new int[n + 1];
	int *frequencyEnd = new int[n + 1];

	for(int i = 0; i < m; i++) {
			
		cin >> left >> right;
		frequencyStart[left]++;
		frequencyEnd[right]++;
	}

	printArray(frequencyStart, n + 1);
	printArray(frequencyEnd, n + 1);
	
	coinBoxes(frequencyStart, frequencyEnd, n);

	cout << endl << endl;
	return 0;
}
