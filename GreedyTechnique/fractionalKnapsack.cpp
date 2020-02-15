# include <iostream>
# include <algorithm>

using namespace std;

class Item {

public:
	int value;
	int weight;
	float vbw;
};

bool comparator(Item a, Item b) {
	return a.vbw > b.vbw;
}

int main(void) {

	int t;
	cin >> t;

	while(t--) {
		int n, w;
		cin >> n >> w;

		Item I[n];

		for(int i=0; i<n; i++) {
			cin >> I[i].value >> I[i].weight;
			I[i].vbw = (float) I[i].value / I[i].weight;
		}

		sort(I, I + n, comparator);

		int currentWeight = 0;
		float value = 0;

		for(int i=0; i<n; i++) {

			if(w - currentWeight >= I[i].weight) {
				currentWeight += I[i].weight;
				value += I[i].value;
			} else {
				int remaining = w - currentWeight;
				float vl = (float) remaining * I[i].vbw;
				value += vl;			
				currentWeight += remaining;
				break;
			}
		}

		cout << value << endl;
	}
}