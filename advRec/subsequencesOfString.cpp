# include <iostream>
# include <string>
# include <math.h>
using namespace std;

int returnSubsequences(string str, string output[]) {

	if(str.empty() == true) {
		output[0] = "";
		return 1;
	}

	string smallString = str.substr(1);
	int smallOutputSize = returnSubsequences(smallString, output);

	for(int i=0; i<smallOutputSize; i++) {
		output[i + smallOutputSize] = str[0] + output[i];
	}

	return 2 * smallOutputSize;
}

int main(void) {

	string str;

	cin >> str;
	int size = pow(2, str.size());
	string *stringArray = new string[size];
	int stringArraySize = returnSubsequences(str, stringArray);

	cout << "\n\n";
	for(int i=0; i<stringArraySize; i++) {
		cout << stringArray[i] << "\n";
	}

	return 0;
}

int returnSubsequences(string input, string output[]) {

	if(input.empty() == true) {
		output[0] = "";
		return 1;
	}

	string smallString = input.substr(1);
	int smallOutputSize = returnSubsequences(smallString, output);

	for(int i=0; i<smallOutputSize; i++) {
		output[i + smallOutputSize] = input[0] + output[i];
	}

	return 2 * smallOutputSize;
}
