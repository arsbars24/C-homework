#include <iostream>
#include <fstream>

using namespace std;
void readMatrix(ifstream &fin, int **matrix, int n, int m) {
	
	if (fin.is_open()) {
		while (fin) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {

					fin >> matrix[i][j];
				}
			}
		}
		
		
	}
	else {
		cout << "File isn`t opened";
	}
	fin.close();
}
bool isTrue(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
		
			return false;
		}
	}
	//вывести что n простое. 
	return true;
}

int main() {
	cout << "Start" << endl;
	int summ = 0;
	bool flag;
	int n = 4;
	int m = 3;
	int** matrix = new int* [n];
	int** rows =new int* [n];
	for (int i = 0; i < n; i++)
		rows[i] = new int[2];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
	}
	ifstream fin{ "matrix.txt" };
	
	readMatrix(fin, matrix, n, m);
	
	for (int i = 0; i < n; i++) {
		summ = 0;
		for (int j = 0; j < m; j++) {
			summ += matrix[i][j];
			
		}
		cout << summ << endl;
		flag = isTrue(summ);
		if (flag) {
			rows[i][0] = summ;
			rows[i][1] = i;
		}
		else {
			rows[i][0] = 0;
			rows[i][1] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cout << rows[i][j] << " ";
		}
		cout << endl;
	}
	// sort
	int k = 0;
	for (int i = 0; i < n - k; i++) {
		for ( k = 0; k < n; k++)
			//k - номер текущей строки
		{
			if (rows[i][0] < rows[i - 1][0])
			{
				int tmp = rows[i][0];
				rows[i][0] = rows[i - 1][0];
				rows[i - 1][0] = tmp;
			}


		}
	}
	
	for (int i = 0; i < n; i++) {
		if (rows[i][0] != 0)
			cout << rows[i][1] << ' ';
	}
}