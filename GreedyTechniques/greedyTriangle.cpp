# include <iostream>
# include <algorithm>
# include <limits.h>
using namespace std;

void printTheGreedyTriangle(int *arr, int n) {

	sort(arr, arr + n, greater<int>());

	int finalA, finalB, finalC;

	int maxPerimeter = INT_MIN;

	bool solution = false;

	for(int i = 0; i< n - 2; i++) {

		if(arr[i] < arr[i + 1] + arr[i + 2]) {

			solution = true;

			int perimeter = arr[i] + arr[i + 1] + arr[i + 2];

			if(perimeter > maxPerimeter) {
				finalA = arr[i];
				finalB = arr[i + 1];
				finalC = arr[i + 2];
				maxPerimeter = perimeter;
			} else if(perimeter == maxPerimeter) {
				if(arr[i] > finalA) {
					finalA = arr[i];
					finalB = arr[i + 1];
					finalC = arr[i + 2];
				} else if(arr[i] == finalA) {
					if(arr[i + 2] > finalC) {
						finalA = arr[i];
						finalB = arr[i + 1];
						finalC = arr[i + 2];
					}
				}
			}
		}
	}

	if(solution == false) {
		cout << -1 << "\n\n";
	} else {
		cout << finalC << " " << finalB << " " << finalA << "\n\n";
	}
}

int main(void) {

	int n;
	cin >> n;

	int *arr = new int[n];

	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	printTheGreedyTriangle(arr, n);

	cout << endl << endl;

	return 0;
}

