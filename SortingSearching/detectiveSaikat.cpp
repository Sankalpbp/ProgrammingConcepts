# include <iostream>
using namespace std;

int merge(int *arr, int l, int mid, int r) {

	int n1 = mid - l + 1;
	int n2 = r - mid;

	int *arrL = new int[n1 + 1];
	int *arrR = new int[n2 + 1];

	for(int i=0; i<n1; i++) {
		arrL[i] = arr[l + i];
	}

	for(int j=0; j<n2; j++) {
		arrR[j] = arr[(mid + 1) + j];
	}

	arrL[n1] = 99999;
	arrR[n2] = 99999;

	int i = 0, j = 0;
	int count = 0;

//	for(int k=0; k<=n1; k++) {
//		cout << arrL[k] << " ";
//	} cout << endl;

//	for(int k=0; k<=n2; k++) {
//		cout << arrR[k] << " ";
//	} cout << endl;

	for(int k=l; k<=r; k++) {

		if(arrL[i] > arrR[j]) {
			arr[k] = arrR[j];
			j++;
		} else {
			arr[k] = arrL[i];
			if(arr[i] != arr[j] && arr[j] != 99999)
				count += (arrR[i] * (n2 - j));
			i++;
		}
	}
	
	return count;
}

int countSeries(int *arr, int l, int r) {

	int count = 0;

	if(l < r) {

		int mid = (l + r) / 2;
		count += countSeries(arr, l, mid);
		count += countSeries(arr, mid + 1, r);
		count += merge(arr, l, mid, r);
		return count;
	}

	return count;
}

int countSeries(int *arr, int n) {

	return countSeries(arr, 0, n - 1);
}

int main(void) {

	int t;
	cin >> t;

	while(t--) {

		int n;
		cin >> n;

		int *arr = new int[n];
		for(int i=0; i<n; i++) {
			cin >> arr[i];
		}

		cout << countSeries(arr, n);
		
		cout << endl << endl;
		for(int i=0; i<n; i++) {
			cout << arr[i] <<  " ";
		}
		cout << endl << endl;
		cout << endl;
	}

	cout << endl << endl;

	return 0;
}
