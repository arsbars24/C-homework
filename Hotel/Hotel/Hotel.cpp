#include <iostream>
#pragma
using namespace std;
void inpArr(int**&, int&, int&);
void outputArray(int**, int);

int main() {
	int n, num;
	int** a;
	num = 1;
	inpArr(a, n, num);
	outputArray(a, n);
	return 0;
} 

void inpArr(int**& b, int& n, int& num) {
	int k = n - 1;
	cin >> n;
	b = new int* [n];
	for (int i = 0; i < n; i++) {
		b[i] = new int[n]; // row
		for (int j = 0; j < n; j++) {
			b[i][j] = 0;
		}
	for (int i = n; i > 0; --i) {
		int column = i; int str = 0;
		for (int j = 0; j < k; ++j) {
			b[--column - 1][++str] = num;
			++num;
		}
		--k;

	}
	k = 1;
	for (int j = n; j > 0; --j) {
		int column = 0; int str = j;
		for (int i = 0; i < k; ++i) {
			b[++column][--str] = num;
			++num;
		}
		++k;
	}
	}
}

void outputArray(int** b, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) { //output square matrix
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}

}