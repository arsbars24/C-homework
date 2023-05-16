#include <iostream>
using namespace std;

int Alg(int n) {
	int* arr = new int[1000];
	for (int i = 1; i < round(sqrt(n)) + 1; i++) {

	}
	return 
}

int main() {
	int x, n;
	cin >> n;
	int x = -1;
	int mx_d = 0;
	int vr = 0;

	for (int i = 1; i <= n; i++) {
		vr = Alg(i);
		if (vr > mx_d)
			mx_d = vr; x = i;
	}
	cout << x << endl;
	cout << mx_d;
	return 0;
}