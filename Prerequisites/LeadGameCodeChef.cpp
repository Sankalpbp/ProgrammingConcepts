// this is a codechef problem
// here is the link to it
// https://www.codechef.com/problems/TLG

# include <iostream>
using namespace std;

int main(void) {

    int n;
    cin >> n;
    int first, second;

    int cumulativeFirst = 0;
    int cumulativeSecond = 0;

    int maxLead = 0;
    short int maxLeadPlayer = 1;

    for(int i=0; i<n; i++) {
        cin >> first;
        cin >> second;

        int currLead = 0;
        int currLeadPlayer = 1;

        cumulativeFirst += first;
        cumulativeSecond += second;

        if(cumulativeFirst > cumulativeSecond) {
            currLead = cumulativeFirst - cumulativeSecond;
            currLeadPlayer = 1;
        } else {
            currLead = cumulativeSecond - cumulativeFirst;
            currLeadPlayer = 2;
        }

        if(currLead > maxLead) {
            maxLead = currLead;
            maxLeadPlayer = currLeadPlayer;
        }
    }

    cout << maxLeadPlayer << " " << maxLead << endl;
}
