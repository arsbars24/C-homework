#include <iostream>
#include <vector>

struct Pix {
	int x, y;
	int* neighbours[4]; // ������ ������ �� ������� 
	Pix(int a, int b) {
		this->x = a;
		this->y = b;
	}
};
int main() {
	int n, _x, _y;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> _x;
		std::cin >> _y;
		Pix(_x, _y);
		// ��������� ��� ������� �������

	}
	return 0;
}