# include <iostream>
using namespace std;

int bracketCombinations(int opening, int closing, int total) {

	if(opening > total || closing > total) {
		return 0;
	}

	if(opening == total && closing == total) {
		return 1;
	}

	if(opening == closing) {
		return bracketCombinations(opening + 1, closing, total);
	}

	else if(opening == total) {
		return bracketCombinations(opening, closing + 1, total);
	}

	return bracketCombinations(opening + 1, closing, total) + bracketCombinations(opening, closing + 1, total);		
}

int main(void) {
	
	int n;
	cin >> n;

	// total number of brackets of one type, closing and opening
	
	cout << bracketCombinations(0, 0, n) << endl << endl;

	return 0;
}
