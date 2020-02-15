# include <iostream>
# include <climits>
using namespace std;

class node {

	public:
		int maximum;
		int secondMaximum;
};

void buildTree(int *arr, node *tree, int start, int end, int treeNode) {

	if(start == end) {
		tree[treeNode].maximum = arr[start];
		tree[treeNode].secondMaximum = INT_MIN;
		return;
	}
	
	int mid = (start + end) / 2;

	buildTree(arr, tree, start, mid, 2 * treeNode);
	buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

	node left = tree[2 * treeNode];
	node right = tree[2 * treeNode + 1];

	tree[treeNode].maximum = max(tree[2 * treeNode].maximum, tree[2 * treeNode + 1].maximum);
	tree[treeNode].secondMaximum = min(max(left.maximum, right.secondMaximum), max(left.secondMaximum, right.maximum));

	return;
}

void updateTree(int *arr, node *tree, int start, int end, int treeNode, int index, int value) {
	
	if(start == end) {
		arr[index] = value;
		tree[treeNode].maximum = value;
		tree[treeNode].secondMaximum = INT_MIN;
		return;
	}

	int mid = (start + end) / 2;

	if(index > mid) {
		updateTree(arr, tree, mid + 1, end, 2 * treeNode + 1, index, value);
	} else {
		updateTree(arr, tree, start, mid, 2 * treeNode, index, value);
	}

	node left = tree[2 * treeNode];
	node right = tree[2 * treeNode + 1];

	tree[treeNode].maximum = max(left.maximum, right.maximum);
	tree[treeNode].secondMaximum = min(max(left.maximum, right.secondMaximum), max(left.secondMaximum, right.maximum));

	return;
}

node queryTree(node *tree, int start, int end, int treeNode, int left, int right) {
	
	if(start > right || end < left) {
		node answer;
		answer.maximum = INT_MIN;
		answer.secondMaximum = INT_MIN;
		return answer;
	}

	if(start >= left && end <= right) {
		return tree[treeNode];
	}

	int mid = (start + end) / 2;

	node answer1 = queryTree(tree, start, mid, 2 * treeNode, left, right);
	node answer2 = queryTree(tree, mid + 1, end, 2 * treeNode + 1, left, right);

	node answer;
	answer.maximum = max(answer1.maximum, answer2.maximum);
	answer.secondMaximum = (max(answer1.secondMaximum, answer2.maximum), max(answer1.maximum, answer2.secondMaximum));

	return answer;
}

int main(void) {
		
	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	node *tree = new node[3 * n];

	buildTree(arr, tree, 0, n - 1, 1);

	for(int i = 0; i < 3 * n; i++) {
		cout << tree[i].maximum << " " << tree[i].secondMaximum << endl;
	}

	cout << endl << endl;

	int index, value;
	cin >> index >> value;
	updateTree(arr, tree, 0, n - 1, 1, index, value);

	for(int i = 0; i < 3 * n; i++) {
		cout << tree[i].maximum << " " << tree[i].secondMaximum << endl;
	}

	cout << endl << endl;

	int left, right;
	cin >> left >> right;

	node answer = queryTree(tree, 0, n - 1, 1, left, right);
	
	cout << answer.maximum + answer.secondMaximum << endl << endl;
	
	return 0;
}
