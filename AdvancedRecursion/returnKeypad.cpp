# include <iostream>
# include <math.h>
using namespace std;

string getString(int number) {

	if(number == 2) {
		return "abc";
	} else if(number == 3) {
		return "def";
	} else if(number == 4) {
		return "ghi";
	} else if(number == 5) {
		return "jkl";
	} else if(number == 6) {
		return "mno";
	} else if(number == 7) {
		return "pqrs";
	} else if(number == 8) {
		return "tuv";
	} else if(number == 9) {
		return "wxyz";
	} 
	return " ";
}

int keypad(int input, string *output) {

	if(input == 0) {
		output[0] = "";
		return 1;
	}

	int lastDigit = input % 10;
	int smallNumber = input / 10;

	int smallOutputSize = keypad(smallNumber, output);
	string options = getString(lastDigit);

	// making copies for new strings

	for(int i=0; i<options.length() - 1; i++) {
		for(int j=0; j<smallOutputSize; j++) {	
			output[j + (i + 1) * smallOutputSize] = output[j];
		}
	}

	int k = 0;
	for(int i=0; i<options.length(); i++) {
		for(int j=0; j<smallOutputSize; j++) {
			output[k] = output[k] + options[i];
			k++;
		}
	}
	return smallOutputSize * options.length();
}

int main(void) {

	int n;
	cin >> n;

	string *output = new string[10000];

	int count = keypad(n, output);

	for(int i=0; i<count; i++) {
		cout << output[i] << "\n";
	}

	cout << endl;

	return 0;
}
