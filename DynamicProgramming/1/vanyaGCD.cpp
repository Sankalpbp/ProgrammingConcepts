# include <iostream>
# include <math.h>
# include <vector>
using namespace std;

int gcd(int a, int b) {

	if(a == 0 && b == 0) {
		return 0;
	}

	if(a == 0) {
		return b;
	}

	if(b == 0) {
		return a;
	}

	if(a > b) {
		return gcd(a % b, b);
	} 

	return gcd(a, b % a);
}

int gcdVector(vector<int> v) {
		
	int Gcd = gcd(v[0], v[1]);

	int size = v.size();

	for(int i = 2; i < size; i++) {
		Gcd = gcd(Gcd, v[i]);
	}

//	cout << "(" << Gcd << ")";
	return Gcd;
}

int returnSubsequences(int *arr, int n, vector<int> *output) {
		
	if(n == 0) {
		return 1;
	}

	int smallOutput = returnSubsequences(arr + 1, n - 1, output);

	for(int i = 0; i < smallOutput; i++) {
			
		vector<int> a = output[i];
		a.push_back(arr[0]);
		output[i + smallOutput] = a;
	}

	return 2 * smallOutput;
}

bool increasingSubsequence(vector<int> v) {

	int n = v.size();

	for(int i = 0; i < n - 1; i++) {
		if(v[i] < v[i + 1]) {
			return false;
		}
	}

	return true;
}

int gcdNumbers(int *input, int n) {
		
	int outputLength = pow(2, n);

	// avoid using vectors if you can. Or figure out a way to access consecutive elements of a vector at a time
	vector<int> *output = new vector<int> [outputLength];

	int subs = returnSubsequences(input, n, output);

//	for(int i = 0; i < outputLength; i++) {
//		for(auto it = output[i].begin(); it != output[i].end(); it++ ) {
//			cout << *it << " ";
//		}
//		cout << endl;
//	}

	int answer = 0;
	for(int i = 0; i < outputLength; i++) {
	
		if(output[i].empty() == false) {
			if(increasingSubsequence(output[i]) && gcdVector(output[i]) == 1) {
				answer++;
			}
		}
	}

	return answer;
}

void printDP(int **dp, int n) {
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 101; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;
}

int gcdNumbersDP(int *input, int n) {
		
	// the dp array containing indices as the rows and gcd as the columns
	
	int **dp = new int *[n];
	for(int i = 0; i < n; i++) {
		dp[i] = new int[101];
		for(int j = 0; j < 101; j++) {
			dp[i][j] = 0;
		}
	}

	// first fill the first row, that is when there is only one element in the subsequence, the single number itself
	
	for(int i = 1; i <= 100 ; i++) {
		dp[0][i] = gcd(input[0], i);
	}

	printDP(dp, n);
	// dp[ending at index this][with gcd this]
	// our dp matrix stores the number of elements with certain gcd ending at this index
	// ignore first column

	for(int i = 1; i < n; i++) {
		// go through the rows, indices, essentially
		
		for(int k = i - 1; k >= 0; k--) {
			// go through all of the previous elements

			if(input[k] < input[i]) {
			// check for if input[i] maintains the increasing subsequence property	
			
				for(int Gcd = 1; Gcd <= 100; Gcd++) {
					// find the number of subsequences ending at input[k] with GCD = gcd

					int newGCD = gcd(input[i], Gcd);
					dp[i][newGCD] += dp[k][Gcd];
				}
			}
		}
	}

	printDP(dp, n);
	int sum = 0;
	for(int i = 0; i < n; i++) {
		// sum of the count of the elements with gcd = 1
		sum += dp[i][1];
	}

	for(int i = 0; i < n; i++) {
		delete[] dp[i];
	}
	delete dp;

	return sum;
}

int main(void) {
	
	int n;
	cin >> n;

	int *input = new int[n];
	for(int i = 0 ; i < n; i++) {
		cin >> input[i];
	}

//	cout << gcdNumbers(input, n) << endl << endl;
	
	cout << gcdNumbersDP(input, n) << endl << endl;

	return 0;
}
