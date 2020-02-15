# include <iostream>
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeNode) {
	
	// we reached the leaf
	if(start == end) {
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start + end) / 2;

	buildTree(arr, tree, start, mid, 2 * treeNode);
	buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

void updateTree(int *arr, int *tree, int start, int end, int treeNode, int index, int value) {

	if(start == end) {
		arr[index] = value;
		tree[treeNode] = value;
		return;
	}
	int mid = (start + end) / 2;

	// if index is greater than middle, then, move towards the right subtree
	if(index > mid) {
		updateTree(arr, tree, mid + 1, end, 2 * treeNode + 1, index, value);
	} else {
		updateTree(arr, tree, start, mid, 2 * treeNode, index, value);
	}

	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

int query(int *tree, int start, int end, int treeNode, int left, int right) {

	// completely outside
	if(start > right || end < left) {
		return 0;
	}

	// if completely inside
	if(start >= left && end <= right) {
		return tree[treeNode];
	}

	int mid = (start + end) / 2;
	int answer1 = query(tree, start, mid, 2 * treeNode, left, right);
	int answer2 = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);

	return answer1 + answer2;
}

int main(void) {
		
	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int *tree = new int[2 * n];

	buildTree(arr, tree, 0, n - 1, 1);

	for(int i = 1; i < 2 * n; i++) {
		cout << tree[i] << "  ";
	}

	cout << endl << endl;

	int index, value;
	cin >> index >> value;
	updateTree(arr, tree, 0, n - 1, 1, index, value);

	for(int i = 1; i < 2 * n; i++) {
		cout << tree[i] << "  ";
	}

	cout << endl << endl;

	int left, right;
	cin >> left >> right;
	int answer = query(tree, 0, n - 1, 1, left, right);

	cout << answer << endl << endl;
	return 0;
}
