# include <iostream>
using namespace std;

int firstIndex(int *arr, int n, int number) {

	static int i = 0;

	if(n == 0) {
		return -1;
	}

	if(arr[0] == number) {
		return i;
	}

	i++;
	return firstIndex(arr + 1, n - 1, number);
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
	cout << firstIndex(arr, n, number);

	return 0;
}
