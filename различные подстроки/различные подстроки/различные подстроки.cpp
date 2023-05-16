#include <iostream>
using namespace std;

int f_c(string S) {
	int n = S.length();
	int res = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++){
			bool bflag = true;
			for (int k = j + 1; k < n - i; k++) {
				if (S.substr(j, i) == S.substr(k, i)) {
					bflag = false;
					break;
				}

			}
			if (bflag) res++;
		}
	}
	return res;
}