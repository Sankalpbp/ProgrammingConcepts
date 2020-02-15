# include <iostream>
# include <algorithm>
# include <math.h>
using namespace std;

int donuts(int *arr, int n) {

	sort(arr, arr + n, greater<int>());

	int sum = 0;
	for(int i=0; i<n; i++) {
		sum += arr[i] * pow(2, i);
	}

	return sum;
}

int main(void) {

	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	cout << donuts(arr, n);

	cout << endl;

	return 0;
}
