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

void update(int *arr, int *tree, int start, int end, int treeNode, int index, int value) {
	
	if(start == end) {
		arr[index] = value;
		tree[treeNode] = value;
		return;
	}

	int mid = (start + end) / 2;

	// if index is greater than mid, then move towards right subtree
	
	if(index > mid) {
		update(arr, tree, mid + 1, end, 2 * treeNode + 1, index, value);
	} else {
		update(arr, tree, start, mid, 2 * treeNode, index, value);
	}

	tree[treeNode] = min(tree[2 * treeNode], tree[2 * treeNode + 1]);
}

int query(int *tree, int start, int end, int treeNode, int left, int right) {

	// completely outside, we will return the maximum stuff possible
	if(start > right || end < left) {
		return INT_MAX;
	}

	// completely inside, we will return the value at that node
	if(start >= left && end <= right) {
		return tree[treeNode];
	}

	int mid = (start + end) / 2;

	int answer1 = query(tree, start, mid, 2 * treeNode, left, right);
	int answer2 = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);

	return min(answer1, answer2);
}

void print(int *arr, int n) {
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl << endl;
}

int main(void) {
	
	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int *tree = new int[4 * n];
	buildTree(arr, tree, 0, n - 1, 1);

	for(int i = 0; i < 4 * n; i++) {
		cout << tree[i] << " ";
	}
	cout << endl << endl;

	char c;
	cin >> c;

	if(c == 'u') {
		int index, value;
		cin >> index >> value;
		update(arr, tree, 0, n - 1, 1, index, value);
		print(tree, 4 * n);
	} else if(c == 'q') {
		int left, right;
		cin >> left >> right;
		cout << query(tree, 0, n - 1, 1, left, right) << endl << endl;
	}

	return 0;
}
