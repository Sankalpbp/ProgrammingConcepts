# include <iostream>
using namespace std;

void removeDuplicates(char *arr) {

	if(arr[0] == '\0') {
		return;
	}

	if(arr[1] == '\0') {
		return;
	}

	if(arr[0] == arr[1]) {
		int i = 0;
		for(; arr[i] ; i++) {
			arr[i] = arr[i+1];
		}
		removeDuplicates(arr);
	}

	removeDuplicates(arr + 1);
}

int main(void) {

	char *arr = new char[1000];
	cin >> arr;

	removeDuplicates(arr);
	cout << arr << endl;

	return 0;
}
