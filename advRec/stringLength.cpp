# include <iostream>
using namespace std;

int length(char *arr) {

	if(arr[0] == '\0') {
		return 0;
	}

	int smallStringLength = length(arr + 1);
	return smallStringLength + 1;
}

int main(void) {

	char *arr = new char[1000];
	cin >> arr;
	cout << length(arr);
	cout << endl;

	return 0;
}
