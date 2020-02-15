# include <iostream>
using namespace std;

void printArray(int *arr, int n) {
	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

void rotateArray2(int *arr, int n, int d) {

	int *save = new int[d];
	for(int i=0; i<d; i++) {
		save[i] = arr[i];
	}

	for(int i=0; i<n-d; i++) {
		arr[i] = arr[i+d];
	}

	for(int i=0; i<d; i++) {
		arr[n-d + i] = save[i];
	}
}

void rotateArray(int *arr, int n, int d) {

	for(int i = 0; i<d; i++) {
		int save = arr[i];
		for(int j=1; j<n; j++) {
			arr[j-1] = arr[j];
		}
		arr[n-1] = save;
	}
}

void reverseArray(int *arr, int f, int l) {
	for(int i=f; i<=(l/2); i++) {
		swap(arr[i], arr[l-i+f]);
	}
}

void rotateArray3(int *arr, int n, int d) {
	reverseArray(arr, 0, n-1);
	reverseArray(arr, 0, n - d - 1);
	reverseArray(arr, n - d, n - 1);
}

int main(void) {

	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	int d;
	cin >> d;

//	rotateArray(arr, n, d);
//	rotateArray2(arr, n, d);
	rotateArray3(arr, n, d);
	printArray(arr, n);

	return 0;
}
