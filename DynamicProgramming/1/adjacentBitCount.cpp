# include <iostream>
using namespace std;

int adjacentBitCount(int size, int requiredAdjacentBitCount, int firstBit) {
		
	if(size == 1) {
		if(requiredAdjacentBitCount == 0) {
			return 1;
		} else if(requiredAdjacentBitCount < 0) {
			return 0;
		} else {
			return 0;	
		}
	}

	if(firstBit == 1) {
		return adjacentBitCount(size - 1, requiredAdjacentBitCount - 1, 1) + adjacentBitCount(size - 1, requiredAdjacentBitCount, 0);
	}

	return adjacentBitCount(size - 1, requiredAdjacentBitCount, 1) + adjacentBitCount(size - 1, requiredAdjacentBitCount, 0);
}

int adjacentBitCount(int size, int requiredAdjacentBitCount, int firstBit, int ***memo) {
	
	if(requiredAdjacentBitCount < 0) {
		return 0;
	}

	if(size == 1) {
		
		if(requiredAdjacentBitCount == 0) {
			return 1;
		} else {
			return 0;
		}
	}

	if(firstBit == 1) {
		
		if(memo[size][requiredAdjacentBitCount][firstBit] > -1) {
			return memo[size][requiredAdjacentBitCount][firstBit];
		} else {
			int answer = adjacentBitCount(size - 1, requiredAdjacentBitCount - 1, 1, memo) + adjacentBitCount(size - 1, requiredAdjacentBitCount, 0, memo);
			memo[size][requiredAdjacentBitCount][firstBit] = answer;
			return memo[size][requiredAdjacentBitCount][firstBit];
		}
	}

	if(memo[size][requiredAdjacentBitCount][firstBit] > -1) {
		return memo[size][requiredAdjacentBitCount][firstBit];
	}

	int answer = adjacentBitCount(size - 1, requiredAdjacentBitCount, 1, memo) + adjacentBitCount(size - 1, requiredAdjacentBitCount, 0, memo);
	memo[size][requiredAdjacentBitCount][firstBit] = answer;
	return memo[size][requiredAdjacentBitCount][firstBit];
}

void printMemo(int ***memo, int size, int requiredAdjacentBitCount, int firstBit) {
		
	for(int i = 0; i <= size; i++) {
		for(int j = 0; j <= requiredAdjacentBitCount; j++) {
				
			for(int k = 0; k < firstBit ; k++) {
				cout << memo[i][j][k] << " ";
			}

			cout << endl;
		}
		cout << endl << endl; 
	}

	cout << endl << endl << "\n\n\n";
}

int adjacentBitCountDP(int size, int requiredAdjacentBitCount) {
		
	int ***dp = new int** [size + 1];

	for(int i = 0; i <= size; i++) {
		
		dp[i] = new int* [requiredAdjacentBitCount + 1];

		for(int j = 0; j <= requiredAdjacentBitCount; j++) {
			dp[i][j] = new int[2];		

			for(int k = 0; k < 2; k++) {
				dp[i][j][k] = -1;	
			}
		}
	}

	// for size = 1 and requirement = 0, we will fill for bit 0 and 1 respectively, any string will work to form an adjacent bit stuff
	
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;

	// for size = 1 and requirement = 1, 2, we will fill for bit 0 and 1 respectively, no string with 1 size can form an adjacent bits
	dp[1][1][0] = 0;
	dp[1][1][1] = 0;
	
	dp[1][2][0] = 0;
	dp[1][2][1] = 0;

	// for size from 2 to n, for requirement 0, we will fill for bit 0 and 1.	
	// all the strings that can be formed depending on the number of characters present in the string.
	// and as we are incrementing one bit at a time, the number of possible string must get doubled than the previous string

	for(int j = 1; j <= requiredAdjacentBitCount; j++) {
		dp[1][j][0] = 0;
		dp[1][j][1]= 0;
	}

	for(int i = 2; i <= size; i++) {
		// requiredAdjacentBitCount = 0

		dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][0][1];
		// figure out the logic
		dp[i][0][1] = dp[i - 1][0][0];	
	}
	
	for(int i = 2; i <= size; i++) {
		
		for(int j = 1; j <= requiredAdjacentBitCount; j++) {
	
			// for bit = 0
			dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
		
			// for bit = 1
			dp[i][j][1] = dp[i - 1][j - 1][1] + dp[i - 1][j][0];
		}
	}

	int answer = dp[size][requiredAdjacentBitCount][0] + dp[size][requiredAdjacentBitCount][1];

	for(int i = 0; i <= size; i++) {
		for(int j = 0; j <= requiredAdjacentBitCount; j++) {
			delete[] dp[i][j];
		}
		delete[] dp[i];
	}
	delete[] dp;

	return answer;
}

int main(void) {
		
	int p;
	cin >> p;

	int dataSetNumber, size, requiredAdjacentBitCount;
	for(int i = 0; i < p; i++) {
		cin >> dataSetNumber;
		cin >> size;
		cin >> requiredAdjacentBitCount;

//		cout << adjacentBitCount(size, requiredAdjacentBitCount, 0) + adjacentBitCount(size, requiredAdjacentBitCount, 1) << endl << endl;
		int ***memo = new int** [size + 1];
		for(int i = 0; i <= size; i++) {
			memo[i] = new int* [requiredAdjacentBitCount + 1];
			
			for(int j = 0; j <= requiredAdjacentBitCount; j++) {
				memo[i][j] = new int[3];

				for(int k = 0; k < 3; k++) {
					memo[i][j][k] = -1;	
				}
			}
		}
		
//	cout << endl << endl;
//	cout << adjacentBitCount(size, requiredAdjacentBitCount, 0, memo) + adjacentBitCount(size, requiredAdjacentBitCount, 1, memo) << endl << endl;
//	printMemo(memo, size, requiredAdjacentBitCount, 2);
	cout << adjacentBitCountDP(size, requiredAdjacentBitCount) << endl << endl;


	for(int i = 0; i <= size; i++) {
			for(int j = 0; j <= requiredAdjacentBitCount; j++) {
				delete[] memo[i][j];
			}
			delete[] memo[i];
		}

		delete[] memo;
	}

	return 0;
}
