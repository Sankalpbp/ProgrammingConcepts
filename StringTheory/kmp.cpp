# include <iostream>
using namespace std;

int *getLongestSuffixPreffix(string pattern) {
	
	int length = pattern.length();
	int * longestSuffixPreffix = new int[length];

	longestSuffixPreffix[0] = 0;

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
				// if j == 0 is true
				longestSuffixPreffix[i] = 0;
				i++;
			}
		}
	}

	return longestSuffixPreffix;
}

bool kmpSearch(string str, string pattern) {
		
	int lengthText = str.size();
	int lengthPattern = pattern.size();

	int i = 0;
	int j = 0;

	int *longestSuffixPreffix = getLongestSuffixPreffix(pattern);

	while(i < lengthText && j < lengthPattern) {
			
		if(str[i] == pattern[j]) {
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

	if(j == lengthPattern) {
		return true;
	}

	return false;
}

// try another variation to this problem to find all the indexes where the pattern has matched.

int main(void) {
		
	string str;
	string subString;
	cin >> str >> subString;

	cout << kmpSearch(str, subString) << endl << endl;
	return 0;
}
