#include <iostream>
using namespace std;

void pointsInArray(int**, int*);
void hitCalculation(int**);

int main() {
	int n;
	cin >> n;
	int* A = new int[1000];
	pointsInArray(&A, &n);
	hitCalculation(&A);

}

void pointsInArray(int** A, int* n) {
	while (n > 0) {
		int j, i;
		cin >> j >> i;
		A[i][j] = 1;
		--n;
	}
}

void hitCalculation(int** A) {
	int point; 
	for (int i = 0; i < 1000; ++i) {
		for (int j = 0; j < 1000; ++j) {
			if (A[i][j] = 1) {

			}
		}
	}
}