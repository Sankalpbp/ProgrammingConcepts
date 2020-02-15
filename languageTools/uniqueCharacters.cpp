# include <iostream>
# include <map>

using namespace std;

int main(void) {

	string str;
	cin >> str;

	map<char, bool> m;
	string s;

	for(int i=0; i<str.size(); i++) {
		if(m[str[i]] == false) {
			m[str[i]] = true;
			s += str[i];
		}
	}

	cout << s << endl;

	return 0;
}
