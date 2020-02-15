// use one other approaches as well : they are more efficieny
// 1. We don't have to allocate the whole dp array, instead we can do the stuff using only two
// Store first two rows in them, then, as we move further, switch between the arrays and store the rows one at a time

# include <iostream>
# include <climits>
using namespace std;

void print(int **dp, int n, int m) {
		
	for(int i = 0; i < n; i++) {
		
		for(int j = 0; j < m; j++) {
			cout << dp[i][j] << "  ";
		}

		cout << endl;
	}

	cout << endl << endl;
}

void dpHelper2(int *min, int left, int right) {
	
	if(min[right - 1] <= left - 1) {
		cout << "Yes\n";
		return;
	}

	cout << "No\n";
	return;
}

void dpHelper1(int** dp, int m, int left, int right) {
		
	for(int i = 0; i < m; i++) {
		if(dp[right - 1][i] <= left - 1) {
			cout << "Yes\n";
			return;
		}
	}

	cout << "No\n";
	return;
}

//void dpHelper2(int **dp, int n, int m, int left, int right, int *minimum) {
//		
//	
//}

void spreading(int queries, int **spreadsheet, int n, int m) {
		
	int **dp = new int* [n];
	for(int i = 0; i < n; i++) {
		dp[i] = new int[m];
	}

	// each column in first row is sorted till itself, therefore : 
	for(int j = 0; j < m; j++) {
		dp[0][j] = 0;
	}

	int *minimum = new int[m];
	for(int i = 1; i < n; i++) {

		int min = INT_MAX;
		for(int j = 0; j < m; j++) {
			if(spreadsheet[i - 1][j] <= spreadsheet[i][j]) {
				if(min > dp[i - 1][j]) {	
					min = dp[i - 1][j];
				}
				dp[i][j] = dp[i - 1][j];
			} else {
				if(min > i) {
					min = i;
				}
				dp[i][j] = i;
			}
		}

		minimum[i] = min;
	}

	print(dp, n, m);
	for(int i = 0; i < n; i++) {
		cout << minimum[i] << "  ";
	}
	int left, right;
	cin >> left >> right;

	for(int i = 0; i < queries; i++) {	
		dpHelper1(dp, m, left, right);
		dpHelper2(minimum, left, right);	
		cin >> left >> right;
	}
	
	return;
}

int main(void) {
		
	int n, m;
	cin >> n >> m;

	int **spreadsheet = new int*[n];

	for(int i = 0; i < n; i++) {
		
		spreadsheet[i] = new int [m];
		for(int j = 0; j < m; j++) {
			cin >> spreadsheet[i][j];
		}
	}

	int queries;
	cin >> queries;
	spreading(queries, spreadsheet, n, m);
	
	return 0;
}
