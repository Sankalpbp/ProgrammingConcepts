# include <iostream>
using namespace std;

int * getLongestSuffixPreffix(string pattern) {
		
	int length = pattern.length();
	int * longestSuffixPreffix = new int[length];

	longestSuffixPreffix[0] = 0;
	// no suffix or preffix unfortunately

	int i = 1, j = 0;

	while(i < length) {
			
		if(pattern[i] == pattern[j]) {
			longestSuffixPreffix[i] = j + 1;
			i++;
			j++;
		} else {
			if(j != 0) {
				j = longestSuffixPreffix[j - 1];
			} else {
				longestSuffixPreffix[i] = 0;
				i++;
			}
		}
	}

	return longestSuffixPreffix;
}

int findIndexOfSubstring(string text, string pattern) {
		
	int textLength = text.length();
	int patternLength = pattern.length();

	int i = 0, j = 0;

	int * longestSuffixPreffix = getLongestSuffixPreffix(pattern);

	while(i < textLength && j < patternLength) {
			
		if(text[i] == pattern[j]) {
			i++;
			j++;
		} else {
			if(j != 0) {
				j = longestSuffixPreffix[j - 1];
			} else {
				i++;
			}
		}
	}

	if(j == patternLength) {
		return (i - patternLength);
	}

	return -1;
}

int main(void) {
		
	string str, subString;
	cin >> str >> subString;
//abcxabcdabcdabcy
//abcdabcx
	cout << findIndexOfSubstring(str, subString) << endl << endl;
	return 0;
}
