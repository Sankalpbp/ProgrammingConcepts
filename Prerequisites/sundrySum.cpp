# include <iostream>
using namespace std;

int main(void) {

    int n;
    cin >> n;
    int **arr = new int*[n];
    for(int i=0; i<n; i++) {
        arr[i] = new int[n];
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    int requiredSum = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == 0 || j == 0 || i == n-1 || j == n-1) {
                requiredSum += arr[i][j];
            }
            else if(i == j) {
                requiredSum += arr[i][j];
            }

            else if((i+j) == n-1) {
                requiredSum += arr[i][j];
            }
        }
    }

    cout << requiredSum << "\n";

    return 0;
}
