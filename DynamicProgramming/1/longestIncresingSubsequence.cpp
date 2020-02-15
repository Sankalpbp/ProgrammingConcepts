# include <iostream>
using namespace std;

int lengthOfLIS(int *arr, int n) {
		
	int *dp = new int[n];
	dp[0] = 1;

	for(int i = 1; i < n; i++) {
			
		dp[i] = 1;
		for(int j = i - 1; j >= 0; j--) {
			if(arr[j] > arr[i]) {
				continue;
			}
			int possibleAnswer = dp[j] + 1;
			if (possibleAnswer > dp[i]) {
				dp[i] = possibleAnswer;
			}
		}
	}

	int best = 0;
	for(int i =0 ; i<n; i++) {
		if(best < dp[i]) {
			best = dp[i];
		}
	}

	return best;
}

int main(void) {
		
	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	cout << lengthOfLIS(arr, n);
	cout << endl << endl;
	delete[] arr;

	return 0;
}
