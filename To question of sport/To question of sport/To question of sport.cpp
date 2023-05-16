#include <iostream>
using namespace std;

void input_array(int**&, int&);

void output_array(int**, int);

int main() {
	int n, m; // if cin m and n in main no need in & in input
	int** a;
	input_array(a, n);
	output_array(a, n);
	return 0;
}

void input_array(int**& b, int& n) {
	cin >> n;
	b = new int* [n]; // column of adress
	for (int i = 0; i < n; i++) {
		b[i] = new int[n]; // row
		for (int j = 0; j < n; j++) {
			cin >> b[i][j];
		}
		cout << endl;
	}
}

/*void output_array(int** b, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << b[i][j] << ' ';
	}
}*/
//выводит построчно массив
void output_array(int** b, int n) {
	int diag;
	
	for (diag = 0; diag < n; ++diag) {
		int i, j;
		for (i = 0; i < diag; ++i) {
			for (j = 0; j < diag; ++j) {
				cout << b[i][j];
			}
		}
	}
}