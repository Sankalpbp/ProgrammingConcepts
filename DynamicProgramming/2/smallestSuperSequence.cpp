# include <iostream>
using namespace std;

int lengthSmallestSuperSequence(string s, string t) {
		
	if(s.empty() == true && t.empty() == true) {
		return 0;
	}

	if(s.empty() == true) {
		return t.size();
	}

	if(t.empty() == true) {
		return s.size();
	}

	if(s[0] == t[0]) {
		return 1 + lengthSmallestSuperSequence(s.substr(1), t.substr(1));
	}

	int option1 = lengthSmallestSuperSequence(s.substr(1), t);
	int option2 = lengthSmallestSuperSequence(s, t.substr(1));

	return 1 + min(option1, option2);
}

int lengthSmallestSuperSequence(string s, string t, int m, int n, int **memo) {
		
	if(s.empty() == true && t.empty() == true) {
		return 0;
	}

	if(s.empty() == true) {
		return t.size();
	}

	if(t.empty() == true) {
		return s.size();
	}

	if(memo[m][n] > -1) {
		return memo[m][n];
	}

	if(s[0] == t[0]) {
		memo[m][n] = 1 + lengthSmallestSuperSequence(s.substr(1), t.substr(1));
		return memo[m][n];
	}

	int option1 = lengthSmallestSuperSequence(s.substr(1), t);
	int option2 = lengthSmallestSuperSequence(s, t.substr(1));

	memo[m][n] = 1 + min(option1, option2);

	return memo[m][n];
}

int lengthSmallestSuperSequenceDP(string s, string t, int m, int n) {
		
	int **dp = new int* [m + 1];
	for(int i = 0; i <= m; i++) {
		dp[i] = new int[n + 1];
	}

	// imagine each block in the row representing the characters of s
	// and each block in the column representing the characters of t
	
	// therefore, further imagine that last column will be the null character
	// and last row representing the null character
	
	dp[m][n] = 0;

	for(int i = n - 1; i >= 0; i--) {
		dp[i][m] = n - i;	
	}

	for(int i = m - 1; i >= 0; i--) {
		dp[n][i] = m - i;
	}

	// the above filling is essentially the length of the subsequence required when the other string is empty, which is the length of the first string
	
	for(int i = m - 1; i >= 0; i--) {
		for(int j = n - 1; j >= 0; j--) {
		
			if(s[i] == t[j]) {
				dp[i][j] = 1 + dp[i + 1][j + 1];
			} else {
				dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}

	int answer = dp[0][0];

	for(int i = 0; i <= m; i++) {
		delete[] dp[i];
	}

	delete[] dp;

	return answer;
}

int main(void) {
	
	string s, t;
	cin >> s >> t;

	cout << lengthSmallestSuperSequence(s, t) << endl << endl;

	int **memo = new int* [s.size() + 1];
	for(int i = 0; i <= s.size(); i++) {
		memo[i] = new int[t.size() + 1];
		for(int j = 0; j <= t.size(); j++) {
			memo[i][j] = -1;
		}
	}
	
	cout << lengthSmallestSuperSequence(s, t, s.size(), t.size(), memo) << endl << endl;
	for(int i = 0; i <= s.size(); i++) {
		delete[] memo[i];
	}
	delete[] memo;

	cout << lengthSmallestSuperSequenceDP(s, t, s.size(), t.size()) << endl << endl;
	return 0;
}
