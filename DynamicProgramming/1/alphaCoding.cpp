// try to print each code while measuring the number of alpha codes

# include <iostream>
using namespace std;

int numberOfAlphaCodes(int *n, int size) {
		
	if(size == 1) {
		return 1;
	}
	
	if(size == 0) {
			
		return 1;
	}

	int output = numberOfAlphaCodes(n, size - 1);

	if(n[size - 2] * 10 + n[size - 1] <= 26) {
			output += numberOfAlphaCodes(n, size - 2);
	}

	return output;
}

int numberOfAlphaCodes(int *n, int size, int *memo) {
		
	if(size == 1) {
		return 1;
	}

	if(size == 0) {
		return 1;
	}

	if(memo[size] > 0) {
		return memo[size];
	}

	int output = numberOfAlphaCodes(n, size - 1, memo);
	if(n[size - 2] * 10 + n[size - 1] <= 26) {

		output += numberOfAlphaCodes(n, size - 2, memo);
	}

	memo[size] = output;

	return output;
}

int numberOfAlphaCodesDP(int *n, int size) {
		
	long *dp = new long[size + 1];
	dp[0] = 1;
	dp[1] = 1;
	
	for(int i = 2; i < size + 1; i++) {
		
		dp[i] = dp[i - 1];
		if(n[size - 2] * 10 + n[size - 1] <= 26) {
				
			dp[i] += dp[i - 2];
		}
	}

	cout << endl << endl;
	long output = dp[size];
	delete[] dp;
	return output;
}

int returnModValue(int *n, int size) {
		
	return numberOfAlphaCodesDP(n, size) % (1000000007);
}

int main(void) {
		
	int size;
	cin >> size;

	int *n = new int[size];

	for(int i = 0; i < size; i++) {
		
		cin >> n[i];
	}
	cout << numberOfAlphaCodes(n, size) << endl << endl;

	int *memo = new int[size + 1];
	for(int i = 0; i <= size; i++) {
		memo[i] = 0;			
	}
	cout << numberOfAlphaCodes(n, size, memo);
	cout << endl << endl;

	cout << numberOfAlphaCodesDP(n, size) << endl << endl;
	cout << returnModValue(n, size) << endl << endl;
	delete[] memo;
	delete[] n;
	return 0;
}
