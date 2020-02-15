# include <iostream>
# include <map>
using namespace std;

int main(void) {

    int n;
    cin >> n;

    char str[n];
    cin >> str;

    map<char, int> m;
    for(int i=0; i<str.size(); i++) {
        m[str[i]]++;
    }

    map<char, int> :: iterator it;

    cout << m['a'] << " " << m['s'] << " " << m['p'] << "\n";

    return 0;
}
