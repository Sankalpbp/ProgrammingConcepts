# include <iostream>
using namespace std;

void allIndices(int *arr, int size, int output[], int number) {
	static int i = 0;
	static int current = 0;
	if(size == 0) {
		return;
	}
	
	if(arr[0] == number) {
		output[i] = current;
		i++;
	}

	current++;
	allIndices(arr + 1, size - 1, output, number);
}

int main(void) {

	int n;
	cin >> n;
	int *arr = new int[n];
	
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	int *output = new int[n];
	for(int i=0; i<n; i++) {
		output[i] = -1;
	}

	int number;
	cin >> number;
	
	allIndices(arr, n, output, number);

	for(int i=0; i<n; i++) {
		cout << output[i] << "  ";
	}	

	return 0;
}
