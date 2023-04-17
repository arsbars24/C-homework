#define _USE_MATH_DEFINES
#include <iostream>
#include <Cmath>
#include <iomanip>
using namespace std;

int main() {
	double H, W;
	double x, y;
	double r, PI;
	double VP, VC;
	PI = M_PI;
	cin >> H >> W;
	cin >> x >> y;
	cin >> r;
	x = abs(x);
	y = abs(y);
	if (y > x)
		y = x;
	VP = W * W * H / 3;
	VC = PI * r * r * H * ((W / 2) - x) / (W / 2);
	cout << setprecision(6) << VP - VC;
}