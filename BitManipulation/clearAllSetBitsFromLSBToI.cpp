# include <iostream>
using namespace std;

int clearAllSetBits(int n, int i) {

	int mask = ~((1 << (i+1)) - 1);
	
	return n & mask;
}

int main(void) {
	int n, i;
	cin >> n >> i;

	cout <<	clearAllSetBits(n, i) << endl;

	return 0;
}