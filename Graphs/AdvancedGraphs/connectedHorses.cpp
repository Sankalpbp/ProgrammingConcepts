# include <iostream>
# include <utility>
using namespace std;

int factorial(int n) {
		
	if(n == 0) {
		return 1;
	}

	int smallOutput = factorial(n - 1);
	return n * smallOutput;
}

int main(void) {
		
	int n, m;
	cin >> n >> m;

	int numberOfHorses;
	cin >> numberOfHorses;
	pair<int, int> *horses = new pair<int, int> [numberOfHorses];
	
	for(int i = 0; i < numberOfHorses; i++) {
		cin >> horses[i].first;
		cin >> horses[i].second;
	}

	int answer = 1;
	for(int i = 0; i< numberOfHorses; i++) {
			
		int count = 1;
		for(int j = i + 1; j < numberOfHorses; j++) {
			if(abs(horses[i].first - horses[j].first) == 1 && abs(horses[i].second - horses[j].second) == 2
					|| abs(horses[i].second - horses[j].second) == 1 && abs(horses[i].first - horses[j].first) == 2) {
				count++;
			}
		}
		answer *= factorial(count);
	}

	cout << answer << endl;

	return 0;
}
