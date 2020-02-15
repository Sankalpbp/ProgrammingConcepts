# include <iostream>
using namespace std;

int sumArray(int *arr, int n);

int main(void) {

	int n;
	cin >> n;
	int *arr = new int[n];

	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	cout << sumArray(arr, n);
	cout << endl;

	return 0;
}

int sumArray(int *arr, int n) {

	if(n == 1) {
		return arr[0];
	}

	int sum = sumArray(arr + 1, n - 1);
	return arr[0] + sum;
}
