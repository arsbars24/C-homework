#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* num = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	int j, p;
	j = 0;
	
	while (j < n) {
		for (int p = j + 1; p < n; ++p) {
			cout << num[j] << ',' << num[p] << ' ';
		}
		++j;
	}
	
	
	
	/*
	for (int j = 0; j < sizeof(A) / sizeof(A[0]); ++j) {
		for (int p = j + 1; p < sizeof(A) / sizeof(A[0]); ++p) {
			cout << A[j] << ' ' << A[p] << endl;
		}
	}
	*/
}