# include <iostream>
# include <algorithm>
using namespace std;

void print(int *arr, int n) {
		
	cout << endl;
	for(int i = 0; i < n; i++) {
			
		cout << arr[i] << "  ";
	}

	cout << endl << endl;
}

void minMax(int n, int operations, int favoriteNumber) {

	int *rangers = new int[n];

	for(int i = 0; i < n; i++) {
		cin >> rangers[i];
	}


	for(int i = 0; i < operations; i++) {

		sort(rangers, rangers + n);
		
		for(int j = 0; j < n; j += 2) {
			rangers[j] ^= favoriteNumber;
		}
	}

	int min = rangers[0];
	int max = rangers[0];
	
	for(int i = 0; i < n; i++) {
		if(rangers[i] < min) {
			min = rangers[i];
		}

		if(rangers[i] > max) {
			max = rangers[i];
		}
	}

	cout << min << " " << max << endl << endl;
	
	delete[] rangers;
}

bool ifEven(int n) {
		
	if(n % 2 == 0) {
		return true;
	}

	return false;
}

void minMaxDP(int n, int operations, int favoriteNumber) {
		
	int *strengthFrequency = new int[1001];

	int a;
	for(int i = 0; i < n; i++) {
		cin >> a;
		strengthFrequency[a]++;
	}

	int currentIndex = 0;

	bool useFirst = true;

	for(int i = 0; i <= 1000 && currentIndex <= n; i++) {
	
		currentIndex += strengthFrequency[i];

		if(ifEven(currentIndex)) {
		// we will start from first 
			strengthFrequency[i ^ favoriteNumber] += strengthFrequency[i] / 2;
			strengthFrequency[i] /= 2;	
			
			if(useFirst) {
				useFirst = true;
			} else {
				useFirst = false;
			}
		} else {
		// we will start from second
			if(useFirst) {
				strengthFrequency[i ^ favoriteNumber] += strengthFrequency[i] / 2 + 1;
				strengthFrequency[i] /= 2;
				useFirst = false;
			} else {
				strengthFrequency[i ^ favoriteNumber] += strengthFrequency[i] / 2;
				strengthFrequency[i] -= strengthFrequency[i] / 2;
				useFirst = false;
			}
		}
	}

	for(int i = 0; i <= 1000; i++) {
		if(strengthFrequency[i] > 0) 
			cout << i << "(" << strengthFrequency[i] << ")\n ";
	}

	cout << endl << endl; 
}

int main(void) {
		
	int n, operations, favoriteNumber;
	cin >> n >> operations >> favoriteNumber;

//	minMax(n, operations, favoriteNumber); 
	
	minMaxDP(n, operations, favoriteNumber);
	return 0;
}
