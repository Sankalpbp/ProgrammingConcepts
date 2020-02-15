# include <iostream>
using namespace std;

string numberToString(int number) {

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

	return "";
}

int keypad(int input, string ouput[]) {

	if(input == 0) {
		output[0] = "";
		return 1;
	}

	int lastDigit = input % 10;
    int smallNumber = input / 10;
	
	int smallOutput = keypad(smallNumber, output);

	string options = numberToString(lastDigit);

	for(int i=0; i < options.length() - 1; i++) {
		for(int j=0; j<smallOutputSize; j++) {
			
		}		
	}	
}

int main(void) {

	int number;
	cin >> number;

	string *output = new string[1000];
	int count = keypad(number, output);

	for(int i=0; i<count; i++) {
		cout << ouput[i] << endl;
	}	

	return 0;
}	
