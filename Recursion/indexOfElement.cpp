# include <iostream>

using namespace std;


int indexOfSearchedElement(int *arr, int n, int x) {

    static int i=0;

    if(arr[0] == x) {
        return i;
    }

    i++;
    return indexOfSearchedElement(arr+1, n-1, x);
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
    cout << indexOfSearchedElement(arr, n, x);

    return 0;
}
