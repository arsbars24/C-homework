#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	double a, b, k;
	int n;
	cin >> a >> b >> n;
	k = (a * a * b * M_PI)/ 8;
	double* Y = new double[n + 1];
	
	for (int i = 0; i < n + 1; i++) {
		double k = -n;
		Y[i] = (k + (2 * i) )/ n;
		
	}
	for (int i = 1; i < n + 1; i++) {
		double res;
		res = k * ((Y[i] * (1 - Y[i] * Y[i] / 3)) - (Y[i -1] * (1 - Y[i - 1] * Y[i - 1] / 3)));
		cout << fixed<< setprecision(12);
		cout << res << '\n';
	}
	return 0;
} 
// int64