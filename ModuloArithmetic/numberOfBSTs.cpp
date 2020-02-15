# include <iostream>
# include <math.h>
using namespace std;

int balancedBST(int h) {
		
	if(h == 0 || h == 1) {
		return 1;
	}

	int mod = pow(10, 9) + 7;
	int x = balancedBST(h - 1);
	int y = balancedBST(h - 2);

	long result1 = (long)(x * x);
	long result2 = (long)(2 * x * y);

	int answer1 = (int)(result1 % mod);
	int answer2 = (int)(result2 % mod);

	int answer = (answer1 + answer2) % mod;

	return answer;
}

int main(void) {
	
	int h;
	cin >> h;
	cout << balancedBST(h) << endl << endl;

	return 0;
}
