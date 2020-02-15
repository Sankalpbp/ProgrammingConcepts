# include <iostream>
using namespace std;

int unsetIthBit(int n, int i) {
	return (n & ~(1 << i));
}

int main(void) {

	int n, i;
	cin >> n >> i;

	cout << unsetIthBit(n, i) << endl;

	return 0;
}