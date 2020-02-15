# include <iostream>
using namespace std;

int maximumAscii(string s, string t, int k) {
		
	if(k == 0) {
		return 0;
	}

	if(s[0] == '\0' || t[0] == '\0') {
		return 0;
	}

	if(s[0] == t[0]) {

		int option1 = s[0] + maximumAscii(s.substr(1), t.substr(1), k - 1);
		int option2 = maximumAscii(s.substr(1), t, k);
		int option3 = maximumAscii(s, t.substr(1), k);

		return max(option1, max(option2, option3));
	}

	int option1 = maximumAscii(s.substr(1), t, k);
	int option2 = maximumAscii(s, t.substr(1), k);

	return max(option1, option2);
}

int maximumAscii(string s, string t, int m, int n, int k, int ***memo) {
		
	if(k == 0) {
		return 0;
	}

	if(s[0] == '\0' || t[0] == '\0') {
		return 0;
	}

	if(memo[m][n][k] > -1) {
		return memo[m][n][k];
	}

	if(s[0] == t[0]) {
		
		int option1 = s[0] + maximumAscii(s.substr(1), t.substr(1), m - 1, n - 1, k - 1, memo);
		int option2 = maximumAscii(s.substr(1), t, m - 1, n, k, memo);
		int option3 = maximumAscii(s, t.substr(1), m, n - 1, k, memo);

		memo[m][n][k] = max(option1, max(option2, option3));

		return memo[m][n][k];
	}

	int option1 = maximumAscii(s.substr(1), t, m - 1, n, k, memo);
	int option2 = maximumAscii(s, t.substr(1), m, n - 1, k, memo);

	memo[m][n][k] = max(option1, option2);

	return memo[m][n][k];
}

void printDP(int ***dp, int m, int n, int k) {
		
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			for(int l = 0; l < k; l++) {
				cout << dp[i][j][l] << "  ";
			}
			cout << endl;
		}

		cout << endl << endl;
	}

	cout << endl << endl << endl;
}

int maximumAsciiDP(string s, string t, int m, int n, int k) {
		
	int ***dp = new int** [m + 1];

	for(int i = 0; i <= m; i++) {
		dp[i] = new int* [n + 1];
		
		for(int j = 0; j <= n; j++) {
			dp[i][j] = new int[k + 1];
			for(int l = 0; l <= k; l++) {
				dp[i][j][l] = -1;
			}
		}
	}

//	printDP(dp, m + 1, n + 1, k + 1);
	
	// if k = 0, that is the length of the string is zero, no happiness can be generated
	for(int i = 0; i <= m; i++) {
		for(int j = 0; j <= n; j++) {
			dp[i][j][0] = 0;
		}
	}

	// if any of the string is of length = 0, no happiness can be further generated
	for(int i = 0; i <= k; i++) {
		
		for(int j = 0; j <= m; j++) {
			dp[j][0][i] = 0;
		}

		for(int j = 0; j <= n; j++) {
			dp[0][j][i] = 0;
		}
	}

	for(int l = 1; l <= k; l++) {
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
			
				if(s[i - 1] == t[j - 1]) {
					dp[i][j][l] = max(s[i - 1] + dp[i - 1][j - 1][l - 1], max(dp[i - 1][j][l], dp[i][j - 1][l]));
				} else {
					dp[i][j][l] = max(dp[i - 1][j][l], dp[i][j - 1][l]);
				}
			}
		}
	}

	int answer = dp[m][n][k];

	for(int i = 0; i <= m; i++) {
		for(int j = 0; j <= n; j++) {
			delete[] dp[i][j];		
		}

		delete[] dp[i];
	}

	delete[] dp;

	return answer;
}

int main(void) {
		
	string s, t;
	cin >> s >> t;

	int k;
	cin >> k;

	cout << maximumAscii(s, t, k) << endl << endl;

	int ***memo = new int** [s.size() + 1];

	for(int i = 0; i <= s.size(); i++) {
		memo[i] = new int* [t.size() + 1];
		for(int j = 0; j <= t.size(); j++) {
			memo[i][j] = new int[k + 1];
			for(int l = 0; l <= k; l++) {
				memo[i][j][l] = -1;
			}
		}
	}

 	cout << maximumAscii(s, t, s.size(), t.size(), k, memo) << endl << endl;


	cout << maximumAsciiDP(s, t, s.size(), t.size(), k) << endl << endl;
	return 0;
}
