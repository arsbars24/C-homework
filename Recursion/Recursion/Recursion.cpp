#include <iostream>
using namespace std;
//рекурсия постоянно обращается к стеку ===> стек растёт 
//
int main() {
	
 }

/*****************************************************/
//факториал рекурсией
int fact(int n) {
	if (n == 0 || n == 1)
		return 1;
	return n * fact(n - 1);

 }

/******************************/
int fib(int n) {
	if ((n == 1) || (n == 2)) {
		return 1;
	}
		
	return fib(n - 1) + fib(n - 2);
}

// определитель считаем
int det(int** a, int n) {
	if (n == 2)
		return (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);
	int sum = 0;
	int k = 1;
	for (int i = 0; i < n; i++) {
		int** b = new int* [n - 1];
		for (int j = 0; j < n - 1; j++) {
			b[j] = new int[n - 1];
			for (int m = 0; m < i; m++) {
				b[j][m] = a [j + 1][m];
			}
			for (int m = i + 1; m < n - 1; m++) {
				b[j][m] = a[j + 1][m + 1];
			}
		}
		sum += k * a[0][i] * det(b, n - 1);
		k = - k;
	}
	return sum; // delete []b;
}