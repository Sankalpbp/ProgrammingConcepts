# include <iostream>
# include <climits>
using namespace std;

int minCost(int ** cost, int persons, int currentPerson, int mask) {
		
	if(currentPerson >= persons) {
		return 0;
	}

	int minimum = INT_MAX;
	//find the bit that is unset and then..., that is, finding the job that is not assigned yet,
	// the bits of the mask denotes the jobs, 0 represents, hasn't assigned yet, 1 represents the reverse

	for(int i = 0; i < persons; i++) {

		int unsetBitMask = (1 << i);
		if(!(mask & unsetBitMask)) {
			// this means that ith bit is unset, and hence we are gonna assign it
			// and we will assign for the other person, and change the mask as well
			// change the mask in a way, that now, ith bit is also set, essentially
			int newMask = mask | unsetBitMask;
			int smallOutput = minCost(cost, persons, currentPerson + 1, newMask);
			int answer = smallOutput + cost[currentPerson][i];
			if(answer < minimum) {
				minimum = answer;
			}
		}
	}

	return minimum;
}

int minCost(int ** cost, int persons, int currentPerson, int mask, int * memo) {
		
	if(currentPerson >= persons) {
		return 0;
	}

	if(memo[mask] != -1) {
		return memo[mask];
	}

	int minimum = INT_MAX;

	for(int i = 0; i < persons; i++) {
		
		int unsetBitMask = (1 << i);
		if(!(mask & unsetBitMask)) {
			int newMask = mask | unsetBitMask;
			
			int smallOutput = minCost(cost, persons, currentPerson + 1, newMask, memo);
			int answer = smallOutput + cost[currentPerson][i];

			if(answer < minimum) {
				minimum = answer;
			}
		}
	}

	memo[mask] = minimum;
	return minimum;
}

int minCostDP(int ** cost, int persons) {
		
	int *dp = new int[1 << persons];
	for(int i = 0; i < (1 << persons); i++) {
		dp[i] = INT_MAX;
	}

	dp[0] = 0;	// because, we know, when nobody is assigned any task, no cost would be there

	for(int mask = 0; mask < (1 << persons) - 1; mask++) {
		
		//finding the number of set bits
		int temp = mask;
		int setBits = 0;
		while(temp > 0) {
			if(temp % 2 == 1) {
				setBits++;
			}
			temp /= 2;
		}

		// update the table
		for(int j = 0; j < persons; j++) {
			int unsetBitMask = (1 << j);
			if(!(mask & unsetBitMask)) {
				int newMask = mask | unsetBitMask;
				dp[newMask] = min(dp[newMask], dp[mask] + cost[setBits][j]);
			}
		}
	}

	return dp[(1 << persons) - 1];
}

int main(void) {
		
	int persons;	// and equal number of jobs
	cin >> persons; 

	int **cost = new int* [persons];
	for(int i = 0; i < persons; i++) {
		cost[i] = new int[persons];
		for(int j = 0; j < persons; j++) {
			cin >> cost[i][j];
		}
	}
	
	cout << minCost(cost, persons, 0, 0) << endl << endl;

	// as we need to find the answer for every mask, our mask is essentially the state telling us which person has 
	// got which task and what's the cost according to that

	// so, we will make the memo for all the combinations of the mask, i.e. 2 ^ n - 1;
	int * memo = new int [1 << persons];
	for(int i = 0; i < (1 << persons); i++) {
		memo[i] = -1;
	}

	cout << minCost(cost, persons, 0, 0, memo) << endl << endl;
	
	cout << minCostDP(cost, persons) << endl << endl;
	return 0;
}
