# include <iostream>
# include <set>
# include <unordered_map>
# include <vector>

using namespace std;

int main(void) {

    vector<int> v;
    int num;
    cin >> num;
    while(num != -100) {
        v.push_back(num);
        cin >> num;
    }

//    works fine if the order is not the issue. But if it is... then.
    set<int> s;
    vector<int> :: iterator vIterator;
    for(vIterator = v.begin(); vIterator != v.end(); ++vIterator) {
        s.insert(*vIterator);
    }

    set<int> :: iterator sIterator;
    for(sIterator = s.begin() ; sIterator != s.end() ; ++sIterator) {
        cout << *sIterator << " ";
    }


    return 0;
}
