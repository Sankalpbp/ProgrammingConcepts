# include <iostream>
using namespace std;

int main(void) {

	int t;
	cin >> t;

	while(t--) {
		long n;
		cin >> n;

		int sum = 0;
		while(n > 0) {
	//		cout << n % 10 << "\n";
			sum += n % 10;
			n /= 10;
		}

		cout << sum << endl;
	}

	return 0;
}
