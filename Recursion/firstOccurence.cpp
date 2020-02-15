# include <iostream>
using namespace std;


int FirstOccurence(int *arr, int n, int x) {
    static int i = 0;

    // hit the base case
    if(n == 0) /* and we couldn't find the element */
        return -1;

    if(arr[0] == x) {
        return i;
    }

    i++;
    return FirstOccurence(arr+1, n-1, x);
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
    cout << "\n\n";
    cout << FirstOccurence(arr, n, x);
    cout << "\n\n";

    return 0;
}
