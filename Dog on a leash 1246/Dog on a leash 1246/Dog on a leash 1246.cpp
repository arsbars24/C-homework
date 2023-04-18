#include <iostream>
using namespace std;

int main() {
	int n;
	double s = 0;
	double sx = 0;
	double sy = 0;
	cin >> n;
	int** a = new int*[n];
	for (int i = 0; i < n; i++) { 
		a[i] = new int[2];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> a[i][j];
		}
		cout << endl;
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cout << a[i][j];
		}
	}*/
	int counter = 0;
	while (counter <= n) {
		for (int i = 0; i < n - 1; i++) {
			sx = a[i][1] + a[i + 1][1];
		}
		for (int i = 0; i < n - 1; i++) {
			sy = a[i][2] + a[i + 1][2];
		}
		s += sx * sy;
		counter++;
	}
	if (s > 0)
		cout << "ccw";
	else {
		cout << "cw";
	}
}