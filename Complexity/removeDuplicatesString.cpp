# include <map>
# include <iostream>
# include <string>
# include <set>
# include <vector>

using namespace std;

int main(void) {

    string str;
    cin >> str;

    // set<char> s;
    vector<char> v;
    // for(int i=0; i<str.size(); i++) {
    //     if(s.find(str[i]) == s.end()) {
    //         s.insert(str[i]);
    //         v.push_back(str[i]);
    //     }
    // }
    //
    vector<char> :: iterator it;


    map<char, bool> m;
    for(int i=0; i<str.size(); i++) {
        if(m[str[i]] == false) {
            v.push_back(str[i]);
            m[str[i]] = true;
        }
    }

    for(it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}
