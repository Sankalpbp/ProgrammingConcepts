# include <iostream>
using namespace std;

void removeConsecutiveDuplicates(char *str) {

	if(str[0] == '\0') {
		return;
	} else if(str[1] == '\0') {
		return;
	} else if(str[0] == str[1]) {
		for(int i=0; str[i]; i++) {
			str[i] = str[i + 1];
		}

		removeConsecutiveDuplicates(str);
	} else if(str[0] != str[1]) {
		removeConsecutiveDuplicates(str + 1);
	}
}

int main(void) {

	char *str = new char[10000];
	cin >> str;

	removeConsecutiveDuplicates(str);

	cout << str << endl << endl;
	return 0;
}
