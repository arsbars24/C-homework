#pragma once
#include <iostream>
using namespace std;

class Geometry{
public:
	class Point {
	public:
		char name;
		double x, y;
		p() {}
		p(double _x, double _y, char n) { x = _x, y = _y, name = n; }

	};
	class l {
	private:
		double A, B, C;
	public:
		char name;
		l() {}
		l(double _x, double _y, char n) { x = _x, y = _y, name = n; }
	};
	class v {
	private:
		double x, double y;
	public:
		char name;
		v() {}
		v(double _x, double _y, char n) { x = _x, y = _y, name = n; }
		double len(r a) { return sqrt(a.x * a.x + a.y * a.y); }
		v operator+(r a, r b) { return r(a.x + b.x, a.y + b.y); }
		v operator-(r a, r b) { return r(a.x - b.x, a.y - b.y); }
		double operator*(r a, r b) { return a.x * b.x + a.y * b.y; }
		v operator*(r a, r b) { return a.x * b.x + a.y * b.y; }
		v operator^(r a, r b) { return a.x * b.y - b.x * a.y; }
	};
	
}