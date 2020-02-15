# include <iostream>
using namespace std;

int AllIndices(int *arr, int n, int x, int output[]) {

    static int i = 0, size = 0;

    if(n == 0) {
        return 0;
    }

    if(arr[0] == x) {
        output[size++] = i;
    }
    i++;
    AllIndices(arr+1, n-1, x, output);

    return size;
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

    // allIndices(arr, n, x);
    int *output = new int[n];
    int out = AllIndices(arr, n, x, output);
    cout << out << "\n\n";
    for(int i=0; i<out; i++) {
        cout << output[i] << " ";
    }

    return 0;
}
