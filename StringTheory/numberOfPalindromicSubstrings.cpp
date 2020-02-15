# include <iostream>
# include <string>

using namespace std;

bool isPalindrom(string str) {
		
	int length = str.length();

	for(int i = 0; i < length / 2; i++) {
		if(str[i] != str[length - i - 1]) {
			return false;
		}
	}

	return true;
}

int numberOfpalindromicSubstrings(string str) {
		
	int length = str.length();
	int number = 0;

	for(int i = 0; i < length; i++) {
		for(int j = 1; j <= length - i; j++) {
			
			string substring = str.substr(i, j);
			if(isPalindrom(substring) == true) {
				number++;
			}
		}
	}

	return number;
}

int main(void) {
		
	string str;
	cin >> str;

	cout << numberOfpalindromicSubstrings(str) << endl << endl;
	return 0;
}
