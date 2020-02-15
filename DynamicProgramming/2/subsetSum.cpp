# include <iostream>
using namespace std;

bool subsetSum(int *arr, int n, int requiredSum) {
		
	if(requiredSum == 0) {
		return true;
	}

	if(requiredSum < 0) {
		return false;
	}

	if(n == 0) {
		return false;
	}

	bool option1 = subsetSum(arr, n - 1, requiredSum); // exclude last element
	bool option2 = subsetSum(arr, n - 1, requiredSum - arr[n - 1]);	// include last element 
			
	return option1 || option2;
}

int subsetSum(int *arr, int n, int requiredSum, int **memo) {
		
	if(requiredSum == 0) {
		return 1;
	}

	if(requiredSum < 0) {
		return 0;
	}

	if(n == 0) {
		return 0;
	}

	if(memo[n][requiredSum] > -1) {
		return memo[n][requiredSum];
	}

	int option1 = subsetSum(arr, n - 1, requiredSum, memo);	// exclude last element
	int option2 = subsetSum(arr, n - 1, requiredSum - arr[n - 1], memo);	// include last element

	return option1 || option2;
}

void print(bool **dp, int n, int requiredSum) {
		
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < requiredSum; j++) {
			cout << dp[i][j] << "  ";
		}

		cout << endl;
	}

	cout << endl << endl;
}

void subsetSumDP(int *arr, int n, int requiredSum) {
		
	bool **dp = new bool* [n + 1];
	for(int i = 0; i <= n; i++) {
		dp[i] = new bool[requiredSum + 1];
	}

	// if there is no element, and the required sum is 0, then, there is only one possiility
	dp[0][0] = 1;

	// if there are no elements, then, no sum is possible
	for(int i = 1; i <= requiredSum; i++) {
		dp[0][i] = false;
	}

	// if the requred sum is zero, then, any number of elements can form the required sum
	for(int i = 1; i <= n; i++) {
		dp[i][0] = true;
	}

	print(dp, n, requiredSum);

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= requiredSum; j++) {
			
			dp[i][j] = dp[i - 1][j];

			if(j >= arr[i - 1]) {
				dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
			}
		}
	}

	bool answer = dp[n][requiredSum];

	for(int i = 0; i <= n; i++) {
		delete[] dp[i];
	}

	delete[] dp;

	if(answer) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

int main(void) {
	
	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int requiredSum;
	cin >> requiredSum;

	if(subsetSum(arr, n, requiredSum)) {
		cout << "True\n";
	} else {
		cout << "False\n";
	}

	int ** memo = new int* [n + 1];
	for(int i = 0; i <= n; i++) {
		memo[i] = new int[requiredSum];
		for(int j = 0; j <= requiredSum; j++) {
			memo[i][j] = -1;
		}
	}

	if(subsetSum(arr, n, requiredSum, memo)) {
		cout << "True\n";	
	} else {
		cout << "False\n";
	}

	cout << endl << endl;

	subsetSumDP(arr, n, requiredSum);
	return 0;
}
