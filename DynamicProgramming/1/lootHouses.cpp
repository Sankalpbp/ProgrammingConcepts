# include <iostream>
using namespace std;

int maxLoot(int *arr, int startingHouse, int endingHouse) {
	
	if(startingHouse == endingHouse) {
		return arr[startingHouse]; 
	}

	if(startingHouse == endingHouse - 1) {
		return max(arr[startingHouse], arr[startingHouse + 1]); 
	}

	int option1 = maxLoot(arr, startingHouse + 2, endingHouse);
	int option2 = maxLoot(arr, startingHouse + 1, endingHouse);

	return max(arr[startingHouse] + option1, option2);
}

int maxLoot(int *arr, int startingHouse, int endingHouse, int *memo) {
		
	if(startingHouse == endingHouse) {
			
		return arr[startingHouse];
	}

	if(startingHouse == endingHouse - 1) {
			
		return max(arr[startingHouse], arr[startingHouse + 1]);
	}

	if(memo[startingHouse] > 0) {
		return memo[startingHouse];
	}

	int option1 = maxLoot(arr, startingHouse + 2, endingHouse);
	int option2 = maxLoot(arr, startingHouse + 1, endingHouse);

	memo[startingHouse] = max(arr[startingHouse] + option1, option2);

	return max(arr[startingHouse] + option1, option2);
}

int maxLootDP(int *arr, int n) {
		
	int *dp = new int[n];

	// doesn't matter to start from first or last
	// one house left
	dp[0] = arr[0];

	// two houses left
	dp[1] = max(arr[0], arr[1]);
	
	for(int i = 2; i < n; i++) {
		dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
	}
	
	int answer = dp[n - 1];

	delete[] dp;

	return answer;
}

int main(void) {
		
	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i =0; i < n; i++) {
		cin >> arr[i];
	}

	cout << maxLoot(arr, 0, n - 1) << endl << endl;

	int *memo = new int[n];
	for(int i = 0; i < n; i++) {
		memo[i] = 0;
	}

	cout << maxLoot(arr, 0, n - 1, memo) << endl << endl;
	cout << maxLootDP(arr, n) << endl << endl;

	delete[] memo;
	delete[] arr;
	return 0;
}
