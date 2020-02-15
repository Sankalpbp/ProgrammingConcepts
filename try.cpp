#include<iostream>
#define MOD 1000000007
using namespace std;
typedef pair<int, int> pii;

void printDP(pii **dp, int n, int k) {

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++ ){

			cout << dp[i][j].first << "  ";
		}
		cout << endl;
	}

	cout << endl << endl << endl;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++ ){

			cout << dp[i][j].second << "  ";
		}

		cout << endl;
	}
}

int solve(int n, int k){

	pii **dp = new pii*[n+1];
	for(int i = 0; i <= n; i++){
		dp[i] = new pii[k+1];
	}
	dp[1][0].first = 1;
	dp[1][0].second = 1;

	for(int j = 1; j <= k;j++){
		dp[1][j].first = 0;
		dp[1][j].second = 0;
	}

	for(int i = 2; i <= n; i++){
		dp[i][0].first = (dp[i-1][0].first + dp[i-1][0].second)%MOD;
		dp[i][0].second = dp[i-1][0].first;
	}

	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= k; j++){
			dp[i][j].first = (dp[i-1][j].first + dp[i-1][j].second)%MOD;
			dp[i][j].second = (dp[i-1][j].first + dp[i-1][j-1].second)%MOD;
		}
	}

	printDP(dp, n + 1, k + 1);
	int ans = (dp[n][k].first + dp[n][k].second)%MOD;
	for(int i = 0; i <= n; i++){
		delete[] dp[i];
	}
	delete[] dp;
	return ans;

}

int main(){

	int T;
	cin >> T;
	while(T--){
		int num , n, k;
		cin >>num >> n >> k;
		int ans = solve(n,k);
		cout << num <<" "<< ans << endl;
	}
}
