# include <iostream>
using namespace std;

bool check(int m, int k) {

	int sharma = 0;
	int singh = 0;

	while(m > 0) {

		if(m < k) {
			sharma += m;
			m = 0;
			break;
		}

		sharma += k;
		m -= k;

		singh += (m / 10);
		m -= (m / 10);
	}	
	
	if(2 * sharma >= m) {
		return true;
	}

	return false;
}

int returnMaxK(int n, int k) {

	int low = 0;
	int high = n;

	int ans = 0;

	while(low < high) {

		int m = (low + high)/2;

		if(check(n, m)) {
			ans = k;
			high = m - 1;
		} else {
			low = m + 1;
		}		
	}
	return ans; 
}

int main(void) {

	int n, k;
	cin >> n >> k;

	cout << returnMaxK(n, k);
	cout << endl << endl;
	return 0;
}
