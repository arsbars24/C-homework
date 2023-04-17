#include <iostream>
using namespace std;

int main() {
	int n, shift;
	cin >> n >> shift;
	int* num = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cout << "array" << endl;
	for (int i = 0; i < n; i++)
		cout << num[i] << ' ';

	for (int i = shift; i < shift + 10; i++)
		cout << num[(i) % n] << ' ';
	return 0;
}