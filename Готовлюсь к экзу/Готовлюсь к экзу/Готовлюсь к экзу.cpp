#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
	double a, b;
	float e = numeric_limits<float>::epsilon();
	a = 100 - 99.9;
	b = 10 - 9.9;
	cout << setprecision(9);
	cout << a << ' ' << b << '\n';
	a == b ? cout << "True" : cout << "False";
	cout << "\n";
	cout << e << '\n';
	fabs(a - b) < e ? cout << "True" : cout << "False";
	cout << "\n";
	cout << abs(-2.545674);

}