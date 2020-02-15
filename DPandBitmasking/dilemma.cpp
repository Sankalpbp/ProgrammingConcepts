# include <iostream>
# include <vector>
# include <climits>
using namespace std;

int findTouches(int position, int mask, vector<string> &v, int ** dp) {
	
	cout << position << " " << mask << endl;
	// if only one bit is set, therefore, it would be of the form 2 ^ n
	if(mask & (mask - 1) == 0) {
		return 0;
	}

	// if the string ended, that is, position got to zero
	if(position < 0) {
		return 10000;
	}

	if(dp[position][mask] != INT_MAX) {
		return dp[position][mask];
	}

	int newMask1 = 0;
	int newMask2 = 0;
	int touches = 0;

	for(int i = 0; i < v.size(); i++) {
		
		if(mask & (1 << i)) {
			touches++;
			if(v[i][position] == '0') {
				newMask1 |= (1 << i);
			} else {
				newMask2 |= (1 << i);
			}
		}
	}

	int answer1 = findTouches(position - 1, newMask1, v, dp) + findTouches(position - 1, newMask2, v, dp) + touches;
	int answer2 = findTouches(position - 1, mask, v, dp);

	int answer = min(answer1, answer2);
	dp[position][mask] = answer;

	return answer;
}

int minimumTouchesRequired(int n, vector<string> v) {
	
	int maximumMask = (1 << (n + 1));
	int ** dp = new int* [v[0].size()];

	for(int i = 0; i < v[0].size(); i++) {
		dp[i] = new int[maximumMask];
		for(int j = 0; j < maximumMask; j++) {
			dp[i][j] = INT_MAX;
		}
	}
		
	return findTouches(v[0].size() - 1, (1 << n) - 1, v, dp);
}

int main(void) {
		
	int n;
	cin >> n;

	vector<string> v;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	for(int i = 0; i < n; i++) {
		cout << v[i] << endl;
	}

	cout << minimumTouchesRequired(n, v) << endl << endl;
	return 0;
}
