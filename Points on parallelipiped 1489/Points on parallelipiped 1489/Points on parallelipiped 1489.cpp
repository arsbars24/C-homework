#include <iostream>
#include <Cmath>
using namespace std;

double findPlace(int A, int B, int C, double x, double y) {
	int Case;
	double X, Y, Z;
	if (C <= x <= C + A && y <= B) {
		Case = 1;
	}
	else if (C <= x <= C + A && B <= y <= B + C) {
		Case = 2;
	}
	else if (C + A <= x <= (2 * C) + A && B + C <= y <= (2 * B) + C) {
		Case = 3;
	}
	else if (C <= x <= C + A && B + C + B <= y <= 2 * (B + C)) {
		Case = 4;
	}
	else if (x <= C && B + C <= y <= (2 * B) + C) {
		Case = 5;
	}
	else if (C <= x <= C + A && B + C <= y <= (2 * B) + C) {
		Case = 6;
	}
	else {
		Case = 7;
	}
	switch (Case){
	case 1:
		X = x - C;
		Y = y;
		Z = C;
	case 2:
		X = x - C;
		Y = y - B;
		Z = C + B - y;
	case 3:
		X = x - A - C;
		Y = y - C - B;
		Z = 2 * C + A - x;
	case 4:
		X = x - C;
		Y = y - B - C - C; 
		Z = 2 * (B + C) - y;
	case 5:
		X = x;
		Y = y - C - B;
		Z = C - x;
	case 6:
		X = x - C;
		Y = y - C - B;
		Z = 0;
	case 7:
		cout << "Out of field";
	}

	// make obj with par XYZ
	return X, Y, Z; //return obj
}

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double X1, Y1, Z1;


}