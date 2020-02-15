# include <iostream>
# include <limits.h>
using namespace std;

int findMax(int *arr, int n) {
	int max = INT_MIN;

	for(int i=0; i<n; i++) {
		if(max < arr[i]) {
			max = arr[i];
		}
	}

	return max;
}


int returnMaxCandies(int *arr, int n, int k) {

	int max = findMax(arr, n);

	int candies = 1;
	int answer = 0;

	bool t = false;
	int studentsServed = 0;

	while(candies <= max) {
		
		studentsServed = 0;
		t = false;

		for(int i=0; i<n; i++) {

			studentsServed += (arr[i] / candies);
			if(studentsServed >= k) {
				answer = candies;
				t = true;
				break;
			}
		}

		if(t == false) {
			break;
		}

		candies += 1;
	}	

	return answer;
}

bool find(int &answer, int k, int n, int *arr, int low, int high) {

	if(low <= high) {
	
		int candies = (low + high) / 2;
		int studentsServed = 0;
		bool t = false;

		for(int i = 0; i<n; i++) {
		
			studentsServed += (arr[i] / candies);
			if(studentsServed >= k) {
				answer = candies;
				t = true;
				break;
			}
		}
		if(t) {
			return find(answer, k, n, arr, candies + 1, high);
		} else if(!t) {
			return find(answer, k, n, arr, low, candies - 1);
		}
	}

	return false;
}

int returnMaxCandiesEfficient(int *arr, int n, int k) {

	int max = findMax(arr, n);
	int answer;
	answer = 0;
	bool t = find(answer, k, n, arr, 0, max);

	return answer;
}


int main(void) {

	int t;
	cin >> t;

	while(t--) {

		int n, k;
		cin >> n >> k;

		int *candyBox = new int[n];
		for(int counter = 0; counter < n; counter++) {
			cin >> candyBox[counter];
		}

		int max = findMax(candyBox, n);

//		cout << returnMaxCandies(candyBox, n, k) << endl;
		cout << returnMaxCandiesEfficient(candyBox, n, k) << endl;
	}

	return 0;
}
