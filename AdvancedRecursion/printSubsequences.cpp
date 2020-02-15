# include <iostream>
using namespace std;

void printSubsequence(string input, string output) {

	if(input.empty() == true) {
		cout << output << endl;
		return;
	} 

	printSubsequence(input.substr(1), output);
	printSubsequence(input.substr(1), output + input[0]);
}

int main(void) {

	string str;
	cin >> str;
	string output = "";
	printSubsequence(str, output);
	cout << endl;

	return 0;
}
