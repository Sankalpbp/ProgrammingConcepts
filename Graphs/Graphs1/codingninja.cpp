# include <iostream>
# include <vector>
# include <utility>
using namespace std;

bool stringPossible(string s, int i, int j, bool **visited, char **matrix, int rows, int cols) {
	
	if(i == rows || j == cols || i < 0 || j < 0) {
		return false;
	}

	if(s[0] == '\0') {
		return true;
	}

	if(matrix[i][j] != s[0]) {
		return false;
	}

	visited[i][j] = true;
	
	bool *returnStuff = new bool[8];
	returnStuff[0] = stringPossible(s.substr(1), i - 1, j - 1, visited, matrix, rows, cols);
	returnStuff[1] = stringPossible(s.substr(1), i + 1, j - 1, visited, matrix, rows, cols);
	returnStuff[2] = stringPossible(s.substr(1), i - 1, j + 1, visited, matrix, rows, cols);
	returnStuff[3] = stringPossible(s.substr(1), i + 1, j + 1, visited, matrix, rows, cols);
	returnStuff[4] = stringPossible(s.substr(1), i, j - 1, visited, matrix, rows, cols);
	returnStuff[5] = stringPossible(s.substr(1), i, j + 1, visited, matrix, rows, cols);
	returnStuff[6] = stringPossible(s.substr(1), i - 1, j, visited, matrix, rows, cols);
	returnStuff[7] = stringPossible(s.substr(1), i + 1, j, visited, matrix, rows, cols);
	
	bool answer = false;

	for(int i = 0; i < 8; i++) {
		answer = answer || returnStuff[i];
	}

	return answer;
}

void makeFalse(bool **visited, int rows, int cols) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			visited[i][j] = false;
		}
	}
}

bool ifStringPossible(char **matrix, int rows, int cols) {
		
	string s = "CODINGNINJA";
	
	vector<pair<int, int>> cS;
	
	// FINDING FIRST 'C'
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(matrix[i][j] == 'C') {
				cS.push_back(make_pair(i, j));
			}
		}
	}

	bool **visited = new bool* [rows];
	for(int i = 0; i < rows; i++) {
		visited[i] = new bool[cols];
	}

	makeFalse(visited, rows, cols);

	for(int i = 0; i < cS.size(); i++) {
		makeFalse(visited, rows, cols);
		int k = cS[i].first;
		int l = cS[i].second;
		if(stringPossible(s, k, l, visited, matrix, rows, cols)) {
			return true;		
		}
	}

	return false;
}

int main(void) {

	int rows, cols;
	cin >> rows >> cols;

	char **matrix = new char* [rows];
	for(int i = 0; i < rows; i++) {
		matrix[i] = new char[cols];
		for(int j = 0; j < cols; j++) {
			cin >> matrix[i][j];
		}
	}

	if(ifStringPossible(matrix, rows, cols)) {
		cout << "\nYes";
	} else {
		cout << "\nNo";
	}
		
	return 0;
}
