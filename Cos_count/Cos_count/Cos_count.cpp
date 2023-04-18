#include <Cmath>
#include <iostream>
using namespace std;

double myCos(double x, double eps) {
	double sum = 1;
	double a = x;
	int next = 2;
	double x2 = x * x;
	while (abs(a) > eps) {
		a = a * x2 * (-1) / next / (next - 1);
		next = next + 2;
		sum += a;

	}
	return sum;
}
int main() {

	double x = 3.141592654 / 2;
	double eps = 0.0000001;
	double s = cos(x);
	cout << myCos(x, eps) << endl;
	cout << s;
}