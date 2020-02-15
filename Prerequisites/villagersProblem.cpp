# include <iostream>

using namespace std;

int main(void) {

    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n/2; i++) {
        arr[i] += arr[n-1-i];
    }

    for(int i=0; i<n/2; i++) {
        cout << arr[i]/10 << " " << arr[i]%10 << "\n";
    }
    return 0;
}
