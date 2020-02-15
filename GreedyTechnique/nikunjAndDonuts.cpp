# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main(void) {

	std::vector<int> v;
	int num;

	cin >> num;
	while(num != -10000) {

		v.push_back(num);
		cin >> num;
	}

	sort(v.begin(), v.end(), greater<int>());

	int sum = 0;
	int i;
	for(auto it = v.begin(); it != v.end(); ++it) {
		sum += (*it) * (1 << i);
		i++;
	}

	cout << sum << endl;

	return 0;
}