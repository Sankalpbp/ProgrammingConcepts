# include <iostream>
# include <climits>
# include <algorithm>
using namespace std;

void print(int *arr, int n) {
		
	for(int i = 0; i < n; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl << endl;
}

int minimumAbsoluteDifference(int *arr, int n, int k) {

	print(arr, n);
	int minDifference = INT_MAX;
	for(int i = 0; i < (n - k); i++) {
	
		int difference = 0;

		for(int j = i; j < i + k; j++) {
			for(int l = j + 1; l < (i + k); l++) {
				difference += abs(arr[j] - arr[l]);
			}
		}

		if(minDifference > difference) {
			minDifference = difference;
		}
	}

	return minDifference;
}

int minimumAbsoluteDifferenceDP(int *arr, int n, int k) {
		
	// we need two dp arrays
	
	// first : contatining the difference at ith, which will be used to find the value for the (i + 1)th
	int *dp = new int[n];
	// second : containing the sum of the array till here
	int *sumTillHere = new int[n];

	// fill the rest of the sumTillHere array
	sumTillHere[0] = arr[0];
	for(int i = 1; i < n; i++) {
		sumTillHere[i] = sumTillHere[i - 1] + arr[i];
	}

	dp[0] = 0;

	// as the method of finding the difference sum for the first k elements is different than others, lets compute that first
	int previousDifference = 0;
	for(int i = 1; i < k; i++) {
		previousDifference += i * arr[i] + sumTillHere[i - 1];
	}

	int difference = 0;	
	int i = 1;
	for(int j = k; j < n; j++) {
		
		difference = 0;
		difference = previousDifference - 2 * (sumTillHere[j] - sumTillHere[i]) + (k - 1) * (arr[i] + arr[j]);
		i++;

		if(difference < previousDifference) {
			previousDifference = difference;
		}
	}

	return previousDifference;
}

int main(void) {
		
	int n, k;
	cin >> n >> k;

	int *arr = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// sort the array
	sort(arr, arr + n);
//	cout << minimumAbsoluteDifference(arr, n, k) << endl;
	
	cout << minimumAbsoluteDifferenceDP(arr, n, k) << endl << endl;
	return 0;
}
