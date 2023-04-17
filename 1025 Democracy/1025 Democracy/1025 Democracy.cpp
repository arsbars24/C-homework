#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* a = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1]) {
				int b = a[j]; // создали дополнительную переменную
				a[j] = a[j + 1]; // меняем местами
				a[j + 1] = b; // значения элементов
			}
		}
	}
	int k = (n / 2) + 1;
	int sum = 0;
	for (int i = 0; i < k; i++) {
		sum += (a[i] / 2) + 1;
	}
	cout << sum;
	return 0;
}