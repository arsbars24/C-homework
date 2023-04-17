#include <iostream>
#include <Cmath>
#include <iomanip>
using namespace std;

int main() {
	int V, A;
	double K, S1, S2, sin2A, sinA, eps, PI, B, V2;
	cin >> V >> A >> K;
	int g = 10;
	eps = 0.000001;
	PI = 3.1415926535;
	B = (PI / 180) * A;
	V2 = V * V;
	sinA = sin(B);
	sin2A = 2 * sin(B) * cos(B);
	S1 = V2 * sin2A / 10;
	S2 = V2 * sin2A / 10;

	
	while (S2 > eps) {
		S2 /= K;
		S1 += S2;
	}
	if (A == 90) {
		S1 = V2 * sinA / 2 * g;
		S2 = V2 * sinA / 2 * g;
		while (S2 > eps) {
			S2 /= K;
			S1 += S2;
		}
	}
	if (A == 0) {
		S1 = 0;
	}
	cout << setprecision(3);
	cout << S1;
	return 0;
}