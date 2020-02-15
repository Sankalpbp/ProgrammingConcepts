# include <iostream>
# define MOD 1000000007
using namespace std;

long numberOfBST(int n) {
	
	if(n == 0) {
		// no nodes
		return 1;
	}
	
	if(n == 1) {
		// 1 node, only root
		return 1;
	}

	// 1 node is taken as root
	// k - 1 nodes are taken as left tree
	// n - (k - 1 + 1) = n - k nodes are  taken as right tree

	long count = 0;

	for(int k = 1; k <= n/2; k++) {
		count += numberOfBST(k - 1); 
		count += numberOfBST(n - k);
	}

	cout << count << endl << endl;
	return count; 
}

int main(void) {
		
	int n;
	cin >> n;

	long answer = numberOfBST(n);
	cout << answer << endl << endl;

	return 0;
}
