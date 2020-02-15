# include <iostream>
# include <map>
# include <algorithm>
using namespace std;

int uniqueElement(int *arr, int size) {
	map<int, int> m;
	for(int i=0; i<size; i++) {
		m[arr[i]] += 1;
	}

	map<int, int> :: iterator it;
	for(it = m.begin(); it != m.end(); it++) {
		if(it -> second == 1) {
			return it -> first;	
		}
	}
}

int uniqueElement2(int *arr, int size) {

	for(int i=0; i<size; i++) {

		bool present = false;
		for(int j=0; j<size ; j++) {
			if(i != j && arr[i] == arr[j]) {
				present = true;
				break;
			}
		}
		
		if(!present) {
			return arr[i];
		}
	}

	return -1;
}

int uniqueElement3(int *arr, int n) {

	sort(arr,arr +  n);
	int i=0;
	for(; i<n-1; i+=2) {
		if(arr[i] != arr[i+1]) {
			return arr[i];
		}
	}

	if(i == n-1) {
		return arr[n-1];
	}

	return -1;
}

int uniqueElement4(int *arr, int n) {

	int result = 0;

	for(int i=0; i<n; i++) {
		result ^= arr[i];
	}

	return result;
}

int main(void) {

	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	cout << uniqueElement(arr, n);
	cout << endl << uniqueElement2(arr, n);
	cout << endl << uniqueElement3(arr, n);
	cout << endl << uniqueElement4(arr, n);
	cout << endl;

	return 0;
}
