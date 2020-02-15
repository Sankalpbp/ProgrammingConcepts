#include<bits/stdc++.h>
using namespace std;

long long maxSubarrayProduct(long long arr[], long long n){

    long long maxEndingHere = 1;
    long long minEndingHere = 1;
    long long maxSoFar = 1;

    for(long long i = 0;i<n;i++){
        if(arr[i] > 0){
            maxEndingHere = maxEndingHere*arr[i];
            minEndingHere = min(minEndingHere*arr[i], (long long)1);
        }
        else if(arr[i] == 0){
            maxEndingHere = 1;
            minEndingHere = 1;
        }
        else{
            long long temp = maxEndingHere;
            maxEndingHere = max(minEndingHere*arr[i], (long long)1);
            minEndingHere = temp*arr[i];
        }

        if(maxSoFar < maxEndingHere){
            maxSoFar = maxEndingHere;
        }
    }
    return maxSoFar;
}

int main() {

	long long t;
	cin >> t;

	while(t--){
	    long long n;
	    cin >> n;
	    long long arr[n];
	    long long negative = 0, zeroes = 0;
	    for(long long i = 0;i<n;i++){
	        cin >> arr[i];
	        if(arr[i] < 0){
	            negative++;
	        }
	        if(arr[i] == 0){
	            zeroes++;
	        }
	    }

	    if(negative == 1 && zeroes == n-1 && zeroes != 0){
	        cout << "0" << endl;
	    }
	    else if(negative == 1 && n == 1){
	        cout << arr[0] << endl;
	    }
	    else{
	        cout << maxSubarrayProduct(arr, n) << endl;
	    }

	}

	return 0;
}
