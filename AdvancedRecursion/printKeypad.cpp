# include <iostream>
using namespace std;

string getString(int n) {

	if(n == 2) {
		return "abc";
	} else if(n == 3) {
		return "def";
	} else if(n == 4) {
		return "ghi";
	} else if(n == 5) {
		return "jkl";
	} else if(n == 6) {
		return "mno";
	} else if(n == 7) {
		return "pqrs";
	} else if(n == 8) {
		return "tuv";
	} else if(n == 9) {
		return "wxyz";
	}

	return "";
}

void printKeypad(int n, string output) {

	if(n == 0) {
		cout << output << endl;
		return;
	} 

	int lastDigit = n % 10;
	int smallNumber = n / 10;

	string str = getString(lastDigit);

	for(int i = 0; i < str.length(); i++) {
		printKeypad(smallNumber, str[i] + output);
	}
}

int main(void) {

	int n;
	cin >> n;

	string output = "";
	printKeypad(n, output);
	return 0;
}
