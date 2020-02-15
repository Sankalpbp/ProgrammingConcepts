# include <iostream>
using namespace std;

void findFrequency(int *arr, int n, int *frequency) {
		
	for(int i = 0; i < n; i++) {
		frequency[arr[i]]++;
	}
}

int maximumPoints(int *arr, int start, int end, int *frequency) {

	if(start == end) {
		return arr[start];
	}

	if(start == end - 1) {
		return max(arr[start], arr[start + 1]);
	}
	
	int option1 = maximumPoints(arr, start + 1, end, frequency);
	int option2 = maximumPoints(arr, start + 2, end, frequency); 

	return max(option2 + arr[start] * frequency[arr[start]], option1);
}

int maximumPoints(int 

int main(void) {
		
	int n;
	cin >> n;

	int *board = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> board[i];
	}

	int *frequency = new int[1001];
	findFrequency(board, n, frequency);

	cout << maximumPoints(board, 0, n - 1, frequency) << endl << endl;

	return 0;
}
