# include <bits/stdc++.h>

using namespace std;

// create an array with the product of all the elements except the element at i

int main(void) {

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

        int *arr = new int[n];

        long *product = new long[n];

        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        long leftProduct = 1;

        for(int i=0; i<n; i++) {
            product[i] = leftProduct;
            leftProduct *= arr[i];
        }

        long rightProduct = 1;
        for(int i=n-1; i>=0; i--) {
            product[i] *= rightProduct;
            rightProduct *= arr[i];
        }


        for(int i=0; i<n; i++) {
            cout << product[i] << " ";
        }
        cout << endl;
    }
}
