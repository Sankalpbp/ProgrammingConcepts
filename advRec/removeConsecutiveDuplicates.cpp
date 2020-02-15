# include <iostream>
using namespace std;

void removeConsecutiveDuplicates(char str[]) {

	if(str[0] == '\0') {
		return;
	}

	if(str[1] == '\0') {
		return;
	}

	if(str[0] == str[1]) {
		int i=1;
		for(; str[i] != '\0'; i++) {
			str[i-1] = str[i];
		}

		str[i-1] = '\0';
		removeConsecutiveDuplicates(str);
	}

	removeConsecutiveDuplicates(str + 1);
}

int main(void) {

	char str[100];

	cin >> str;

	removeConsecutiveDuplicates(str);

	cout << str << endl;

	return 0;
}
