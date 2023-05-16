#include <Cmath>
#include <iostream>
using namespace std;

double mySin(double x, double eps) {
	double sum = x;
	double an = x;
	int next = 3;
	double x2 = x * x;
	while (abs(an) > eps) {
		an = an * x2 * (-1) / next / (next - 1);
		next = next + 2;
		sum += an;

	}
	return sum;
}
int main() {
	
	double x = 3.141592654 / 6;
	double eps = 0.000001;
	double s = sin(x);
	cout << mySin(x, eps) << endl;
	cout << s;
}