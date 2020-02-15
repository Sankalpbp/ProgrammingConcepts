# include <iostream>
using namespace std;

int returnLength(char *str) {

	if(str[0] == '\0') {
		return 0;
	}

	char *smallStr = str + 1;
	int smallOutput = returnLength(smallStr);

	return 1 + smallOutput;
}

int main(void) {

	char* string = new char[10000];
	cin >> string;

	cout << returnLength(string) << endl;

	return 0;
}
