# include <iostream>
# include <algorithm>

using namespace std;

class activity {

	public:
		int start;
		int finish;
};

bool comparator(activity a, activity b) {
	
	bool condition = a.finish < b.finish;

	return condition;
}

int maximumActivities(activity *arr, int n) {

	sort(arr, arr + n, comparator);

	int time = arr[0].finish;
	int activities = 1;

	for(int i=1; i<n; i++) {
		if(arr[i].start >= time) {
			activities += 1;
			time = arr[i].finish;
		}
	}

	return activities;
}

int main(void) {

	int n;
	cin >> n;

	activity *arr = new activity[n];

	for(int i=0; i<n; i++) {
		cin >> arr[i].start;
		cin >> arr[i].finish;
	}

	cout << maximumActivities(arr, n);

	cout << endl << endl;
	return 0;
}


