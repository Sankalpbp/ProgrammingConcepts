# include <iostream>
using namespace std;

int isWinningPossible(int *arr, int n) {

	int swaps = 0;

	for(int i = 0; i<n; i++) {
	if(arr[i] == i + 1) {
		continue;
	}

	if(arr[i] != i + 1) {
		if(arr[i - 1] == i + 1) {
			swap(arr[i - 1], arr[i]);
			swaps++;
		} else if(arr[i - 2] == i + 1) {
			swap(arr[i - 2], arr[i]);
			swaps += 2;
		} else {
			return -1;
		}
	}
	}

	return swaps;
}

int main(void) {

	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i = 0; i<n; i++) {
		cin >> arr[i];
	}

	int ans = isWinningPossible(arr, n);

	if(ans != -1) {
		cout << "YES\n" << ans;
	} else {
		cout << "NO\n";
	}
	cout << endl << endl;

	return 0;
}
