# include <iostream>
using namespace std;

int fibonacci(int n) {

	if(n == 0) {
		return 0;
	} if(n == 1 || n == 2) {
		return 1;
	} 

	return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacci(int n, int *arr) {

	if(n == 0) {
		return 0;
	} if(n == 1 || n == 2) {
		return 1;
	}

	if(arr[n] > 0) {
		return arr[n];
	}

	int output = fibonacci(n - 1, arr) + fibonacci(n - 2, arr);
	arr[n] = output;

	return arr[n];
}

int fibonacciDP(int n) {
		
	int *dp = new int[n + 1];

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	for(int i = 2; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
	}

	int output = dp[n];
	delete[] dp;

	return output;
}

int main(void) {

	int n;
	cin >> n;

	int *arr = new int[n + 1];
	for(int i = 0; i < n; i++) {
		arr[i] = 0;
	}

	cout << fibonacci(n) << endl << endl;
	cout << fibonacci(n, arr) << endl << endl;
	cout << fibonacciDP(n) << endl << endl;	
	delete[] arr;
	return 0;
}
