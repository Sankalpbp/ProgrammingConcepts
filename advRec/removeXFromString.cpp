# include <iostream>
using namespace std;

void removeX(char str[]) {
	if(str[0] == '\0') {
		return;
	}

	if(str[0] != 'x') {
		removeX(str+1);
	}

	if(str[0] == 'x') {

		int i=1;
		for(; str[i] != '\0'; i++) {
			str[i-1] = str[i];
		}
		str[i - 1] = '\0';
		removeX(str);
	}
}


int main(void) {

	char str[100];
	cin >> str;

	removeX(str);

	cout << str << endl << endl;
	return 0;
}