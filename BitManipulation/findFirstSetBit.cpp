#include <iostream>
using namespace std;

int findFirstSetBit(int n) {
    if(n == 0) {
        return 0;
    }
    int i=0;
    while(true) {
        if(n & (1 << i)) {
            return i+1;
        } else {
            i++;
        }
    }
}

int main() {
	//code
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    
	    cout << findFirstSetBit(n);
	    cout << endl;
	}
	return 0;
}