# include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int fullMoon = 0;
    while(n % 11 != 1) {
        fullMoon++;
        n *= 2;
    }

    cout << fullMoon << " " << n << endl;
}
