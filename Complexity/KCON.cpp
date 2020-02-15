# include <bits/stdc++.h>

using namespace std;

long long kadane(int *arr, int n) {
    long long currentSum = 0;
    long long bestSum = INT_MIN;

    for(int i=0; i<n; i++) {
        currentSum += arr[i];

        if(bestSum < currentSum) {
            bestSum = currentSum;
        }
        if(currentSum < 0) {
            currentSum = 0;
        }
    }

    return bestSum;
}

long long maxSubarraySum(int *arr, int n, int k) {

    long long kadaneSum = kadane(arr, n);

    if(k == 1) {
        return kadaneSum;
    }

    long long currentPrefixSum = 0, currentSuffixSum = 0;
    long long maxPrefixSum = INT_MIN, maxSuffixSum = INT_MIN;

    for(int i=0; i<n; i++) {
        currentPrefixSum += arr[i];
        if(maxPrefixSum < currentPrefixSum) {
            maxPrefixSum = currentPrefixSum;
        }
    }

    long long totalSum = currentPrefixSum;  // after the last loop, currentPrefixSum sum is essentially the sum of all the array elements

    for(int i=n-1; i>=0; --i) {
        currentSuffixSum += arr[i];
        if(maxSuffixSum < currentSuffixSum) {
            maxSuffixSum = currentSuffixSum;
        }
    }

    if(totalSum < 0) {
        return max(maxPrefixSum + maxSuffixSum, kadaneSum);
    } else {
        return max(maxSuffixSum + maxPrefixSum + (totalSum * (k-2)) , kadaneSum);
    }
}

int main(void) {

    int t;
    cin >> t;

    while(t--) {
        int n, k;

        cin >> n >> k;

        int arr[n];

        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        cout << maxSubarraySum(arr, n, k) << "\n";
    }
}
