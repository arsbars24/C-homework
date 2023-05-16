#include <iostream>
using namespace std;

int main() {
	int num, new_num, ten;
	num = 7;
	new_num = 0;
	ten = 1;
	while (num != 0) {
		if (num & 1) { //true if last is 1
			new_num = (1 * ten) + new_num;
		}
		ten *= 10;
		num = num >> 1;
		
	}
	cout << new_num;
}