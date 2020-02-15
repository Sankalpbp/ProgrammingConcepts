# include <iostream>
# include <climits>
using namespace std;

class trieNode {

public:		
	trieNode *left;
	trieNode *right;
};

void insert(int value, trieNode *head) {
		
	trieNode *current = head;
	for(int i = 31; i >= 0; i--) {
			
		//checking if the bit is set or not
		int bit = (value >> i) & 1;

		if(bit == 0) {
			// not set
			if(current -> left == NULL) {
				current -> left = new trieNode();
			}
			current = current -> left;
		} else {
			// set
			if(current -> right == NULL) {
				current -> right = new trieNode();
			}
			current = current -> right;
		}
	}
}

int findMaxXORPair(trieNode *head, int *arr, int size) {
		
	int maxXor = INT_MIN;
	for(int i = 0; i < size; i++) {

		trieNode *current = head;
		int currentXor = 0;
		int value = arr[i];

		for(int j = 31; j >= 0; j++) {
			int bit = (value >> j) & 1;

			if(bit == 0) {
				if(current -> right != NULL) {
					currentXor += (1 << j);
					current = current -> right;
				} else {
					current = current -> left;
				}
			} else {
				if(current -> left != NULL) {
					currentXor += (1 << j);
					current = current -> left;
				} else {
					current = current -> right;
				}
			}
		}

		if(currentXor > maxXor) {
			maxXor = currentXor;
		}
	}

	return maxXor;
}

int main(void) {
		
	int n;
	cin >> n;

	trieNode * root = new trieNode();
	int *arr = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for(int i = 0; i < n; i++) {
		insert(arr[i], root);
	}

	cout << findMaxXORPair(root, arr, n) << endl << endl;

	return 0;
}
