# include <iostream>
# include <string>
using namespace std;

int editDistance(string s, string t) {
	
	if(s[0] == '\0' && t[0] == '\0') {
		return 0;
	}

	if(s[0] == '\0') {
		return t.size();
	}

	if(t[0] == '\0') {
		return s.size();
	}

	if(s[0] == t[0]) {
		return editDistance(s.substr(1), t.substr(1));
	} else {
		
		int option1, option2, option3;

		// replace a character in s and hence call on the rest of the s and rest of the t
		option1 = 1 + editDistance(s.substr(1), t.substr(1));

		// delete a character in s, hence, call on the rest of the s with the same t
		option2 = 1 + editDistance(s.substr(1), t);

		// insert a character in s, hence, call on the same s and the rest of the t
		option3 = 1 + editDistance(s, t.substr(1));

		int minimum = min(option1, option2);
		return min(minimum, option3);
	}
}

int editDistance(string s, string t, int m, int n, int **memo) {

	if(m == 0 && n == 0) {
		return 0;
	}

	if(m == 0) {
		return n;
	}

	if(n == 0) {
		return m;
	}

	if(memo[m][n] > -1) {
		return memo[m][n];
	}

	if(s[0] == t[0]) {
		memo[m][n] =  editDistance(s.substr(1), t.substr(1), m - 1, n - 1, memo);
		return memo[m][n];
	}

	int option1, option2, option3;

	// replace a character in s and hence call on the rest of the s and rest of the t
	option1 = 1 + editDistance(s.substr(1), t.substr(1), m - 1, n - 1, memo);

	// delete a character in s, hence, call on the rest of the s with the same t
	option2 = 1 + editDistance(s.substr(1), t, m - 1, n, memo);

	// insert a character in s, hence, call on the same s and the rest of the t
	option3 = 1 + editDistance(s, t.substr(1), m, n - 1, memo);

	int minimum = min(option1, option2);
	memo[m][n] =  min(minimum, option3);

	return memo[m][n];
}

void print(int **memo, int n, int m) {
		
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << memo[i][j] << "  ";
		}
		cout << endl;
	}
}

int editDistanceDP(string s, string t, int n, int m) {
	
	int **dp = new int* [n + 1];
	for(int i = 0; i <= n; i++) {
		dp[i] = new int[m + 1];
		for(int j = 0 ; j <= m; j++) {
			dp[i][j] = -1;
		}
	}

	// if the length of all of the strings is zero, no cost is required
	dp[0][0] = 0;

	// lets now fill the first row and first columns
	
	for(int i = 1; i <= n; i++) {
		dp[i][0] = i;
	}

	for(int i = 1; i <= m; i++) {
		dp[0][i] = i;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
	
			if(s[i - 1] == t[i - 1]) {
				dp[i][j] = dp[i - 1][j - 1];		
			} else {
				dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
			}
		}
	}

	print(dp, n, m);
	int answer = dp[n][m];

	for(int i = 0; i < n; i++) {
		delete[] dp[i];
	}
	delete[] dp;

	return answer;
}

int main(void) {
		
	string s, t;
	cin >> s >> t;

//	cout << editDistance(s, t) << endl << endl;

	int m = s.size();
	int n = t.size();

	int **memo = new int* [m + 1];
	for(int i = 0; i <= m; i++) {
		memo[i] = new int[n + 1];
		for(int j = 0 ; j <= n ;j++) {
			memo[i][j] = -1;
		}
	}

	cout << editDistance(s, t) << endl << endl;
	cout << editDistanceDP(s, t, m, n) << endl << endl;

	return 0;
}
