#include <iostream>
#include <fstream>
using namespace std;
//метод чтения матрицы
// печать матрицы
// произведение 2 матриц
// запись

int** readMatrix(ifstream&, int&, int&);
void printMatrix(int**, int, int);
int** multMatrix();
int** streamMatrix();


int main()
{
	int n, m, k;
	ifstream fin("matrix.txt");
	//ofstream fout(path2);
	// path and path2 make later
	int** a, // **b, **c; // matrix
	a = readMatrix(fin, n, m);// & при описании
	//b = readMatrix(fin, m, k);
	printMatrix(a, n, m);
	//printMatrix(b, m, k);
	//c = multMatrix(a, b, n, m, k);
	//printMatrix(c, n, k);
	//streamMatrix(fout, c, n, k);
	return 0;
}

int** readMatrix(ifstream& fin, int& n, int& m) {
	fin >> n >> m;
	int** a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
		for (int j = 0; j < m; j++) {
			fin >> a[i][j];
		}
	}
	return a;
}

void printMatrix(int** a, int n, int m) {
	cout << n << " " << m << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
	}
	cout << endl;
}
