# include <iostream>
using namespace std;

int lengthOfLBSA(int *input, int n) {
		
	int *dpForIncreasingSubsequence = new int[n];
	int *dpForDecreasingSubsequence = new int[n];

	dpForIncreasingSubsequence[0] = 1;
	// for the first number, the maximum subsequence possible will be of size 1

	for(int i = 1; i < n; i++) {
			
		dpForIncreasingSubsequence[i] = 1;

		for(int j = i - 1; j >= 0; j--) {
			
			if(input[j] >= input[i]) {
				continue;
			} else {
				
				// now that the number before was smaller(strictly)
				// we will check that if the size of the previous element's
				// longest subsequence + this element(because it will be included in
				// that sequence now) is greater than what is the
				// value of the subsequence of this element
				int newLength = dpForIncreasingSubsequence[j] + 1;
				if(dpForIncreasingSubsequence[i] < newLength) {
					dpForIncreasingSubsequence[i] = newLength;
				}
			}
		}
	}

	for(int i = n - 2; i >= 0; i--) {
		
		dpForDecreasingSubsequence[i] = 1;

		for(int j = i + 1; j < n; j++) {
			
			if(input[j] >= input[i]) {
				continue;
			} else {
					
				int newLength = dpForDecreasingSubsequence[j] + 1;
				if(dpForDecreasingSubsequence[i] < newLength) {
					dpForDecreasingSubsequence[i] = newLength;
				}
			}
		}
	}

	int *resultDP = new int[n];
	int max = 0;

	for(int i =0; i<n; i++) {
		
		resultDP[i] = dpForIncreasingSubsequence[i] + dpForDecreasingSubsequence[i];
		if(resultDP[i] > max) {
			max = resultDP[i];
		}
	}

	delete[] dpForIncreasingSubsequence;
	delete[] dpForDecreasingSubsequence;
	delete[] resultDP;

	return max;
}

int main(void) {
		
	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	cout << lengthOfLBSA(arr, n) << endl << endl;

	delete[] arr;
	return 0;
}
