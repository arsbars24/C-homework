#include <iostream>
using namespace std;

class Point {
public:
	int x, y;
	Point() : x(0), y(0) {} 
	Point(int _x, int _y) {
		this->x = _x;
		this->y = _y;
	};
};

class Vector {
public:
	Point A;
	Vector() {};
	Vector(Point _A) {
		A = _A;
	};
	
	double Length() {
		return sqrt(A.x * A.x + A.y * A.y);
	};
	void Sum(const Vector VB) {
		this->A.x += VB.A.x;
		this->A.y += VB.A.y;
	};
	void Minus(const Vector VB) {
		this->A.x -= VB.A.x;
		this->A.y -= VB.A.y;
	};
};

class Line {
public:
	Vector A, B;
	Line() {};
	Line(Vector _A, Vector _B) {
		A = _A;
		B = _B;
	};
	double Length() {
		A.Minus(B);
		return A.Length();
	}
	bool IsOnLine(Point _A) {
		return ((_A.x - A.A.x) / (B.A.x - A.A.x) == (_A.y - A.A.y) / (B.A.y - A.A.y));
	};
};

int main() {
	Point A(1, 1);
	Vector V(A);
	Point B(3, 9);
	Vector V2(B);
	Line S(V, V2);
	Point C(3, 5);
	cout << S.Length() << endl;
	cout << S.IsOnLine(C);
	cout << '#';
	
	return 0;
}