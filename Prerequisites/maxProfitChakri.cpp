# include <iostream>
using namespace std;

int main(void) {

    int n;
    cin >> n;
    int *prices = new int[n];
    for(int i=0; i<n; i++) {
        cin >> prices[i];
    }

    int *nextGreaterPrice = new int[n];
    int max = prices[n-1];
    nextGreaterPrice[n-1] = prices[n-1];
    for(int i = n-2; i>=0; i--) {
        if(max > prices[i]) {
            nextGreaterPrice[i] = max;
        }
        else {
            nextGreaterPrice[i] = prices[i];
            max = prices[i];
        }
    }

    for(int i=0; i<n; i++) {
        cout << nextGreaterPrice[i] << " ";
    }

    // now we will find the maximum profit the ninja can earn
    max = 0;
    for(int i=0; i<n; i++) {
        nextGreaterPrice[i] -= prices[i];
        if(nextGreaterPrice[i] > max) {
            max = nextGreaterPrice[i];
        }
    }

    cout << "\n" << max;

    cout << "\n\n";
    return 0;
}
