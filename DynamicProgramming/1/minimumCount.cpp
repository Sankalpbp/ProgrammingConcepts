# include <iostream>
using namespace std;

int main(void) {
	
	int n;
	cin >> n;

	int answer;

	for(int x = 1; x <= 33; x++) {
	
		int xSquared = x * x;
		if(n % (xSquared) == 0) {
			answer = (n / (xSquared));
		} else if ((n / xSquared) < 1) {
			break;
		}
	}

	cout << answer << endl << endl;
	return 0;
}
