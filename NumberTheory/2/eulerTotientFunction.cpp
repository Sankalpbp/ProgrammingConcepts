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
		factors += 1;
	}

	if(factors == 2) {
		return true;
	}

	return false;
}

void makeSievePrime(bool * sieve, int n) {
		
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

int *eulerTotientFunction(int n) {
		
//	makeSievePrime(sieve, n);

	// we find the Euler Totient Function for every number till n
	// and save it in the Phi array
	int * phi = new int[n + 1];
	for(int i = 1; i <= n; i++) {
		phi[i] = i;
	}

	for(int i = 2; i <= n; i++) {
		if(phi[i] == i) {
			// this means that this number has never been manipulated, so, this has to be prime
			// so, for prime numbers, we will change the value from i to i - 1, because all the numbers will be co prime with it, except itself
			phi[i] = i - 1;
			
// this logic is also correct			
//			for(int j = 2 * i; j <= n; j += i) {
//				phi[j] = (phi[j] * (i - 1)) / i;
//			}
			for(int j = 2; i * j <= n; j++) {
				phi[i * j] = (phi[i * j] * (i - 1)) / i;
			}
		}
	}

	return phi;
}

int main(void) {
	
	int n;
	cin >> n;

	int * phi =  eulerTotientFunction(n); 
	for(int i = 1; i <= n; i++) {
		cout << i << " : " << phi[i] << endl; 
	}
	cout << endl << endl;
		
	return 0;
}
