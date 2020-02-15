# include <iostream>
using namespace std;

int inversionCount(int *arr, int low, int high);
int mergeCount(int *arr, int low, int mid, int high);

int main(void) {

	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	cout << inversionCount(arr, 0, n-1);
	cout << endl;

	return 0;
}

int mergeCount(int *arr, int low, int mid, int high) {

	int count = 0;

	int n1 = mid - low + 1;
	int n2 = high - mid;

	int *leftArr = new int[n1 + 1];
	int *rightArr = new int[n2 + 1];

	for(int i=0; i<n1; i++) {
		leftArr[i] = arr[low + i];
	}

	for(int j=0; j<n2; j++) {
	       rightArr[j] = arr[mid + 1 + j];
   	}

	leftArr[n1] = 999999;
	rightArr[n2] = 999999;

	int i=0;
	int j = 0;

	for(int k = low; k <= high; k++) {
		if(leftArr[i] > rightArr[j]) {
			count += (n1 - i);
			arr[k] = rightArr[j];
			j++;
		} else {
			arr[k] = leftArr[i];
			i++;
		}
	}
	
	return count;
}	

int inversionCount(int *arr, int low, int high) {

	int count = 0;

	if(low < high) {

		int  mid = (high + low) / 2;
		count += inversionCount(arr, low, mid);
		count += inversionCount(arr, mid + 1, high);
		count += mergeCount(arr, low, mid, high);
		return count;
	}
	return count;
}
