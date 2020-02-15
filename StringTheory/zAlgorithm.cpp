# include <iostream>
# include <vector>
using namespace std;

void fillZ(int * Z, string str) {
		
	int left = 0;
	int right = 0;

	int length = str.length();

	for(int i = 1; i < length; i++) {
		
		if(i > right) {
			// "i" doesn't lie between left and right.
			// therefore, Z[i] is zero for now
			left = i;
			right = i;

			while(right < length && str[right - left] == str[right]) {
				right++;
			}

			Z[i] = right - left;
			right--;		
		} else {
			int indexFromPreffix = i - left;

			if(Z[indexFromPreffix] <= right - i) {
				// "i" lies between left and right
				// Z will exist previously for this
				Z[i] = Z[indexFromPreffix];
			} else {
				// some part of Z is already included
				// you have to start matching further
				left = i;
				
				while(right < length && str[right - left] == str[right]) {
					right++;
				}
				Z[i] = right - left;
				right--;
			}
		}
	}
}

vector<int> zAlgorithm(string text, string pattern) {
		
	// creating the string that will be used for the work
	string str = pattern + "$" + text;
	int length = str.length();

	// creating the Z algorithm to store all the "Z" values in it.
	int * Z = new int[length];
	// call the fillZ function to calculate the z values
	fillZ(Z, str);

	vector<int> v;
	// now apply the main algorithm
	for(int i = 0; i < length; i++) {
		if(Z[i] == pattern.length()) {
			v.push_back(i - pattern.length() - 1);
		}
	}
	
	return v;
}

int main(void) {
		
	string text, pattern;
	cin >> text >> pattern;

	vector<int> matchingIndices = zAlgorithm(text, pattern);
	vector<int> :: iterator it = matchingIndices.begin();

	for(; it != matchingIndices.end(); it++) {
		cout << *it << " ";
	}

	cout << endl;
	return 0;
}
