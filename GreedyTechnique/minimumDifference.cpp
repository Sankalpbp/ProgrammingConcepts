#include <iostream>
# include <algorithm>
# include <limits.h>
using namespace std;

int minimumDifference(int *arr, int n) {
	sort(arr, arr+n);
	int min = INT_MAX;

	for(int i=0; i<n-1; i++) {

		if(min > arr[i+1] - arr[i]) {
			min = arr[i+1] - arr[i];
		}
	}

	return min;
}

int main() {
	//code
	int t;
	cin >> t;
	
	while(t--) {
    	int n;
    	cin >> n;
    
    	int *arr = new int[n];
    
    	for(int i=0; i<n; i++) {
    		cin >> arr[i];
    	}
    
    	cout << minimumDifference(arr, n) << endl;

	}
	return 0;
}