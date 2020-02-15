# include <iostream>
using namespace std;

int flipIthBit(int n, int i) {

	return n ^ (1 << i);
}

int main(void) {

	int n, i;
	cin >> n >> i;

	cout << flipIthBit(n, i) << endl;

	return 0;
}