# include <iostream>
using namespace std;

int main(void) {

    int n;
    cin >> n;
    int target;
    cin >> target;

    int *arr = new int[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int i=0, sum = arr[0], j = 1;

    for(; j<n; j++) {
        if(arr[j] + sum == target) {
            break;
        }
        else if(arr[j] + sum < target) {
            sum += arr[j];
        }
        else {
            sum -= arr[i];
            i++;
        }
    }

    for(int k=i; k<=j; k++) {
        cout << arr[k] << "  ";
    }
    return 0;
}
