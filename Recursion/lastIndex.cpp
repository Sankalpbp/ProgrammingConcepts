# include <iostream>
using namespace std;

int lastIndex(int *arr, int n, int number) {
	static int i = n-1;
	static int answer = -1;

	if(n == 0) {
		return answer;
	}

	if(arr[0] == number) {
		answer = i;
	}

	i--;
	return answer; 
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

	cout << lastIndex(arr + n - 1, n, number) << endl;

	return 0;
}
