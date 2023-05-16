#include <iostream>
#include <fstream>
using namespace std;

struct point {
	double x;
	double y;
	double z;
	point() {};
	point(double a, double b, double c) {
		x = a; y = b; z = c;
	}
};
struct flatness {
	double A;
	double B;
	double C;
	double D;
	flatness() {};
	flatness(double a, double b, double c, double d) {
		A = a; B = b; C = c; D = d;
	}
	point normal = point(A, B, C);
	double length(point a, flatness b) {
		return abs(b.A * a.x + b.B * a.y + b.C * a.z + b.D) / sqrt(b.A * b.A + b.B * b.B + b.C * b.C);
	}



};

int main() {
	fstream fin("input.txt");
	int n;
	fin >> n;
	flatness* fromFile = new flatness[n];
	for (int i = 0; i < n; i++);
		//fin >> fromFile[i]
}
// windows.h структуры посмотреть