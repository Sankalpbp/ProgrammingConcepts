# include <iostream>
using namespace std;

int countSubsets(int n, int *arr, int k) {
		
	int count = 0;

	int repeat = (1 << n);
	for(int mask = 0; mask <= repeat; mask++) {
		
		int sum = 0;

		for(int j = 0; j < n; j++) {
			int repeat2 = (1 << j);
			cout << repeat2 << endl;
			if(mask & repeat2 != 0) {
				sum += arr[j];
			}
		}

		cout << endl; 

		if(sum == k) {
			count++;
		}
	}

	return count;
}

int main(void) {
		
	int n;
	cin >> n;

	int k;
	cin >> k;

	int *arr = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << countSubsets(n, arr, k) << endl << endl;

	return 0;
}
