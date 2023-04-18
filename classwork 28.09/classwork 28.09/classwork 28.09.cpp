#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int pointA, pointB, pointC, pointD;
	cin >> pointA >> pointB >> pointC >> pointD;
	int lengthAB, lengthCD, length;

	if (pointA <= pointB) {
		lengthAB = pointB - pointA;
	}
	else {
		lengthAB = pointA - pointB;
	}

	if (pointC <= pointD) {
		lengthCD = pointD - pointC;
	}
	else {
		lengthCD = pointC - pointD;
	}

	if (max(pointA, pointB) < min(pointC, pointD)){
		return -1;
	}
		
	if (max(pointA, pointB) > min(pointC, pointD)) {
		length = max(pointA, pointB) - min(pointC, pointD);
		return length;
	}

	if (pointB == pointC) {
		return 0;
	}

}
// Max(A,C) < Min(B,D)