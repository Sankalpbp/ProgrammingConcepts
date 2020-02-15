# include <iostream>
# include <map>
using namespace std;

void printPairSumZero(int *arr, int n) {
	map<int, int> m;

	for(int i=0; i<n; i++) {
		m[arr[i]]++;
	}

	for(int i=0; i<n; i++) {
		
		for(int j=0; j<m[arr[i]] * m[-arr[i]]; j++) {
			if(arr[i] < 0) {
				cout << arr[i] << " " << -arr[i] << "\n";
			} else {
				cout << -arr[i] << " " << arr[i] << "\n";
			}
		}
		m[arr[i]] = 0;
		m[-arr[i]] = 0;
	}	
}

void printPairSumZeroEfficient(int *arr, int n) {
		map<int, int> m;
		
		for(int i=0; i<n; i++) {
			m[arr[i]]++;
			for(int j=0; j< m[-arr[i]]; j++) {
				if(arr[i] < 0) {
					cout << arr[i] << " " << -arr[i] << "\n";
				} else {
					cout << -arr[i] << " " << arr[i] << "\n";
				}
			}
		}
}

int main(void) {

	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	printPairSumZero(arr, n);
	cout << endl;
	printPairSumZeroEfficient(arr, n);
	cout << endl;

	return 0;
}
