# include <iostream>
# include <climits>
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeNode) {
	
	if(start == end) {
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start + end) / 2;

	buildTree(arr, tree, start, mid, 2 * treeNode);
	buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

	tree[treeNode] = min(tree[2 * treeNode], tree[2 * treeNode + 1]);
}

void updateSegmentTreeLazy(int *tree, int* lazy, int low, int high, int startRange, int endRange, int currPosition, int increment) {
	
	if(low > high) {
		return;
	}

	if(lazy[currPosition] != 0) {
		tree[currPosition] += lazy[currPosition];
		if(low != high) {
			lazy[2 * currPosition] += lazy[currPosition];
			lazy[2 * currPosition + 1] += lazy[currPosition];
		}
		lazy[currPosition] = 0;
	}

	// no overlap
	if(startRange > high || endRange < low) {
		return;
	}

	// complete overlap
	if(startRange <= low && high <= endRange) {
		tree[currPosition] += increment;
		if(low != high) {
			lazy[2 * currPosition] += increment;
			lazy[2 * currPosition + 1] += increment;
		}
		return;
	}

	// if not the above, then, obviously, partial overlap
	
	int mid = (low + high) / 2;

	updateSegmentTreeLazy(tree, lazy, low, mid, startRange, endRange, 2 * currPosition, increment);
	updateSegmentTreeLazy(tree, lazy, mid + 1, high, startRange, endRange, 2 * currPosition + 1, increment);

	tree[currPosition] = min(tree[2 * currPosition], tree[2 * currPosition + 1]);
}

int queryTree(int *tree, int *lazy, int low, int high, int startRange, int endRange, int currPosition) {
	
	if(lazy[currPosition] != 0) {
		tree[currPosition] += lazy[currPosition];

		if(low != high) {
			lazy[2 * currPosition] += lazy[currPosition];
			lazy[2 * currPosition + 1] += lazy[currPosition];
		}
		
		lazy[currPosition] = 0;
	}

	if(startRange > high || endRange < low) {
		return INT_MAX;
	}

	if(startRange <= low && high <= endRange) {
		return tree[currPosition];
	}

	int mid = (low + high) / 2;

	int answer1 = queryTree(tree, lazy, low, mid, startRange, endRange, 2 * currPosition);
	int answer2 = queryTree(tree, lazy, mid + 1, high, startRange, endRange, 2 * currPosition + 1);

	return min(answer1, answer2);
}
		

int main(void) {
	
	int n;
	cin >> n;
	int *arr = new int[n];

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int *tree = new int[3 * n];

	int *lazy = new int[3 * n];
	for(int i = 0; i < 3 * n; i++) {
		cout << tree[i] << "  ";
	}
	cout << endl << endl;

	for(int i = 0; i < 3 * n; i++) {
		cout << lazy[i] << "  ";
	}
	cout << endl << endl;

	buildTree(arr, tree, 0, n - 1, 1);

	int start, end;
	cin >> start >> end;
	int increment;
	cin >> increment;

	updateSegmentTreeLazy(tree, lazy, 0, n - 1, start, end, 1, increment);

	cin >> start >> end;
	cin >> increment;
	updateSegmentTreeLazy(tree, lazy, 0, n - 1, start, end, 1, increment);

	for(int i = 0; i < 3 * n; i++) {
		cout << tree[i] << "  ";
	}
	cout << endl << endl;

	for(int i = 0; i < 3 * n; i++) {
		cout << lazy[i] << "  ";
	}
	cout << endl << endl;

	int left, right;
	cin >> left >> right;

	cout << queryTree(tree, lazy, 0, n - 1, left, right, 1) << endl << endl;
	return 0;
}
