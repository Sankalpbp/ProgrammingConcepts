# include <iostream>
# include <climits>
using namespace std;

int smallestNonSubsequence(string s, string t) {
	
	if(s.empty() == true && t.empty() == true) {
		return 0;
	}

	if(s.empty() == true) {
		return t.size();
	}

	if(t.empty() == true) {
		return s.size();
	}

	// lets exclude s[0] from our subsequence
	int option1 = smallestNonSubsequence(s.substr(1), t);
	
	int index = -1;
	for(int i = 0; i < t.size(); i++) {
		if(s[0] == t[i]) {
			index = i;
			break;
		}
	}

	int option2 = INT_MAX;	// by default the subsequence from here would be of infinite length
	if(index != -1) {
		option2 = 1 + smallestNonSubsequence(s.substr(1), t.substr(index + 1));
	}

	return min(option1, option2);
}

int smallestNonSubsequence(string s, string t, int m, int n, int **memo) {
		
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
	// lets exclude s[0] from our subsequence
	int option1 = smallestNonSubsequence(s.substr(1), t, m - 1, n, memo);

	int index = -1;
	for(int i = 0; i < t.size(); i++) {
		if(s[0] == t[i]) {
			index = i;
			break;
		}
	}

	
	int option2 = INT_MAX;	// BY DEFAULT THE SUBSEQUENCE FROM HERE WOULD BE OF INFINITE LENTH(TO KEEP THINGS CLEAN)
	if(index != -1) {
		option2 = 1 + smallestNonSubsequence(s.substr(1), t.substr(index + 1));
	}

	return min(option1, option2);
}

int smallestNonSubsequenceDP(string s, string t, int m, int n) {
	
	int **dp = new int* [m + 1];
	for(int i = 0; i <= m; i++) {
		dp[i] = new int[n + 1];
	}

	for(int i = m - 1; i >= 0; i--) {
		dp[n][i] = m - i;
	}

	for(int i = n - 1; i >= 0; i--) {
		dp[i][m] = n - i;
	}

	for(int i = m - 1; i >= 0; i--) {
		for(int j = n - 1; j >= 0; j--) {
	
			dp[i][j] = dp[i + 1][j];
			int index = -1;
			for(int k = j; k >= 0; k--) {
				if(t[k] == s[i]) {
					index = k;
				}
			}

			if(index != -1) {
				dp[i][j] = min(dp[i][j], dp[i + 1][index + 1]);
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

	cout << smallestNonSubsequence(s, t) << endl << endl;

	int **memo = new int* [s.size() + 1];
	for(int i = 0; i <= s.size(); i++) {
		memo[i] = new int[t.size() + 1];
		for(int j = 0; j <= t.size(); j++) {
			memo[i][j] = -1;
		}
	}

	cout << smallestNonSubsequence(s, t, s.size(), t.size(), memo) << endl << endl;

	for(int i = 0; i <= s.size(); i++) {
		delete[] memo[i];
	}
	delete[] memo;

	cout << smallestNonSubsequenceDP(s, t, s.size(), t.size()) << endl << endl;
	return 0;
}
