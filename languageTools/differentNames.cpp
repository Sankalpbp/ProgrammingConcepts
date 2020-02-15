# include <iostream>
# include <map>
# include <string>
using namespace std;

int main(void) {

	string str;
	getline(cin, str);

	map<string, int> m;

	string s = "";
	for(int i=0; str[i]; i++) {
		
		if(str[i] != ' ') {
			s += str[i];
		}

		if(str[i] == ' ') {
			m[s]++;
			s = "";
		}
		if(str[i+1] == '\0') {
			m[s]++;
		}
	}	

	map<string, int> :: iterator it;

	for(it = m.begin(); it != m.end(); it++) {
		
		if(it -> second > 1) {
			cout << it -> first << " " << it -> second << "\n";
		}
	}	
	
	return 0;
}
