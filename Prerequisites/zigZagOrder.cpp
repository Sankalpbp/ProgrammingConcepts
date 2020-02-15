# include <iostream>
using namespace std;

int main(void) {

    int n;
    cin >> n;
    int **arr = new int*[n];
    for(int counter = 0; counter < n; counter++) {
        arr[counter] = new int[n];
        for(int counter2 = 0; counter2 < n; counter2++) {
            cin >> arr[counter][counter2];
        }
    }

    for(int col = 0; col < n; col++) {
        if(col % 2 == 0) {
            for(int row = 0; row < n; row++){
                cout << arr[row][col] << " ";
            }
        } else {
            for(int row = n-1; row >=0; row--) {
                cout << arr[row][col] << " ";
            }
        }
    }

    return 0;
}
