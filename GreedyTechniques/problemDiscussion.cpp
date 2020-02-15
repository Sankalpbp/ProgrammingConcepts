# include <iostream>
# include <algorithm>
using namespace std;

int minimumDifference(int *arr, int n, int k) {

	sort(arr, arr + n);

	int big = arr[n - 1] - k;
	int small = arr[0] + k;

	if(big < small) {
		swap(big, small);
	}

	int subtracted;
	int added;

	for(int i=1; i<n-1; i++) {
		subtracted = arr[i] - k;
		added = arr[i] + k;
		
		if(subtracted >= small || added <= big) {
			continue;
		} else if((big - subtracted) <= (added - small)) {
			small = subtracted;
		} else {
			big = added;
		}
	}

	return (big - small);
}

int main(void) {

	int n, k;
	cin >> n >> k;

	int *arr = new int[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	cout << minimumDifference(arr, n, k) << endl;

	return 0;
}
