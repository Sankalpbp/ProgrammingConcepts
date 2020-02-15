# include <iostream>
using namespace std;

// its just like extended euclid's algorithm

class triplet {
		
	public:
		int x;
		int y;
		int gcd;
};

triplet extendedEuclidsAlgorithm(int a, int b) {
		
	// base case;
	if(b == 0) {
		triplet answer;
		answer.gcd = a;
		answer.x = 1;
		answer.y = 0;

		return answer;
	}

	triplet smallAnswer = extendedEuclidsAlgorithm(b, a % b);
	triplet answer;
	answer.gcd = smallAnswer.gcd;
	answer.x = smallAnswer.y;
	answer.y = smallAnswer.x - (a / b) * smallAnswer.y;

	return answer;
}

int multiplicativeModuloInverse(int a, int m) {
		
	triplet answer = extendedEuclidsAlgorithm(a, m);
	return answer.x;
}

int main(void) {
		
	int a, m;
	cin >> a >> m;

	cout <<  multiplicativeModuloInverse(a, m) << endl << endl;

	return 0;
}
