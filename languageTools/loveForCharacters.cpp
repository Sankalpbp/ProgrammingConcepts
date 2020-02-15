# include <iostream>
# include <map>
using namespace std;

void displayFrequencies(char *arr, int n) {

	map<char, int> m;
	for(int i=0; i<n; i++) {
		m[arr[i]]++;
	}

	cout << endl << m['a'];
	cout << endl << m['s'];
	cout << endl << m['p'] << endl;
}

int main(void) {

	// to be done without any function, that is can be done with any function you want
	
	int n;
	cin >> n;
	

	char *arr = new char[n+1];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	arr[n] = '\0';

	displayFrequencies(arr, n);

	return 0;
}





