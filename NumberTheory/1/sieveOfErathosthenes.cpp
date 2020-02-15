# include <iostream>
# include <math.h>
using namespace std;

bool checkPrime(int n) {
	
	int factors = 0;
	int i = 1;

	for(; i * i < n; i++) {
		if(n % i == 0) {
			factors += 2;
		}
	}

	if(i * i == n) {
		factors++;
	}

	if(factors == 2) {
		return true;
	}

	return false;
}

void sieveOfErathosthenes(bool * sieve, int n) {
		
	for(int i = 2; i <= n; i++) {

		if(sieve[i] == false) {
			continue;
		}

		if(checkPrime(i) == true) {
			for(int j = 2; i * j <= n; j++) {
				sieve[i * j] = false;
			}
		}
	}
}

void efficientsieveOfErathosthenes(bool * sieve, int n) {
		
	// there are two optimizations we can use : 
	// 1. the outer loop needs to run only till sqrt(n)
	// 2. the inner loop to "start" from i * i, not from i * 2

	for(int i = 2; i <= sqrt(n); i++) {
		
		if(sieve[i] == false) {
			continue;
		}

		if(checkPrime(i) == true) {
			for(int j = i; i * j <= n; j++) {
				sieve[i * j] = false;
			}
		}
	}
}

int main(void) {
		
	int n;
	cin >> n;

	cout << endl << endl << endl;
	bool * sieve = new bool[n + 1];

	// 0 and 1 are not prime by default
	for(int i = 0; i <= n ; i++) {
		sieve[i] = true;
	}

	sieve[0] = false;
	sieve[1] = false;

	sieveOfErathosthenes(sieve, n);

	int count = 0;
	for(int i = 0; i <= n; i++) {
		if(sieve[i] == true) {
			count++;
			cout << i << " ";
		}
	}

	cout << endl << "count of prime numbers: " << count << endl;

	for(int i = 0; i <= n ; i++) {
		sieve[i] = true;
	}

	sieve[0] = false;
	sieve[1] = false;

	efficientsieveOfErathosthenes(sieve, n);
	count = 0;
	
	cout << endl << endl;  
	for(int i = 0; i <= n; i++) {
		if(sieve[i] == true) {
			count++;
			cout << i << " ";
		}
	}

	cout << endl << "count of prime numbers: " << count << endl;

	return 0;
}
