# include <iostream>
# include <math.h>
using namespace std;

int length(string input) {

	if(input.empty() == true) {
		return 0;
	} 

	string smallString = input.substr(1);
	int smallOutput = length(smallString);

	return 1 + smallOutput;
}

int subsequences(string input, string *output) {

	if(input.empty() == true) {
		output[0] = "";
		return 1;
	}

	string smallString = input.substr(1);
	int smallOutput = subsequences(smallString, output);

	for(int i=0; i<smallOutput; i++) {
		output[i + smallOutput] = input[0] + output[i];
		
	}

	return 2 * smallOutput;
}

int main(void) {

	string input;
	cin >> input;
	int len = length(input);
	long outputLength = pow(2, len);

	string *output = new string[outputLength];

	int count = subsequences(input, output);

	for(int i=0; i<count; i++) {
		cout << output[i] << "\n";
	}

	cout << endl << endl;

	return 0;
}
