# include <iostream>
using namespace std;

void removeCharacter(char *str, char ch) {

	if(str[0] == '\0') {
		return;
	} else if(str[0] != ch) {
		removeCharacter(str + 1, ch);
	} else if(str[0] == ch) {

		for(int i=0; str[i]; i++) {
			str[i] = str[i + 1];
		}

		removeCharacter(str, ch);
	}
}

int main(void) {

	char *str = new char[1000];
	cin >> str;

	char ch;
	cin >> ch;
	removeCharacter(str, ch);

	cout << str << "\n\n";

	return 0;
}
