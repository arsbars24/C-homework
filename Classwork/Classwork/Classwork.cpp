// ifstream input file only for reading
//fin (name txt)
#include <iostream>
#include <fstream>
using namespace std;

int** ReadMatrix(string s, int& n, int& m) {
	ifstream fin(s);
	
	fin >> n >> m;
	int** a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
		for (int j = 0; j < m; j++)
			fin >> a[i][j];
	}
	return a;
}

int main() {
	int n, m;
	string s;
	cin >> s;
	int** arr = ReadMatrix(s, n, m);
	return 0;
}