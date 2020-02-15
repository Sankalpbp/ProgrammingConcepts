# include <iostream>
# include <limits.h>
using namespace std;

void min_max(int *arr, int n, int &min, int &max) {

	for(int i=0; i<n; i++) {
		if(min > arr[i]) {
			min = arr[i];
		} if(max < arr[i]) {
			max = arr[i];
		}
	}
}

int increase(int *arr, int n, int num) {
	
	int count = 0;
	for(int i = 0; i<n; i++) {
		if(arr[i] < num) {
			count++;
		}
	}

	return count;
}

int decrease(int *arr, int n, int num) {
	
	int count = 0;
	for(int i =0; i<n; i++) {
		if(arr[i] > num) {
			count++;
		}
	}

	return count;
}

void checkAndChange(int *arr, int n, int number, int k, int l, int &answer) {

	int increasing = increase(arr, n, number);
	int decreasing = decrease(arr, n, number);
	int temp = 0;

	if(increasing >= decreasing) {
		temp = decreasing * k + l * (increasing - decreasing);
		if(temp < answer) {
				answer = temp;
		}
	}
}
	

int minimumCoins(int *arr, int n, int k, int l) {

	int min = INT_MAX, max = INT_MIN;
	min_max(arr, n, min, max);

	// we need to find the minimum and the maximum and a number between them

	int ans = INT_MAX;
	for(int i=min; i<=max; i++) {
		checkAndChange(arr, n, i, k, l, ans);
	}
	return ans;
}


int main(void) {
	
	int n, k, l;
	cin >> n >> k >> l;

	int *arr = new int[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	cout << minimumCoins(arr, n, k, l) << endl;

	return 0;
}
