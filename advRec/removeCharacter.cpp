# include <iostream>
using namespace std;

void removeCharacter(char *arr, char character) {

	if(arr[0] == '\0') {
		return;
	}

	if(arr[0] != character) {
		removeCharacter(arr + 1, character);
	}

	if(arr[0] == character) {
		int i=0;
		for(; arr[i]; i++) {
			arr[i] = arr[i+1];
		}
		removeCharacter(arr, character);
	}
}

int main(void) {

	char *arr = new char[1000];
	cin >> arr;

	char character;
	cin >> character;

	removeCharacter(arr, character);

	cout << arr;
	cout << endl;
	return 0;
}
