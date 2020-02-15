# include <iostream>
using namespace std;

class triplet {
		
	public:
		int x;
		int y;
		int gcd;
};

// solving diophantine equations
triplet extendedEuclidAlgorithm(int a, int b) {
		
	// base case
	if(b == 0) {
		triplet answer;
		answer.gcd = a;
		answer.x = 1;
		answer.y = 0;	// doesn't exist though

		return answer;
	}

	// extended euclid's algorithm
	triplet smallAnswer = extendedEuclidAlgorithm(b, a % b);
	triplet answer;

	answer.gcd = smallAnswer.gcd;
	answer.x = smallAnswer.y;
	answer.y = smallAnswer.x - (a / b) * smallAnswer.y;

	return answer;
}

int main(void) {

	int a, b;
	cin >> a >> b;

	triplet answer = extendedEuclidAlgorithm(a, b);

	cout << answer.gcd << " " << answer.x << " " << answer.y << endl << endl;
		
	return 0;
}
