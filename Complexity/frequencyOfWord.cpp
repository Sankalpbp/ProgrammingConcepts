# include <iostream>
# include <string>
# include <map>

using namespace std;

int main(void) {

    string str;

    getline(cin, str);

    map<string, int> m;
    string *currentString = NULL;

    int i=0;
    for(int k=0; k<str.size(); k++) {

        if(str[k] != 32) {
            currentString[i++] = str[k];
        } else {

            currentString[i] = '\0';
            i=0;
            cout << "\n\n" << currentString << " \n\n";
            if(m.find(currentString) == m.end()) {
                m[currentString] = 1;
            } else {
                m[currentString]++;
            }

            currentString = "";
        }
    }

    map<string, int> :: iterator it;

    for(it = m.begin(); it != m.end() ;it++) {
        cout << it -> first << "  " << it -> second << "\n";
    }
}
