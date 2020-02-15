# include <iostream>
# include <vector>
using namespace std;

bool checkPrime(int number) {
		
	int factors = 0;
	for(int i = 1; i <= number; i++) {
		if(number % i == 0) {
			factors++;
		}
	}

	if(factors == 2) {
		return true;
	}

	return false;
}

vector<int> primeNumberOn2(int n) {
		
	vector<int> v;

	for(int i = 2; i <= n; i++) {
		if(checkPrime(i) == true) {
			v.push_back(i);
		}
	}
	return v;
}

bool efficientCheckPrime(int number) {
		
	int factors = 0;
	int i = 1;

	for(; i * i < number; i++) {
		if(number % i == 0) {
			factors += 2;
		}
	}

	if(i * i == number) {
		factors += 1;
	}

	if(factors == 2) {
		return true;
	}

	return false;
}

vector<int> primeNumberOnRootn(int n) {
		
	vector<int> v;

	// in general, for each of the factor of any number, there has to be another number that is a factor too
	// so we oughtn't need to check for those, and we can directly use += 2 kinda stuff
	// but for if the factors are equal(like in case of 5 * 5 = 25), we won't doo += 2, we will handle that separately
	for(int i = 2; i <= n; i++) {
		if(efficientCheckPrime(i) == true) {
			v.push_back(i);
		}
	}

	return v;
}

int main(void) {
		
	int n;
	cin >> n;

	vector<int> v = primeNumberOnRootn(n);

	vector<int> :: iterator it = v.begin();
	for(; it != v.end(); it++) {
		cout << *it << " ";
	}

	cout << endl << endl;

	return 0;
}
