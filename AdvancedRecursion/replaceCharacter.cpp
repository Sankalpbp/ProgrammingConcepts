# include <iostream>
using namespace std;

void replaceCharacter(char *str, char ch1, char ch2) {

	if(str[0] == '\0') {
		return;
	} else if(str[0] != ch1) {
		replaceCharacter(str + 1, ch1, ch2);
	} else if(str[0] == ch1) {
		str[0] = ch2;
		replaceCharacter(str + 1, ch1, ch2);
	}
}

int main(void) {

	char *str = new char[1000];
	cin >> str;

	char ch1, ch2;
	cin >> ch1 >> ch2;

	replaceCharacter(str, ch1, ch2);

	cout << endl << str << endl;

	return 0;
}
