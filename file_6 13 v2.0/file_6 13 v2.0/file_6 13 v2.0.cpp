#include <iostream>
#include <fstream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	double** x;
	x = new double* [n];
	for (int i = 0; i < n; i++) x[i] = new double[m];
	//int** rows = new int* [n];
	//for (int i = 0; i < n; i++) int* rows = new int[2];
	ifstream in("matrix.txt");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			in >> x[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
 }