#include <iostream>
using namespace std;

int main() {
	long long  n;
	cin >> n;
	long long summ = 0;
	summ = (n * (n + 1) / 2) * (n + 2);
	
	cout << summ;
	return 0;
}