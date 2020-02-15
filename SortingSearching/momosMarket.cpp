# include <iostream>
using namespace std;

void momosAndMoney(int *arr, int n, int& momos, int& money) {

	for(int i=0; i<n; i++) {
		
		if(money - arr[i] >= 0) {
			money -= arr[i];
			momos++;
		}
	}
}

int returnIndex(int *arr, int low, int high, int money) {

	if(low < high) {

		int mid = (low + high) / 2;

		if(money > arr[mid]) {
		
			if(money > arr[mid] && money < arr[mid + 1]) {
				return mid;
			} else {
				return returnIndex(arr, mid + 1, high, money);
			}

		} else if(money < arr[mid]) {
			
			if(money < arr[mid] && money > arr[mid - 1]) {
				return mid - 1;
			} else {
				return returnIndex(arr, low, mid - 1, money);
			}

		} else {
			return mid;
		}
	}

	return -1;
}

void momosAndMoneyEfficient(int *arr, int n, int& momos, int &money) {

	for(int i=1; i<n; i++) {
		arr[i] += arr[i - 1];
	}

	int m = money;
	int index =	returnIndex(arr, 0, n-1, m);

	money -= arr[index];
	momos = (index + 1);
}
int main(void) {

	int n;
	cin >> n;
	int *shops = new int[n];

	for(int i=0; i<n; i++) {
	
		cin >> shops[i];
	}

	int queries;
	cin >> queries;

	while(queries--) {
	
		int momos = 0;
		int money;
		cin >> money;

//		momosAndMoney(shops, n, momos, money);
		momosAndMoneyEfficient(shops, n, momos, money);
		cout << momos << " " << money << endl;
	}

	cout << endl;
	return 0;
}
