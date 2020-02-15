# include <iostream>
using namespace std;

int main(void) {

    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int sumEven = 0;
    int sumOdd = 0;
    for(int i=0; i<n; i+=2) {
        if(arr[i] % 2 == 0) {
            sumEven += arr[i];
        }
    }

    for(int i=1; i<n; i+=2) {
        if(arr[i] % 2 != 0) {
            sumOdd += arr[i];
        }
    }

    cout << sumEven << " " << sumOdd << "\n";

    return 0;
}
