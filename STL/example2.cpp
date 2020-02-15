# include <iostream>

using namespace std;

int main(void) {

    int a, b;

    int *ptr = new int[2];
    ptr = &a;
    int *ptr2 = ptr + 1;
    ptr2 = &b;

    cout << ptr << "  " << ptr2 << endl;

    return 0;
}
