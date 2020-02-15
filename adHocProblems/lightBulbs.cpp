# include <iostream>
using namespace std;

int countGroups(char *arr, int n) {

	int groups = 0;

	if(arr[0] == '0') {
		groups = 1;
	}
	for(int i=0; i<n; i++) {
		if(arr[i] == '1' && arr[i + 1] == '0') {
			groups += 1;
		}
	}

	return groups;
}

int minimumCost(int groups, int x, int y) {

	if(groups == 0) {
		return 0;
	}

	return (groups - 1) * min(x, y) + y;
}


int main(void) {
	
	int n, x, y;
	cin >> n >> x >> y;

	char *arr = new char[n + 1];
	cin >> arr;

	int groups = countGroups(arr, n);
	cout << minimumCost(groups, x, y) << endl << endl;

	return 0;
}
