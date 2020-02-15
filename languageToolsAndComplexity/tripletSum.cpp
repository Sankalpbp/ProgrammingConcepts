# include <iostream>
using namespace std;

void triplets(int *arr, int first, int last, int x) {

	if(last - first >= 2) {
		int requiredSum = x - (arr[first] + arr[last]);

		for(int i=first + 1; i<last; i++) {
			if(arr[i] == requiredSum) {
				cout << arr[first] << " " << arr[i] << " " << arr[last] << "\n";
				break;
			}
		}

		triplets(arr, first + 1, last, x);
		triplets(arr, first, last - 1, x);
	} else {
		return;
	}
}		

void trivialTriplets(int *arr, int n, int x) {

	for(int i=0; i<n-2; i++) {
		for(int j=i+1; j<n-1; j++) {
			for(int k=j+1; k<n; k++) {
				if(arr[i] + arr[j] + arr[k] == x) {
					cout << arr[i] << " " << arr[j] << " " << arr[k] << "\n";
				}
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

	int x;
	cin >> x;
	triplets(arr, 0, n - 1, x);
	cout << "\n\n";
	trivialTriplets(arr, n, x);
        cout << "\n\n";	
	return 0;
}
