# include <iostream>
using namespace std;

void buildSegmentTree(string s, int *tree, int start, int end, int currTreeNode) {
		
	if(start == end) {
		tree[currTreeNode] = s[start] - '0';
		return;
	}

	int mid = (start + end) / 2;

	buildSegmentTree(s, tree, start, mid, 2 * currTreeNode + 1);
	buildSegmentTree(s, tree, mid + 1, end, 2 * currTreeNode + 2);

	tree[currTreeNode] = (tree[2 * currTreeNode + 1] * ((end - mid) % 2 + 1) + tree[2 * currTreeNode + 2]) % 3;
}

void update(int index, int *tree, int start, int end, int currTreeNode) {
		
	if(start == end) {
		tree[currTreeNode] = 1;
		return;
	}

	int mid = (start + end) / 2;

	if(index > mid) {
		update(index, tree, mid + 1, end, 2 * currTreeNode + 1);
	} else {
		update(index, tree, start, mid, 2 * currTreeNode);
	}

	tree[currTreeNode] = (tree[2 * currTreeNode + 1] * ((end - mid) % 2 + 1) + tree[2 * currTreeNode + 2]) % 3;
}

void update(int index, string &s, int *tree, int n) {
	
	if(s[index] == '1') {
		return;
	}

	update(index, tree, 0, n - 1, 0);
	s[index] = '1';
}

int query(int *tree, int start, int end, int left, int right, int currTreeNode) {
		
	if(left > right || left > end || start > right) {
		return 0;
	}

	if(left <= start && end <= right) {
		return (tree[currTreeNode] * ((right - end) % 2 + 1)) % 3;
	}

	int mid = (start + end) / 2;

	int answer1 = query(tree, start, mid, left, right, 2 * currTreeNode);
	int answer2 = query(tree, mid + 1, end, left, right, 2 * currTreeNode + 1);

	return answer1 + answer2;
}

int main(void) {
		
	int n, a = 0;
	cin >> n;

	string s;
	cin >> s;

	while((1 << a) < n) {
		a++;
	}
	a++;

	int *tree = new int[1 << a];

	buildSegmentTree(s, tree, 0, n - 1, 0);

	long queries;
	cin >> queries;

	while(queries--) {
		int t;
		int left, right;
		cin >> t;

		switch(t) {
			
			case 0:
				cin >> left >> right;
				cout << query(tree, 0, n - 1, left, right, 0) << "\n";
				break;

			case 1:
				cin >> left;
				update(left, s, tree, n);
				break;
		}
	}
	
	return 0;
}
