# include <iostream>
using namespace std;

class treeNode {
	
	public:
		int sum;
		int squareSum;
};

class lazyNode {
	
	public:
		int set;
		int update;
};

void buildTree(int *arr, treeNode *tree, int start, int end, int currTreeNode) {

	if(start == end) {
		tree[currTreeNode].squareSum = arr[start] * arr[start];
		tree[currTreeNode].sum = arr[start];
		return;
	}
	
	int mid = (start + end) / 2;

	buildTree(arr, tree, start, mid, 2 * currTreeNode);
	buildTree(arr, tree, mid + 1, end, 2 * currTreeNode + 1);

	tree[currTreeNode].sum = tree[2 * currTreeNode].sum + tree[2 * currTreeNode + 1].sum;
	tree[currTreeNode].squareSum = tree[2 * currTreeNode].squareSum + tree[2 * currTreeNode + 1].squareSum;
}

void update(treeNode *tree, lazyNode *lazy, int start, int end, int left, int right, int value, int queryType, int currTreeNode) {
	
	if(start > end) {
		return;
	}

	if(lazy[currTreeNode].set != 0) {
		int x = lazy[currTreeNode].set;
		tree[currTreeNode].sum = x * (end - start + 1);
		tree[currTreeNode].squareSum = x * x * (end - start + 1);

		if(start != end) {
			lazy[2 * currTreeNode].update = 0;
			lazy[2 * currTreeNode].set = x;
			lazy[2 * currTreeNode + 1].update = 0;
			lazy[2 * currTreeNode + 1].set = x;
		}
		lazy[currTreeNode].set = 0;
	}

	if(lazy[currTreeNode].update != 0) {
		int x = lazy[currTreeNode].update;
		tree[currTreeNode].sum += x * (end - start + 1);
		tree[currTreeNode].squareSum += x * x * (end - start + 1);

		// check if its the leaf node
		if(start != end) {
			lazy[2 * currTreeNode].update += x;
			lazy[2 * currTreeNode + 1].update += x;
		}

		lazy[currTreeNode].update = 0;
	}

	// above all was done to get the tree in the latest correct state, the lazy updates etc. 
	// now the main logic for the updation between the interval will be done.

	if(end < left || start > right) {
		return;
	}

	if(start >= left && end <= right) {
		// for if there is complete overlapping. then, the values of the elements will be updated according to the type of query

		// queryType = 0 is for the setting part
		if(queryType == 0) {
			
			// that is there is a "set" stuff to do
			tree[currTreeNode].sum = value * (end - start + 1);
			tree[currTreeNode].squareSum = value * value * (end - start + 1);

			if(start != end) {
				// that is, if the node at hand is not the leaf node
				// then, instead of making changes in the nodes of the concerned node, we will make changes in the corresponding lazyTree node
				lazy[2 * currTreeNode].set = value;
				lazy[2 * currTreeNode].update = 0;
				lazy[2 * currTreeNode + 1].set = value;
				lazy[2 * currTreeNode + 1].update = 0;
			}
		} else {
			// that is for queryType = 1, we gotta update the stuff
			tree[currTreeNode].squareSum = value * value * (end - start + 1) + 2 * value * tree[currTreeNode].sum;
			tree[currTreeNode].sum = value * (end - start + 1);

			if(start != end) {
				lazy[2 * currTreeNode].update += value;
				lazy[2 * currTreeNode + 1].update += value;
			}
		}

		return;
	}

	int mid = (start + end) / 2;
	update(tree, lazy, start, mid, left, right, value, queryType, 2 * currTreeNode);
	update(tree, lazy, mid + 1, end, left, right, value, queryType, 2 * currTreeNode + 1);

	tree[currTreeNode].sum = tree[2 * currTreeNode].sum + tree[2 * currTreeNode + 1].sum;
	tree[currTreeNode].squareSum = tree[2 * currTreeNode].squareSum + tree[2 * currTreeNode + 1].squareSum;
}

int query(treeNode *tree, lazyNode *lazy, int start, int end, int left, int right, int currTreeNode) {
		
	if(start > end) {
		return 0;
	}

	if(lazy[currTreeNode].set != 0) {
		
		int x = lazy[currTreeNode].set;

		tree[currTreeNode].sum = x * (end - start + 1);
		tree[currTreeNode].squareSum = x * x * (end - start + 1);

		if(start != end) {
			lazy[2 * currTreeNode].set = x;
			lazy[2 * currTreeNode].update = 0;
			lazy[2 * currTreeNode + 1].set = x;
			lazy[2 * currTreeNode + 1].update = 0;
		}

		lazy[currTreeNode].set = 0;
	}

	if(lazy[currTreeNode].update != 0) {
		
		int x = lazy[currTreeNode].update;
		tree[currTreeNode].squareSum += x * x * (end - start + 1) + 2 * x * tree[currTreeNode].sum;
		tree[currTreeNode].sum += x * (end - start + 1);

		if(start != end) {
			lazy[2 * currTreeNode].update += x;
			lazy[2 * currTreeNode + 1].update += x;
		}

		lazy[currTreeNode].update = 0;
	}

	if(end < left || start > right) {
		return 0;
	}

	if(start >= left && end <= right) {
		return tree[currTreeNode].squareSum;
	}

	int mid = (start + end) / 2;

	int answer1 = query(tree, lazy, start, mid, left, right, 2 * currTreeNode);
	int answer2 = query(tree, lazy, mid + 1, end, left, right, 2 * currTreeNode + 1);

	return (answer1 + answer2);
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
		cout << tree[i].squareSum << "  ";
	}
	cout << endl << endl;

	lazyNode *lazy = new lazyNode[4 * n];
	for(int i = 0; i < 4 * n; i++) {
		lazy[i].set = 0;
		lazy[i].update = 0;
	}

	int queries;
	cin >> queries;

	for(int i = 0; i < queries; i++) {
		int qType;
		cin >> qType;

		if(qType == 0 || qType == 1) {
				
			int left, right, value;
			cin >> left >> right >> value;

			update(tree, lazy, 1, n, left, right, value, qType, 1);
		} else if(qType == 2) {
			int left, right;
			cin >> left >> right;

			cout << query(tree, lazy, 1, n, left, right, 1) <<  endl << endl;
		}
	}

	return 0;
}
