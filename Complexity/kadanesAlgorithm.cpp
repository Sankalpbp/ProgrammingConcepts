# include <iostream>
using namespace std;

int kadanes(int *arr, int n) {

    int bestSum = 0;
    int currentSum = 0;

    for(int i=0; i<n; i++) {
        currentSum += arr[i];

        if(currentSum > bestSum) {
            bestSum = currentSum;
        }
        
        if(currentSum < 0) {
            currentSum = 0;
        }
    }

    return bestSum;
}

int main(void) {

    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << kadanes(arr, n) << "\n";

    return 0;
}
