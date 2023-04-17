#include <iostream>
using namespace std;

void input_array(int**&, int&, int&);

void output_array(int**, int, int);

int main() {
	int n, m; // if cin m and n in main no need in & in input
	int** a;
	input_array(a, n, m);
	output_array(a, n, m);
	return 0;
}

void input_array(int**& b, int& n, int& m) {
	cin >> n >> m;
	b = new int* [n]; // column of adress
	for (int i = 0; i < n; i++) {
		b[i] = new int[m]; // row
		for (int j = 0; j < n; j++) {
			cin >> b[i][j];
		}
		cout << endl;
	}
}

void output_array(int** b, int n, int m) {

}
