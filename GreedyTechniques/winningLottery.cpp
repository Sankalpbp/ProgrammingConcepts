# include <iostream>
# include <math.h>
using namespace std;

long minimumNumber(int sum, int digits) {

	// reserve one to be filled as the most significant digits
	sum -= 1;

	long number = 0;
	int currentDigits = 0;

	while(sum - 9 >= 0) {

		number = (9 * pow(10, currentDigits) + number);
		currentDigits++;
		sum -= 9;
	}

	if(sum > 0) {
		number = (sum * pow(10, currentDigits) + number);
		sum = 0;
	}

	number += pow(10, digits - 1);
	return number;
}

int main(void) {

	int sum, digits;
	cin >> sum >> digits;

	cout << minimumNumber(sum, digits) << endl << endl;

	return 0;
}
