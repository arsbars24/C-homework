#include <iostream>
using namespace std;

int main() {
	int n, weight, opt, ind, summ;
	
	weight = 0;
	cin >> n;
	int* weightArray = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> weightArray[i];
		weight += weightArray[i];
	}
	opt = weight;
	for (int i = 0; i < (1 << n) - 1; ++i) {
		int temp = i;
		ind = 0;
		summ = 0;
		while (temp) {
			if (temp & 1) {
				summ += weightArray[ind];
			}
			++ind;
		}
		if (abs(summ + summ - weight) < opt) {
			opt = abs(summ + summ - weight);
		}
	}
	cout << opt;
}