# include <iostream>
using namespace std;

int minSalary(int n, int *captains, int *assisstants, int x) {

	if(n == 0) {
		return 0;
	}
	if(x == 0) {
		return assisstants[0] + minSalary(n - 1, captains + 1, assisstants + 1, x + 1);
	}

	if(x == n) {
		return captains[0] + minSalary(n - 1, captains + 1, assisstants + 1, x - 1);
	}

	int option1 = assisstants[0] + minSalary(n - 1, captains + 1, assisstants + 1, x + 1);
	int option2 = captains[0] + minSalary(n - 1, captains + 1, assisstants + 1, x - 1);

	return min(option1, option2);
}

int minSalary(int n, int *captains, int *assisstants, int x, int **memo) {
		
	if(n == 0) {
		return 0;
	}

	if(memo[n][x] > -1) {
		return memo[n][x];
	}

	if(x == 0) {
		memo[n][x] = assisstants[0] + minSalary(n - 1, captains + 1, assisstants + 1, x + 1, memo);
		return memo[n][x];
	}

	if(x == n) {
		memo[n][x] = captains[0] + minSalary(n - 1, captains + 1, assisstants + 1, x - 1, memo);
		return memo[n][x];
	}

	int option1 = assisstants[0] + minSalary(n - 1, captains + 1, assisstants + 1, x + 1, memo);
	int option2 = captains[0] + minSalary(n - 1, captains + 1, assisstants + 1, x - 1, memo);

	memo[n][x] = min(option1, option2);
	return memo[n][x];
}

//
//int minSalary(int n, int *captains, int *assisstants) {
//		
//	int **dp = new int* [n + 1];
//
//	for(int i = 0; i <= n; i++) {
//		dp[i] = new int[n / 2 + 1];
//	}
//
//	dp[0][0] = 0;
//	// if the array ended, that is the pilots finished up, no salary required
//	for(int i = 0; i <= n / 2; i++) {
//		dp[0][i] = 0;
//	}
//
//	for(int i = 1; i <= n / 2; i++) {
//		dp[i][i] = captains[i - 1] + dp[i - 1][i - 1];
//	}
//
//	for(int i = 1; i < n; i++) {
//		dp[i][0] = assisstants[i - 1] + dp[i - 1][1];
//	}
//
//	for(int i 
//}

int main(void) {

	int n;
	cin >> n;

	int *captains = new int[n];
	int *assisstants = new int[n];

	for(int i = 0; i < n; i++) {
		cin >> captains[i] >> assisstants[i];
	}

	// here zero is the parameter to show the difference between the number of current assisstants and captains
	cout << minSalary(n, captains, assisstants, 0) << endl << endl;

	int **memo = new int* [n + 1];
	for(int i = 0; i <= n; i++) {
		memo[i] = new int[n / 2 + 1];
		for(int j = 0; j <= n / 2; j++) {
			memo[i][j] = -1;
		}
	}

	cout <<	minSalary(n, captains, assisstants, 0, memo) << endl << endl;
	return 0;
}
