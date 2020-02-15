# include <iostream>
using namespace std;

int main(void) {

	int n;
	cin >> n; 

	int *arr = new int[n];
	for(int i=0; i<n ;i++) {
		cin >> arr[i];
	}

	int sum = n * (n-1) /2;
	int givenSum = 0;

	for(int i=0; i<n; i++) {
		givenSum += arr[i];
	}

	if(sum - givenSum == 1) {
		cout << n-2 << endl;
	} else if(sum - givenSum == 2) {
		cout << n-3 << endl;
	} else if(sum - givenSum == 3) {
		cout << n - 4 << endl;
	}

	return 0;
}
