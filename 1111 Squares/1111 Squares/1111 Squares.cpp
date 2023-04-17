#include <iostream>
#include <cmath>
using namespace std;

struct Point {
	double x;
	double y;
	Point(double a, double b) {
		x = a; y = b;
	}
	Point() {};
	double D(Point a) { return sqrt((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y)); }
	double ScalarProduct(Point u) {
		return x * u.x + y * u.y;
	}
};
struct Line {
	double A;
	double B;
	double C;
	Line() {};
	Line(Point a, Point b) {
		A = b.y - a.y;
		B = a.x - b.x;
		C = -A * a.x - B * a.y;
	}
	double Dist(Point a) {
		return abs(A * a.x + B * a.y + C) / sqrt(A * A + B * B);
	}
	bool Left(Point a) {

	}
};