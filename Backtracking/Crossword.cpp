# include <iostream>
# include <string>
# include <vector>
using namespace std;

bool isVerticallyValid(char crossword[0][10], string word, int row, int column) {

	int count = 0;

	for(int i = 0; i < word.length(); i++) {
	
		if((crossword[row + i][column] == '-') || (crossword[row + i][column] == word[i])) {
		
			count++;
		}

		if(crossword[row + i][column] == '+') {
			return false;
		}
	}

	if(count != word.size()) {
		return false;
	}

	return true;
}

bool isHorizontallyValid(char crossword[0][10], string word, int row, int column) {

	int count = 0;

	for(int i=0; i<word.length(); i++) {
	
		if((crossword[row][column + i] == '-') || (crossword[row][column + i] == word[i])) {
		
			count++;
		}

		if(crossword[row][column + i] == '+') {
		
			return false;
		}
	}

	if(count != word.size()) {
	
		return false;
	}

	return true;
}

void setVertically(char crossword[][10], string word, vector<string> &helper, int i, int j) {

	string help = "";

	for(int k =0; k < word.length(); k++) {
	
		if(crossword[i][j] == '-') {
			crossword[i][j] = word[k];
			help += 'T';
		} else {
			help += 'F';
		}
		i++;
	}

	help += '\0';
	helper.push_back(help);
}

void setHorizontally(char crossword[][10], string word, vector<string> &helper, int i, int j) {

	string help = "";

	for(int k = 0; k < word.length(); k++) {
	
		if(crossword[i][j] == '-') {
			crossword[i][j] = word[k];
			help += 'T';
		} else {
			help += 'F';
		}
		j++;
	} 

	help += '\0';
	helper.push_back(help);
}

void resetVertically(char crossword[][10], string word, vector<string> &helper, int i, int j) {

	int Length = helper.size();
	string help = helper[Length - 1];
	helper.pop_back();

	for(int k=0; k < help.length(); k++) {
		if(help[k] == 'T') {
			crossword[i][j] = '-';
		} 
		i++;
	}

	return;
}

void resetHorizontally(char crossword[][10], string word, vector<string> &helper, int i, int j) {

	int Length = helper.size();
	string help = helper[Length - 1];
	helper.pop_back();

	for(int k =0 ; k<help.length(); k++) {
		if(help[k] == 'T') {
			crossword[i][j] = '-';
		}
		j++;
	}
	return;
}

bool solveCrossword(char crossword[][10], vector<string> &words, vector<string> &helper, int index) {

	if(index == words.size()) {
	
		// we have reached the base case essentially
		//print the crossword
		for(int i=0; i<10; i++) {
			for(int j=0; j<10; j++) {
				cout << crossword[i][j];
			}
			cout << endl;
		}

		cout << endl;
		return true;
	}

	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {

			if(words[index][0] == crossword[i][j] || crossword[i][j] == '-') {
			
				if(isVerticallyValid(crossword, words[index], i, j)) {
					
					setVertically(crossword, words[index], helper, i, j);
					if(solveCrossword(crossword, words, helper, index + 1)) {
						return true;
					}
					resetVertically(crossword, words[index], helper, i, j);
				}
			
				if(isHorizontallyValid(crossword, words[index], i, j)) {
				
					setHorizontally(crossword, words[index], helper, i, j);
					if(solveCrossword(crossword, words, helper, index + 1)) {
						return true;
					}
					resetHorizontally(crossword, words[index], helper, i, j);
				}
			}
		}
	}

	return false;
}

int main(void) {

	char crossword[10][10];

	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			cin >> crossword[i][j];
		}
	}

	string s;
	cin >> s;
	
	vector<string> words;
	string word = "";

	int i = 0;

	while(s[i] != '\0') {

		if(s[i] == ';') {
			words.push_back(word);
			word = "";
		} else {
			word += s[i];
		}
		i++;
	}

	words.push_back(word);
	int size = words.size();

	vector<string> helper(size);

	solveCrossword(crossword, words, helper, 0);
	cout << endl << endl;

	return 0;
}
