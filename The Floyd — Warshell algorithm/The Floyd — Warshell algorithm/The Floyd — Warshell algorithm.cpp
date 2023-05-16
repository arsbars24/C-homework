#include <iostream>
#include <fstream>

using namespace std;
int main() {
	const int n = 4;
	int** ary = new int* [n];
	int** par = new int* [n];
	for (int i = 0; i < n; ++i) {
		ary[i] = new int[n];
	}
	for (int i = 0; i < n; ++i) {
		par[i] = new int[n];
	}
	ifstream file;
	file.open("matrix.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			file >> ary[i][j];
		}
	}

	ifstream file2;
	file2.open("matrixp.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			file2 >> par[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ary[i][j] << ' ';
		}
		cout << std::endl;
	}

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (ary[i][j] > ary[i][k] + ary[k][j]) {
					ary[i][j] = ary[i][k] + ary[k][j];
					par[i][j] = k + 1;
				}
	cout << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ary[i][j] << ' ';
		}
		cout << std::endl;
	}
	cout << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << par[i][j] << ' ';
		}
		cout << std::endl;
	}

}