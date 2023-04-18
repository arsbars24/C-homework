#include "n.h"

int main() {
	Otrezok ab; double m; double f;
	ab.IN();
	cout << "point:";
	cin >> m;
	cin >> f;
	cout << ab.OnLine(m, f);

}