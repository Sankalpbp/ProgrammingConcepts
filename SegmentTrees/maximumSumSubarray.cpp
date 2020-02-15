# include <iostream>
# include <climits>
using namespace std;

class node {

	public:
		int sum;
		int maximumSum;
		int bestPrefixSum;
		int bestSuffixSum;
};
void buildTree(int *arr, node *tree, int start, int end, int treeNode) {
		
	if(start == end) {
		tree[treeNode].sum = arr[start];
		tree[treeNode].maximumSum = arr[start];
		tree[treeNode].bestPrefixSum = arr[start];
		tree[treeNode].bestSuffixSum = arr[start];

		return;
	}

	int mid = (start + end) / 2;

	buildTree(arr, tree, start, mid, 2 * treeNode);
	buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

	node left = tree[2 * treeNode];
	node right = tree[2 * treeNode + 1];

	// sum is essentially the sum of the left and right children.sum
	tree[treeNode].sum = left.sum + right.sum;
	// bestPrefixSum is..
	tree[treeNode].bestPrefixSum = max(left.bestPrefixSum, left.sum + right.bestPrefixSum);
	tree[treeNode].bestSuffixSum = max(right.bestSuffixSum, right.sum + left.bestSuffixSum);
	
	// maximumSum is the main thing, that will be computed by the children
	tree[treeNode].maximumSum = max(left.maximumSum, max(max(right.maximumSum, left.sum + right.bestPrefixSum), max(right.sum + left.bestSuffixSum, left.bestSuffixSum + right.bestPrefixSum)));

	return;
}

void updateTree(int *arr, node *tree, int start, int end, int treeNode, int index, int value) {
	
	if(start == end) {
		arr[index] = value;
		tree[treeNode].sum = arr[start];
		tree[treeNode].maximumSum = arr[start];
		tree[treeNode].bestPrefixSum = arr[start];
		tree[treeNode].bestSuffixSum = arr[start];

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

	tree[treeNode].sum = left.sum + right.sum;
	tree[treeNode].bestPrefixSum = max(left.bestPrefixSum, left.sum + right.bestPrefixSum);
	tree[treeNode].bestSuffixSum = max(right.bestSuffixSum, right.sum + left.bestSuffixSum);

	tree[treeNode].maximumSum = max(left.maximumSum, max(max(right.maximumSum, left.sum + right.bestPrefixSum), max(right.sum + left.bestSuffixSum, left.bestSuffixSum + right.bestPrefixSum)));

	return;
}

node queryTree(node *tree, int start, int end, int treeNode, int left, int right) {
		
	if(end < left || start > right) {
		// completely outside
		node answer;
		answer.sum = INT_MIN;
		answer.maximumSum = INT_MIN;
		answer.bestPrefixSum = INT_MIN;
		answer.bestSuffixSum = INT_MIN;

		return answer;
	}

	if(start >= left && end <= right) {
		return tree[treeNode];
	}

	int mid = (start + end) / 2;
	node answer1 = queryTree(tree, start, mid, 2 * treeNode, left, right);
	node answer2 = queryTree(tree, mid + 1, end, 2 * treeNode + 1, left, right);

	node answer;
	answer.sum = answer1.sum + answer2.sum;
	answer.bestPrefixSum = max(answer1.bestPrefixSum, answer1.sum + answer2.bestPrefixSum);
	answer.bestSuffixSum = max(answer2.bestSuffixSum, answer2.sum + answer1.bestSuffixSum);
	answer.maximumSum = max(answer1.maximumSum, max(max(answer2.maximumSum, answer1.sum + answer2.bestPrefixSum), max(answer2.sum + answer1.bestSuffixSum, answer1.bestSuffixSum + answer2.bestPrefixSum)));

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
		cout << tree[i].maximumSum << "  ";
	}
	cout << endl << endl;

	int index, value;
	cin >> index >> value;

	updateTree(arr, tree, 0, n - 1, 1, index, value);
	for(int i = 0; i < 3 * n; i++) {
		cout << tree[i].maximumSum << "  ";
	}
	cout << endl << endl;

	int left, right;
	cin >> left >> right;

	cout << queryTree(tree, 0, n - 1, 1, left, right).maximumSum << endl << endl;

	return 0;
}
