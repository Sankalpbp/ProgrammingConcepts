# include <iostream>
# include <algorithm>
# include <string>

using namespace std;

struct Student {
	string name;
	int totalMarks;
	int rollNumber;
};

bool comparator(Student& s1, Student& s2) {
	if(s1.totalMarks == s2.totalMarks) {
		return s1.rollNumber < s2.rollNumber;
	}

	return s1.totalMarks > s2.totalMarks;
}

int main(void) {
	
	int n;
	cin >> n;

	Student *arr = new Student[n];

	int marks;

	for(int i=0; i<n; i++) {
		cin >> arr[i].name;
		arr[i].totalMarks = 0;
		for(int j=0; j<3; j++) {
			cin >> marks;
			arr[i].totalMarks += marks;
		}
		arr[i].rollNumber = i+1;	
	}


	sort(arr, arr + n, comparator);	

	for(int i=1; i<=n; i++) {
		cout << i << " " <<  arr[i - 1].name << "\n";
	}

	return 0;
}
