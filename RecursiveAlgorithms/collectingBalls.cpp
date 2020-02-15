# include <iostream>
using namespace std;

bool check(int totalBalls, int balls) {
	
	int tBalls = totalBalls;
	int sharmaBalls = 0;
	int singhBalls = 0;
	while(totalBalls > 0) {

		if(totalBalls < balls) {
			sharmaBalls += balls;
			totalBalls = 0;
			break;
		}
		sharmaBalls += balls;
		totalBalls -= balls;
		singhBalls += (totalBalls / 10);
		totalBalls -= (totalBalls / 10);
	}

	if( 2 * sharmaBalls >= tBalls ) {
		return true;
	}

	return false;
}

int minimalSharmaBalls(int totalBalls, int low, int high, int &minimalBalls) {

	if(low < high) {
	
		int mid = (low + high) / 2;
		
		if(check(totalBalls, mid) == true) {
			minimalBalls = mid;
			minimalSharmaBalls(totalBalls, low, mid - 1, minimalBalls);
		} else if(check(totalBalls, mid) == false) {
			minimalSharmaBalls(totalBalls, mid + 1, high, minimalBalls);
		} 
	}
}

int minimalSharmaBalls(int n) {

	int minimalBalls = 0;
	minimalSharmaBalls(n, 0, n, minimalBalls);

	return minimalBalls;
}

int main(void) {

	int n;
	cin >> n;

	cout << minimalSharmaBalls(n);
	cout << endl;

	return 0;
}
