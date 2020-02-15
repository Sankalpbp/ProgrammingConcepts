# include <iostream>
# include <algorithm>
# include <map>
using namespace std;

void printLongestSubsequence(int *arr, int n) {
    
    // this is an O(nlogn) solution
    sort(arr, arr+n);

    int startIndex = 0;
    int length = 1;

    int finalStartIndex = 0;
    int finalLength = 0;

    int i = 1;
 
	while(i < n) {
        if(arr[i] == arr[i - 1] + 1) {
          i++;
          length++;
        }  else {
            if(finalLength < length) {
                finalLength = length;
                startIndex = i - length;  
            }
            i++;
            length = 1;
        }
    }

	if(i == n) {
		if(length > finalLength) {
			finalLength = length;
			startIndex = i - length;
		}
	}
	
    for(int i=0; i<finalLength; i++) {
        cout << arr[i + startIndex] << " ";
    }
}

void printLongestSubseqEfficient(int *arr, int n) {
	
	map<int, bool> m;

	for(int i=0; i<n; i++) {
		m[arr[i]] = true;
	}

	int lengthOfSubs = 1;
	int max = 0;
	int start = -10;

	for(int i=0; i<n; i++) {

		if(m[arr[i]] == true) {
			
			int find = arr[i] + 1;
			while(m[find] == true) {
				lengthOfSubs += 1;
				m[find] = false;
				find += 1;
			}

			find = arr[i] - 1;
			while(m[find] == true) {
				lengthOfSubs += 1;
				m[find] = false;
				find -= 1;
			}

			if(max < lengthOfSubs) {
				start = find + 1;
				max = lengthOfSubs;
			}

			lengthOfSubs = 1;
		}
	}

	cout << max << " " << start << endl;

	for(int i=0; i<max; i++) {
		cout << start << " ";
		start += 1;
	}
	cout << endl << endl;
}

int main(void) {
    
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

//    printLongestSubsequence(arr, n);
    cout << endl;
    printLongestSubseqEfficient(arr, n);
    cout << endl;

    return 0;
}    

 
