# include <iostream>
using namespace std;

bool isMatching(string str, string pattern) {
		
	int strSize = str.size();
	int patternSize = pattern.size();

	for(int i = 0; i <= (strSize - patternSize); i++) {
		bool isFound = true;
		for(int j = 0; j < patternSize; j++) {
			if(str[i + j] != pattern[j]) {
				isFound = false;
				break;
			}
		}

		if(isFound == true) {
			return isFound;
		}
	}

	// we can also find the index where the pattern "starts" matching
	return false;
}

int main(void) {
		
	string str, pattern;
	cin >> str >> pattern;

	cout << isMatching(str, pattern) << endl << endl;
	return 0;
}
