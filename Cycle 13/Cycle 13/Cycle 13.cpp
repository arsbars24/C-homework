#include <iostream>
#include <Cmath> 
using namespace std;

int main() {
	int N;
	cin >> N;
	if (N == 1) {
		cout << "There is no necessity to change number";
	}
	else if (N == 0) {
		cout << "Unacceptable number";
	}
	else {
		int i = 1;
		while (i * i <= N) {
			++i;
			--N;
		}
		cout << i * i << endl;
		N = i * i;
		cout << N;
	}
	return 0;
}