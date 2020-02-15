# include <iostream>
using namespace std;

int longestCommonSubsequence(char *s1, char *s2) {
		
	if(s1[0] == '\0' || s2[0] == '\0') {
		return 0;
	}

	if(s1[0] == s2[0]) {
		return 1 + longestCommonSubsequence(s1 + 1, s2 + 1);
	}

	int takeFirst = longestCommonSubsequence(s1, s2 + 1);
	int takeSecond = longestCommonSubsequence(s1 + 1, s2);

	return max(takeFirst, takeSecond);
}

int length(char *s) {
	
	if(s[0] == '\0') {
		return 0;
	}

	char* smallString = s + 1;
	int smallLength = length(smallString);

	return 1 + smallLength;
}

int longestCommonSubsequence(char *s1, char *s2, int m, int n, int **memo) {
	
	if(m == 0 || n == 0) {
		return 0;
	}

	if(memo[m][n] > -1) {
		return memo[m][n];
	}

	int answer = 0;
	if(s1[0] == s2[0]) {
		answer = 1 + longestCommonSubsequence(s1 + 1, s2 + 1, m - 1, n - 1, memo); 
	} else {
		int takeFirst = longestCommonSubsequence(s1, s2 + 1, m, n - 1, memo);
		int takeSecond = longestCommonSubsequence(s1 + 1, s2, m - 1, n, memo);

		answer = max(takeFirst, takeSecond);
	}

	memo[m][n] = answer;

	return answer;
}

int longestCommonSubsequenceDP(char *s1, char *s2, int m, int n) {
		
	int **dp = new int* [m + 1];
	for(int i = 0; i <=m; i++) {
		dp[i] = new int[n + 1];
		for(int j = 0; j <= n; j++) {
			dp[i][j] = -1;
		}
	}

	for(int i = 0; i <= m; i++) {
		dp[i][0] = 0;
		dp[0][i] = 0;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(s1[m - i] == s2[n - j]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];	
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int answer = dp[m][n];

	for(int i = 0; i <= m; i++) {
		delete[] dp[i];
	}

	delete[] dp;

	return answer;
}

int main(void) {
		
	char* s1 = new char[1000];
	char* s2 = new char[1000];

	cin >> s1 >> s2;

	int n1 = length(s1);
	int n2 = length(s2);

	int **memo = new int* [n1 + 1];
	for(int i = 0; i <= n1; i++) {
		memo[i] = new int[n2 + 1];
		for(int j = 0; j <= n2; j++) {
			memo[i][j] = -1;
		}
	}

//	cout << longestCommonSubsequence(s1, s2) << endl << endl;

	cout << longestCommonSubsequence(s1, s2, n1, n2, memo) << endl << endl;

	cout << longestCommonSubsequenceDP(s1, s2, n1, n2) << endl << endl;
	
	for(int i = 0; i < n1; i++) {
		delete[] memo[i];
	}

	delete[] memo;

	delete[] s1;
	delete[] s2;

	return 0;
}
