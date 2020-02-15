# include <iostream>
using namespace std;

bool powerOf2(int n) {

	return n & (n-1);
}

int main(void) {

	int n;
	cin >> n; 

	if(!powerOf2(n)) {
		cout << "true\n";
	} else {
		cout << "false\n";
	}

	return 0;
}