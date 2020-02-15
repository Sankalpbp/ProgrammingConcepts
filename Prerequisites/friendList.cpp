# include <iostream>
using namespace std;

int findMax(int *arr, int n) {

    int max = arr[0];
    for(int i=0; i<n; i++) {
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}

int main(void) {

    int n;
    int first, second;
    cin >> n;

    int *arr = new int[1000];

    for(int i=0; i<n; i++) {
        cin >> first;
        cin >> second;
        arr[first]++;
        arr[second]++;
    }

    int max = findMax(arr, 1000);

    for(int i=0; i<1000; i++) {
        if(arr[i] == max) {
            cout << i << " ";
        }
    }
    // if max is equal to the arr[i], we need to print i.
    return 0;
}
