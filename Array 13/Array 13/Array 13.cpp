#include <iostream>
using namespace std;

void lengthCalc(int**&, int&, double&);

int main() {
	int n, R;
	double num = 0;
	double PI = 3.14159;
	cin >> n >> R;
	auto a = new int[n][2];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; j++) {
			cin >> a[i][j];
		}
	}
	num += 2 * PI * R * R;
	cout <<endl << num;
	return 0;
}

void lengthCalc(int**& a, int& n, double& num) {
	double vector, lvector;
	for (int i = 0; i < n; ++i) {
		vector = sqrt((a[i + 1][1] - a[i][1]) * (a[i + 1][1] - a[i][1]) - (a[i + 1][2] - a[i][2]) * (a[i + 1][2] - a[i][2]));
		num += vector;	
	}
	lvector = sqrt((a[n][1] - a[1][1]) * (a[n][1] - a[n][1]) - (a[n][2] - a[n][2]) * (a[n][2] - a[n][2]));
	num += lvector;
}