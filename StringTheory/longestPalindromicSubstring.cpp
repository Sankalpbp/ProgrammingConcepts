# include <iostream>
# include <string>
using namespace std;

int isPalindrome(string str) {
		
	int length = str.length();
	bool notPalindrome = false;

	for(int i = 0; i < length / 2; i++) {
		if(str[i] != str[length - i - 1]) {
			notPalindrome = true;
			break;
		}
	}

	if(notPalindrome == true) {
		return 0;
	}

	return length;
}

int longestPalindromicSubstringOn3(string str) {
		
	// what do we gotta do?
	// we gotta go to each index, for a substring, then, check its 
	// "palindromicity", essentially, shan't we?

	int length = str.length();
	int maxLength = 0;
	for(int i = 0; i < length; i++) {
		for(int j = 1; j <= length - i; j++) {
			
			// form a substring - from i to j
			string subString = str.substr(i, j + 1);
			int palindromicLength = isPalindrome(subString);
			if(maxLength < palindromicLength) {
				maxLength = palindromicLength;
			}
		}
	}

	return maxLength;
}

int longestPalindromicSubstringOn2(string str) {
		
	// for each index, we gotta move left and right, left and right
	// and check till what values both of the indices have got equal values, characters, basically
	// lets try it out
	int length = str.length();
	int maxPalindromicLength = 0;

	for(int i = 0; i < length; i++) {
		
		// this is for odd length substring
		int left = i - 1;
		int right = i + 1;

		int palindromicLength = 1;
		while(left >= 0 && right < length) {
			if(str[left] == str[right]) {
				palindromicLength += 2;
				left--;
				right++;
			} else {
				break;
			}
		}

		if(maxPalindromicLength < palindromicLength) {
			maxPalindromicLength = palindromicLength;
		}
		
		// for the even length substring
		// for this, first check, if the next character is equal to the ith or not, otherwise, there's no point for checking the rest
		if(str[i] != str[i + 1]) {
			continue;
		} else {
			left = i;
			right = i + 1;

			palindromicLength = 0;
			while(left >= 0 && right < length) {
				if(str[left] == str[right]) {
					palindromicLength += 2;
					left--;
					right++;
				} else {
					break;
				}
			}
		}

		if(maxPalindromicLength < palindromicLength) {
			maxPalindromicLength = palindromicLength;
		}
	}

	return maxPalindromicLength;
}

int main(void) {
		
	string str;
	cin >> str;
	cout << longestPalindromicSubstringOn3(str) << endl << endl;
	cout << longestPalindromicSubstringOn2(str) << endl << endl;

	return 0;
}
