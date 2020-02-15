# include <iostream>

using namespace std;

bool isElementPresent(int *arr, int n, int i, int x) {
    if(arr[i] == x) {
        return true;
    }

    if(i+1 < n) {
        return isElementPresent(arr, n, i+1, x);
    }

    return false;
}

bool isElementPresent(int *arr, int n, int x) {
    if(n == 0) {
        return false;
    }

    return (arr[0] == x) || isElementPresent(arr+1, n-1, x);
}

bool isElementPresent(int *arr, int n, int x) {
    return isElementPresent(arr, n, 0, x);
}

int main(void) {
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    cout << isElementPresent(arr, n, x);

    return 0;
}
