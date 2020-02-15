# include <iostream>
# include <vector>
# define MAX 100001
using namespace std;

// we must have a sieve to work with
vector<int> *sieveOfErathosthenes() {
		
	bool *sieve = new bool[MAX];
	for(int i = 0; i < MAX; i++) {
		sieve[i] = true;
	}


	for(int i = 2; i * i < MAX; i++) {
		if(sieve[i] == true) {
			for(int j = i; i * j < MAX; j++) {
				sieve[i * j] = false;
			}
		}
	}

	vector<int> *primes = new vector<int> (MAX);
	primes -> push_back(2);

	for(int i = 3; i < MAX; i += 2) {
		if(sieve[i] == true) {
			primes -> push_back(i);
		}
	}

	return primes;
}

void printPrimes(long long left, long long right, vector<int> * primes) {
		
	bool *isPrime = new bool[right - left + 1];
	for(int i = 0; i <= (right - left); i++) {
		isPrime[i] = true;
	}

	for(int i = 0; primes -> at(i) * (long long)primes -> at(i) <= right; i++) {
		
		// find the prime
		int currentPrime = primes -> at(i);
		// just smaller or equal to left
		long long base = (left / currentPrime) / currentPrime;

		if(base < left) {
			base += currentPrime;
		}
				
		// mark all multiples within left to right as false
		for(long long j = base; j <= right; j += currentPrime) {
			isPrime[j - left] = false;
		}

		// there may be a case where the base is prime itself
		if(base == currentPrime) {
			isPrime[base - left] = true;
		}

		for(long long i = 0; i <= (right - left); i++) {
			if(isPrime[i] == true) {
				cout << i + left << endl;
			}
		}
	}
}

int main(void) {
		
	vector<int> * primes = sieveOfErathosthenes();

	int t;
	cin >> t;

	while(t--) {
			
		long long left, right;
		cin >> left >> right;

		printPrimes(left, right, primes);
	}

	return 0;
}
