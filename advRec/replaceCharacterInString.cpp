# include <iostream>
using namespace std;

void replaceCharacter(char str[], char c1, char c2) {

	if(str[0] == '\0') {
		return;
	}

	if(str[0] != c1) {
		replaceCharacter(str + 1, c1, c2);
	}

	if(str[0] == c1) {
		str[0] = c2;
		replaceCharacter(str+1, c1, c2);
	}
}

int main(void) {

	char str[100];
	cin >> str;	

	char c1, c2;
	cin >> c1 >> c2;

	replaceCharacter(str, c1, c2);

	cout << str << "\n\n";

	return 0;
}