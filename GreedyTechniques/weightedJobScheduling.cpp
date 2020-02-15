# include <iostream>
# include <algorithm>
using namespace std;

class Job {

	public:
		int start;
		int finish;
		int profit;
};

bool compare(Job a, Job b) {

	int condition = a.finish < b.finish;

	// a and b are the consecutive elements of the array here
	return condition;
}

int maxProfit(Job *arr, int n) {

	sort(arr, arr + n, compare);

	int *dynamicProgrammingArray = new int[n];

	dynamicProgrammingArray[0] = arr[0].profit;

	for(int i = 1; i < n; i++) {

		int excluding = dynamicProgrammingArray[i - 1];
		int including = arr[i].profit;
		int lastNonConflictingJobIndex = -1;

		for(int j = i - 1; j >= 0; j--) {
			if(arr[j].finish <= arr[i].start) {
				lastNonConflictingJobIndex = j;
				break;
			}
		}

		if(lastNonConflictingJobIndex != -1) {
			including += dynamicProgrammingArray[lastNonConflictingJobIndex];
		}

		dynamicProgrammingArray[i] = max(excluding, including);
	}

	int ans = dynamicProgrammingArray[n - 1];
	delete[] dynamicProgrammingArray;

	return ans;
}


int main(void) {

	int n;
	cin >> n;

	Job *arr = new Job[n];

	for(int i =0 ; i<n; i++) {
		cin >> arr[i].start;
		cin >> arr[i].finish;
		cin >> arr[i].profit;
	}

	cout << maxProfit(arr, n) << endl << endl;

	return 0;
}
