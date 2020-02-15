# include <iostream> 
# include <limits.h>
using namespace std;

int returnWindow(int *arr, int n) {

	int i = 0;
	while(arr[i % n] != 0) {

		for(int j = 0; j < n; j++) {
			if(arr[j] != 0) {
				arr[j]--;
			}
		}
		i++;
	}

	return (i % n) + 1;
}

int find_t(int *arr, int i, int low, int high, int n) {

	if(low < high) {
		int mid = (low + high) / 2;

		if((i + mid * n) > arr[i]) {
			return find_t(arr, i, low, mid - 1, n);
		} else if((i + mid * n) < arr[i]) {
			return find_t(arr, i, mid + 1, high, n);
		} else {
			return mid;
		}
	}
}

int returnWindowBinarySearch(int *arr, int n) {

	int low = 0;
	int high = 1000000000;

	int index = -1;
	int ans = INT_MAX;
	for(int i = 0; i < n; i++) {

		int t = find_t(arr, i, low, high, n);
		if(ans > t) {
			ans = t;
			index = i;
		}
	}

	return index + 1;
}

/*
int returnWindowConstantTime(int *arr, int n) {

	int ans = INT_MAX;
	int index = -1;

	for(int i=0; i<n; i++) {
		int t = (arr[i] - i) / n;
		if(ans > t) {
			ans = t;
			index = i;
		}
	}

	return index + 1;
}
*/

int main(void) {

	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	cout << returnWindow(arr, n)  << endl;
	cout << returnWindowBinarySearch(arr, n) << endl << endl;
//	cout << returnWindowConstantTime(arr, n) << endl << endl;
	return 0;
}
