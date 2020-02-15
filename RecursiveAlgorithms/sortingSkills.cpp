# include <iostream>
using namespace std;

bool isSorted(int *arr, int n) {

	if(n == 0 || n == 1) {
		return true;
	} 

	bool smallCondition = (arr[0] < arr[1]);
	bool smallProblem = isSorted(arr + 1, n - 1);

	return smallCondition && smallProblem;
}

void isSortedPossible(int *arr, int n) {

	for(int i=0; i<n; i++) {
		if(arr[i + 1] == arr[i] + 1) {
			continue;
		} else if(arr[i + 1] == arr[i] - 1) {
			swap(arr[i + 1], arr[i]);
		}
	}

	if(isSorted(arr, n)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

int main(void) {

	int q;
	cin >> q;
	
	while(q--) {
		int n;
		cin >> n;

		int *arr = new int[n];
		for(int i=0; i<n; i++) {
			cin >> arr[i];
		}

		isSortedPossible(arr, n);
		cout << endl;
	}

	return 0;
}
