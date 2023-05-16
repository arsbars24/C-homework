//#include <iostream>
//using namespace std;
//
//int* Factorize(int x, int& outCount)
//{
//	int* pArray = new int [sqrt(x) + 1] {0};
//	int k = 0;
//	for (int i = 2; i < sqrt(x); ++i) {
//		if (IsPrime(i))
//	}
//	outCount = k;
//	return pArray
//}
//
//
//
//int main() {
//	cout << (IsPrime(x) ? "Is prime"
// }
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int** a = new int* [n] {0};
	for (int i = 0; i < n; i++) {
		int* a = new int [n];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << ' ';
		}
	}
	return 0;
}