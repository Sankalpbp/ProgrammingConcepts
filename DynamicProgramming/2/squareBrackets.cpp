# include <iostream>
using namespace std;

int possibleCombinations(int total, bool *isOpening, int opening, int closing) {

	if(opening > total || closing > total) {
		return 0;
	}

	if(opening == total && closing == total) {
		return 1;
	}

	if(opening == closing || isOpening[opening + closing] == true) {
		return possibleCombinations(total, isOpening, opening + 1, closing);
	} else if(opening == total) {
		return possibleCombinations(total, isOpening, opening, closing + 1);
	}

	int option1 = possibleCombinations(total, isOpening, opening + 1, closing);
	int option2 = possibleCombinations(total, isOpening, opening, closing + 1);

	return option1 + option2;
}

int possibleCombinations(int total, bool *isOpening, int opening, int closing, int **memo) {
		
	if(opening > total || closing > total) {
		return 0;
	}

	if(opening == total && closing == total) {
		return 1;
	}

	if(memo[opening][closing] > -1) {
		return memo[opening][closing];
	}

	if(opening == closing || isOpening[opening + closing] == true) {
		memo[opening][closing] = possibleCombinations(total, isOpening, opening + 1, closing);	
		return memo[opening][closing];
	} else if(opening == total) {
		memo[opening][closing] = possibleCombinations(total, isOpening, opening, closing + 1);
		return memo[opening][closing];
	}

	int option1 = possibleCombinations(total, isOpening, opening + 1, closing);
	int option2 = possibleCombinations(total, isOpening, opening, closing + 1);

	memo[opening][closing] = option1 + option2;
	return memo[opening][closing];
}

int main(void) {
		
	int n;
	cin >> n;

	int k;
	cin >> k;

	int *s = new int [k];
	for(int i = 0; i < k; i++) {
		cin >> s[i];
	}

	bool *isOpening = new bool[2 * n];
	for(int i = 0; i < k; i++) {
		isOpening[s[i] - 1] = true;
	}

	cout << possibleCombinations(n, isOpening, 0, 0) << endl << endl;

	int **memo = new int* [n + 1];
	for(int i = 0; i <= n; i++) {
		memo[i] = new int[n + 1];
		for(int j = 0; j <= n; j++) {
			memo[i][j] = -1;
		}
	}

	cout << possibleCombinations(n, isOpening, 0, 0, memo) << endl << endl;

	for(int i = 0; i <= n; i++) {
		delete[] memo[i];
	}

	delete[] memo;

	delete[] s;
	return 0;
}
