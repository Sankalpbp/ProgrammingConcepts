# include <iostream>
using namespace std;


int LastOccurence(int *arr, int n, int x) {

    static int i=0, ans = -1;
    if(n == 0) {
        return ans;
    }

    if(arr[0] == x) {
        ans = i;
    }

    i++;
    return LastOccurence(arr+1, n-1, x);
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
    cout << LastOccurence(arr, n, x) << "\n";

    return 0;
}
