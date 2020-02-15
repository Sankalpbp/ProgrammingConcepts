# include <iostream>
using namespace std;

int minimumChocolates(int *students, int n) {
		
	int *chocolates = new int[n];

	// first student will get minimum 1 chocolate
	chocolates[0] = 1;

	// while going from 1st student to last student
	for(int i = 1; i < n; i++) {
		if(students[i] > students[i - 1]) {
			chocolates[i] = chocolates[i - 1] + 1;
		} else {
			chocolates[i] = 1;
		}
	}

	for(int i = n - 2; i >= 0; i--) {

		if(students[i] > students[i + 1]) {
			if(chocolates[i] > chocolates[i + 1]) {
				continue;
			} else {
				chocolates[i] = chocolates[i + 1] + 1;
			}
		}
	}

	int totalChocolates = 0;
	for(int i = 0; i < n; i++) {
		totalChocolates += chocolates[i];
	}

	delete[] chocolates;

	return totalChocolates;
}


int main(void) {
		
	int n; 
	cin >> n;

	int * students = new int[n];
	
	for(int i = 0 ; i < n; i ++) {
		cin >> students[i];
	}
	
	cout << minimumChocolates(students, n) << endl << endl;

	return 0;
}
