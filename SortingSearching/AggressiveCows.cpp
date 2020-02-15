# include <bits/stdc++.h>
using namespace std;

bool check(int cows, int *arr, int n, int distance) {
	int cowsArranged = 1;
	int lastPosition  = arr[0];

	for(int i=1; i<n; i++) {
		
		if(arr[i] - lastPosition >= distance) {
			lastPosition = arr[i];
			cowsArranged++;
		}

		if(cowsArranged == cows) {
			return true;
		}
	}
	return false;
}

int main(void) {

	int t;
	cin >> t;

	while(t--) {
		int barns;
		int cows;

		cin >> barns >> cows;
		int arr[barns];

		for(int i=0; i<barns; i++) {
			cin >> arr[i];
		}

		int ans = 0;
		sort(arr, arr+barns);
		int min = 0;
		int max = arr[barns - 1] - arr[0];

		while(min <= max) {
			int mid = min + (max - min)/2;

			if(check(cows, arr, barns, mid)) {
				ans = mid;
				min = mid + 1;
			} else {
				max = mid - 1;
			}
		}

		cout << ans << endl;
	}
}