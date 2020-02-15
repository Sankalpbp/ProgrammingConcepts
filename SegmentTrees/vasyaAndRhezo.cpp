# include <iostream>
using namespace std;

struct treeNode {
		
	int a;
	int b;
	int index;
};

void buildTree(int *arr1, int *arr2, treeNode *tree, int start, int end, int currTreeNode) {
		
	if(start == end) {
		
		tree[currTreeNode].index = start + 1;
		tree[currTreeNode].a = arr1[start];
		tree[currTreeNode].b = arr2[start];

		return;
	}

	int mid = (start + end) / 2;

	buildTree(arr1, arr2, tree, start, mid, 2 * currTreeNode);
	buildTree(arr1, arr2, tree, mid + 1, end, 2 * currTreeNode + 1);

	if(tree[2 * currTreeNode].a > tree[2 * currTreeNode + 1].a) {
		tree[currTreeNode].a = tree[2 * currTreeNode].a;
		tree[currTreeNode].b = tree[2 * currTreeNode].b;
		tree[currTreeNode].index = tree[2 * currTreeNode].index;
	} else if(tree[2 * currTreeNode].a < tree[2 * currTreeNode + 1].a) {
		tree[currTreeNode].a = tree[2  *currTreeNode + 1].a;
		tree[currTreeNode].b = tree[2 * currTreeNode + 1].b;
		tree[currTreeNode].index = tree[2 * currTreeNode + 1].index;
	} else if(tree[2 * currTreeNode].a == tree[2 * currTreeNode + 1].a && tree[2 * currTreeNode].b < tree[2 * currTreeNode + 1].b) {
		tree[currTreeNode].a = tree[2 * currTreeNode].a;
		tree[currTreeNode].b = tree[2 * currTreeNode].b;
		tree[currTreeNode].index = tree[2 * currTreeNode].index;
	} else if(tree[2 * currTreeNode].a == tree[2 * currTreeNode + 1].a && tree[2 * currTreeNode].b > tree[2 * currTreeNode + 1].b) {
		tree[currTreeNode].a = tree[2 * currTreeNode + 1].a;
		tree[currTreeNode].b = tree[2 * currTreeNode + 1].b;
		tree[currTreeNode].index = tree[2 * currTreeNode + 1].index;
	} else if(tree[2 * currTreeNode].index < tree[2 * currTreeNode + 1].index) {
		tree[currTreeNode].a = tree[2 * currTreeNode].a;
		tree[currTreeNode].b = tree[2 * currTreeNode].b;
		tree[currTreeNode].index = tree[2 * currTreeNode].index;
	} else if(tree[2 * currTreeNode].index > tree[2 * currTreeNode + 1].index) {
		tree[currTreeNode].a = tree[2 * currTreeNode + 1].a;
		tree[currTreeNode].b = tree[2 * currTreeNode + 1].b;
		tree[currTreeNode].index = tree[2 * currTreeNode + 1].index;
	}
}

treeNode queryTree(treeNode *tree, int start, int end, int left, int right, int currTreeNode) {
	
	if(left > end || right < start) {
		treeNode answer;
		answer.a = 0;
		answer.b = 0;
		answer.index = 0;
		
		return answer;
	}

	if(start >= left && end <= right) {
		treeNode answer;
		answer.a = tree[currTreeNode].a;
		answer.b = tree[currTreeNode].b;
		answer.index = tree[currTreeNode].index;

		return answer;
	}

	int mid = (start + end) / 2;

	treeNode answer1 = queryTree(tree, start, mid, left, right, 2 * currTreeNode);
	treeNode answer2 = queryTree(tree, mid + 1, end, left, right, 2 * currTreeNode + 1);

	if(answer1.a > answer2.a) {
		return answer1;
	} else if(answer2.a > answer1.a) {
		return answer2;
	} else if(answer1.a == answer2.a && answer1.b < answer2.b) {
		return answer1;
	} else if(answer1.a == answer2.a && answer1.b > answer2.b) {
		return answer2;
	} else if(answer1.index > answer2.index) {
		return answer2;
	}
	
	return answer1;
}

int main(void) {
		
	int n;
	cin >> n;

	int *arr1 = new int[n];
	int *arr2 = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	for(int i = 0; i < n; i++) {
		cin >> arr2[i];
	}

	treeNode *tree = new treeNode[4 * n];

	buildTree(arr1, arr2, tree, 0, n - 1, 1);

	int queries;
	cin >> queries;

	for(int i = 0; i < queries; i++ ){
		int left, right;
		cin >> left >> right;
		treeNode node = queryTree(tree, 0, n - 1, left, right, 1);
		cout << node.index << endl << endl;
	}

	return 0;
}
