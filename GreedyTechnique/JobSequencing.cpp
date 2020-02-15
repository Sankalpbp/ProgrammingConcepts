# include <iostream>
# include <algorithm>

using namespace std;

class Job {

public:
	int finish;
	int start;
	int profit;
};

bool compare(Job a, Job b) {

	return a.finish < b.finish;
}

int findMaximumProfit(Job arr[], int n) {

	sort(arr, arr + n, compare);

	int *dpArray = new int[n];
	dpArray[0] = arr[0].profit;
	int firstNonConflicting = -1;

	for(int i=1; i<n; i++) {

		int includedProfit = arr[i].profit;

		for(int j=i-1; j>=0; j--) {
			
			if(arr[j].finish <= arr[i].start) {
				firstNonConflicting = j;
			}
		}

		if(firstNonConflicting != -1)
			includedProfit += dpArray[firstNonConflicting];

		dpArray[i] = max(includedProfit, dpArray[i-1]);
	}

	int ans = dpArray[n-1];
	delete[] dpArray;
	return ans;
}

int main(void) {

	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;

		Job arr[n];
		
		for(int i=0; i<n; i++) {
			cin >> arr[i].start;
			cin >> arr[i].finish;
			cin >> arr[i].profit;
		}

		cout << "Maximum Profit from the jobs can be : " << findMaximumProfit(arr, n) << endl;
	}

	return 0;
}