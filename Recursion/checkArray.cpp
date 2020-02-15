# include <iostream>
using namespace std;

int checkArray(int *arr, int n, int number) {

	if(arr[0] == number) {
		return true;
	}

	return checkArray(arr + 1, n - 1, number);
}

int main(void) {

	int n;
	cin >> n;
	int *arr = new int[n];
	
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	int number;
	cin >> number;
	cout << checkArray(arr, n, number);

	return 0;
}
