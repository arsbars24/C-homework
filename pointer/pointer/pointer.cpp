#include <iostream>
using namespace std;

int* ReadArray(int);

int main() {
	int* a;
	int n;
	cin >> n;
	a = ReadArray(n);
	
	return 0;
}

int* ReadArray(int n) {
	int* a = new int[n];

	return a;
}
// указатель это адресс  *
// ссылка разименовывается автоматичести &