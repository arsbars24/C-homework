#include <iostream>
using namespace std;

int search(targ, str) {
	int targ_length = targ.length(), str_length = str.length();
	for (int i = 0; i < targ_length - str_length + 1; i++) {
		bool bflag = true;
		for (int j = 0; j < str.length; j++) {
			if (targ[i] != str[i]) {
				bflag = false;
				break;
			}
			if (bflag)
				return i;
		}
	}
} return -1;

int main() {

}