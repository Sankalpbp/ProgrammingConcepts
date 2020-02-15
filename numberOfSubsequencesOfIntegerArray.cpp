# include <iostream>
# include <vector>
# include <math.h>
using namespace std;

void printArray(int *arr, int n) {

	for(int i = 0; i < n; i++) {
		cout << arr[i] << "  ";
	}

	cout << endl << endl;
	return;
}

int subsequences(int *arr, int n, vector<int> *output) {
	
	if(n == 0) {
		// we can add here a number which will represent an empty subsequence, like INT_MIN or INT_MAX
		// but if we are going to manipulate the numbers for getting some output, we may ignore it
		// output[0] = INT_MIN;
		return 1; 
	}

	int smallOutput = subsequences(arr + 1, n - 1, output);

	for(int i = 0; i < smallOutput; i++) {
		vector<int> a = output[i];
		a.push_back(arr[0]);
		output[i + smallOutput] = a;
	}

	return 2 * smallOutput;
}

int main(void) {
		
	int n;
	cin >> n;

	int *arr = new int[n];

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int outputLength = pow(2, n);
	vector<int> *output = new vector<int> [outputLength];

	cout << endl << endl;
	int count = subsequences(arr, n, output);

	for(int i = 0; i < outputLength; i++) {
		for(auto it = output[i].begin(); it != output[i].end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}


	return 0;
}
