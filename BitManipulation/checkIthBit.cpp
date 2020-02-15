# include <iostream>
using namespace std;

bool checkIthBit(int n, int i) {
	if(n & (1 << i)) {
		return true;
	} else {
		return false;
	}
}

int main(void) {

	int n, i;

	cin >> n >> i;

	if(checkIthBit(n, i)) {
		cout << "Its one";
	} else {
		cout << "Its zero";
	}

	cout << "\n";
}