# include <iostream>
# include <string>
# include <math.h>
using namespace std;

int length(string input) {
	if(input[0] == '\0') {
		return 0;
	}

	int smallLength = length(input.substr(1));

	return smallLength + 1;
}

int subsequences(string input, string *output) {
	if(input.empty() == true) {
		output[0] = "";
		return 1;
	}

	string smallString = input.substr(1); // will start from the second character.
	
	int smallOutput = subsequences(smallString, output);

	for(int i=0; i<smallOutput; i++) {
		output[i + smallOutput] = input[0] + output[i];
	}
	
	return smallOutput * 2;
}

int main(void) {

	string input;
	cin >> input;
	int Length = length(input);
	long outputLength = pow(2, Length);

	string *output = new string[outputLength];

	int count = subsequences(input, output);

	for(int i=0; i<count; i++) {
		cout << output[i] << "\n";
	}

	cout << endl << endl;
	return 0;
}
