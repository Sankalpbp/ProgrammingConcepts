# include <iostream>

using namespace std;

int digits(int n) {
    if(n/10 == 0) {
        return 1;
    }

    return 1 + digits(n/10);
}

int main(void) {

    int n;
    cin >> n;

    while(n != 0) {
        cout << digits(n) << endl;
        cin >> n;
    }
}
