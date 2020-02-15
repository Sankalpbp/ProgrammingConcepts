# include <iostream>
using namespace std;


int sumOfArray(int *arr, int n) {
    if(n == 0) {
        return 0;
    }

    return arr[0] + sumOfArray(arr+1, n-1);
}

int main(void) {

    int n;
    cin >> n;

    int *arr = new int[n];

    for(int i=0; i<n; i++) {
        arr[i] = i+1;
    }

    cout << sumOfArray(arr, n);
}
