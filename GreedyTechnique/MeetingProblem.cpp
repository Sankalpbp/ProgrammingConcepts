// this is kinda Activity selection problem

#include <iostream>
# include <algorithm>
using namespace std;

class Meeting {
    
    public:
        int start;
        int finish;
        int order;
};

bool comparator(Meeting a, Meeting b) {
    return a.finish < b.finish;
}

int main() {
	//code
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    
	    Meeting arr[n];
	    for(int i=0; i<n; i++) {
	        cin >> arr[i].start;  
	        arr[i].order = i+1;
	    }
	    
	    for(int i=0; i<n; i++) {
	        cin >> arr[i].finish;
	    }
	    
	    sort(arr, arr+n, comparator);
	    
	    int number = 1;
        int lastFinish = arr[0].finish;
        cout << arr[0].order << " ";
        
        for(int i=1; i<n; i++) {
            if(arr[i].start > lastFinish) {
                number++;
                lastFinish = arr[i].finish;
                cout << arr[i].order << " ";
            }  
        }
        cout << "\n";
	}
	return 0;
}