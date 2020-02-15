# include <iostream>
using namespace std;

int numberOfWays(int ** like, int candies, int currentStudent, int mask) {
		
	if(currentStudent >= candies) {
		return 1;
	}

	int output = 0;
	for(int i = 0; i < candies; i++) {
		
		int unsetBitMask = (1 << i);
		if(!(mask & unsetBitMask) && like[currentStudent][i] == 1) {
			int newMask = mask | unsetBitMask;
			output += numberOfWays(like, candies, currentStudent + 1, newMask);
		}
	}

	return output;
}

int numberOfWays(int ** like, int candies, int currentStudent, int mask, int * memo) {
		
	if(currentStudent >= candies) {
		return 1;
	}

	if(memo[mask] != -1) {
		return memo[mask];
	}

	int output = 0;
	for(int i = 0; i < candies; i++) {
		
		int unsetBitMask = (1 << i);
		
		if(!(mask & unsetBitMask) && like[currentStudent][i] == 1) {
			int newMask = mask | unsetBitMask;
			output += numberOfWays(like, candies, currentStudent + 1, newMask, memo);
		}
	}

	memo[mask] = output;

	return output;
}

int numberOfWaysDP(int ** like, int candies) {
		
	int * dp = new int[1 << candies];
	for(int i = 0; i < (1 << candies); i++) {
		dp[i] = 0;
	}

	dp[0] = 1;	// that means, the mask with 0 value, nobody has got anything, this is one way.

	for(int mask = 0; mask < (1 << candies) - 1; mask++) {
		
		// finding the set bits
		int temp = mask;
		int setBits = 0;
		while(temp > 0) {
			if(temp % 2 == 1) {
				setBits++;
			}
			temp /= 2;
		}

		// update the table
		for(int j = 0; j < candies; j++) {
			int unsetBitMask = (1 << j);
			if(!(mask & unsetBitMask) && like[setBits][j]) {
				int newMask = mask | unsetBitMask;
				dp[newMask] += dp[mask];
			}
		}
	}

	return dp[(1 << candies) - 1];
}

int main(void) {
		
	int candies;
	cin >> candies;

	int ** like = new int* [candies];
	for(int i = 0; i < candies; i++) {
		like[i] = new int[candies];
		for(int j = 0; j < candies; j++) {
			cin >> like[i][j];
		}
	}

	cout << numberOfWays(like, candies, 0, 0) << endl << endl;

	int * memo = new int[1 << candies];
	for(int i = 0; i < (1 << candies); i++) {
		memo[i] = -1;
	}

	cout << numberOfWays(like, candies, 0, 0, memo) << endl << endl;
	
	cout << numberOfWaysDP(like, candies) << endl << endl;

	return 0;
}
