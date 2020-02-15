# include <iostream>
using namespace std;

struct treeNode {
	
	int odds;
	int evens;
};

void buildTree(int *arr, treeNode *tree, int start, int end, int currTreeNode) {
	
	if(start == end) {

		if(arr[start] % 2 == 0) {
			tree[currTreeNode].odds = 0;
			tree[currTreeNode].evens = 1;
		} else {
			tree[currTreeNode].odds = 1;
			tree[currTreeNode].evens = 0;
		}

		return;
	}

	int mid = (start + end) / 2;

	buildTree(arr, tree, start, mid, 2 * currTreeNode);
	buildTree(arr, tree, mid + 1, end, 2 * currTreeNode + 1);

	tree[currTreeNode].evens = tree[2 * currTreeNode].evens + tree[2 * currTreeNode + 1].evens;
	tree[currTreeNode].odds = tree[2 * currTreeNode].odds + tree[2 * currTreeNode + 1].odds;
}

void updateTree(int *arr, treeNode *tree, int start, int end, int currTreeNode, int index, int value) {
		
	if(start == end) {

		arr[index] = value;
		
		if(arr[start] % 2 == 0) {
			tree[currTreeNode].evens = 1;
			tree[currTreeNode].odds = 0;
		} else {
			tree[currTreeNode].evens = 0;
			tree[currTreeNode].odds = 1;
		}
		return;
	}

	int mid = (start + end) / 2;

	if(index > mid) {
		updateTree(arr, tree, mid + 1, end, 2 * currTreeNode + 1, index, value);
	} else {
		updateTree(arr, tree, start, mid, 2 * currTreeNode, index, value);
	}

	tree[currTreeNode].evens = tree[2 * currTreeNode].evens + tree[2 * currTreeNode + 1].evens;
	tree[currTreeNode].odds = tree[2 * currTreeNode].odds + tree[2 * currTreeNode + 1].odds;
}

int queryTreeEven(treeNode *tree, int start, int end, int currTreeNode, int left, int right) {
		
	if(start > right || end < left) {
		return 0;
	}

	if(left <= start && end <= right) {
		return tree[currTreeNode].evens;
	}

	int mid = (start + end) / 2;

	int answer1 = queryTreeEven(tree, start, mid, 2 * currTreeNode, left, right);
	int answer2 = queryTreeEven(tree, mid + 1, end, 2 * currTreeNode + 1, left, right);

	return answer1 + answer2;
}

int queryTreeOdd(treeNode *tree, int start, int end, int currTreeNode, int left, int right) {
	
	if(start > right || end < left) {
		return 0;
	}

	if(left <= start && end <= right) {
		return tree[currTreeNode].odds;
	}

	int mid = (start + end) / 2;

	int answer1 = queryTreeOdd(tree, start, mid, 2 * currTreeNode, left, right);
	int answer2 = queryTreeOdd(tree, mid + 1, end, 2 * currTreeNode + 1, left, right);

	return answer1 + answer2;
}
		

int main(void) {
		
	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	treeNode *tree = new treeNode[4 * n];

	buildTree(arr, tree, 0, n - 1, 1);

	for(int i = 0; i < 4 * n; i++) {
		cout << tree[i].evens << " " << tree[i].odds << endl;
	}

	int queries;
	cin >> queries;

	for(int i = 0; i < queries; i++) {
		int input1, input2, type;
		cin >> type >> input1 >> input2;

		if(type == 0) {
			updateTree(arr, tree, 0, n - 1, 1, input1 - 1, input2);
		} else {
			
			if(type == 1) {
				cout << queryTreeEven(tree, 0, n - 1, 1, input1 - 1, input2 - 1) << endl << endl;
			} else if(type == 2) {
				cout << queryTreeOdd(tree, 0, n - 1, 1, input1 - 1, input2 - 1) << endl << endl;
			}
		}
	}

	return 0;
}
