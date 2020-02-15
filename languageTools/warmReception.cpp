# include <iostream>
# include <algorithm>
using namespace std;

struct Guests {
	int arrival;
	int departure;
};

bool comparator(Guests a, Guests b) {
	return a.arrival < b.arrival;
}

int main(void) {
	
	int n;
	cin >> n;

	Guests *arr = new Guests[n];

	for(int i=0; i<n; i++) {
		cin >> arr[i].arrival;
	}
	
	for(int i=0; i<n; i++) {
		cin >> arr[i].departure;
	}
	
	sort(arr, arr + n, comparator);

	int minDepartTime = arr[0].departure;
	int chairs = 1;

	for(int i=1; i<n; i++) {
		if(minDepartTime > arr[i].arrival) {
			chairs++;
		}

		if(arr[i].departure < minDepartTime) {
			minDepartTime = arr[i].departure;
		}
	}
	
	cout << chairs << endl << endl;

	return 0;
}	
