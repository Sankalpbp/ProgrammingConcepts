# include <iostream>
using namespace std;

double power(double x, double n) {
    if(n == 0) {
        return 1;
    }
    return x * power(x, n-1);
}

int main(void) {

    double x, n;

    cin >> x >> n;

    cout << power(x, n);

    return 0;
}
