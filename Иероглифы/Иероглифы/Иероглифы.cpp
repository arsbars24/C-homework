#include <iostream>
#include <string>
using namespace std;

int main() {
	string t;
	char x;
	int n;
	cin >> n;
	string* a = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> x;
	for (int i = 0; i < n; i++) {
		if (a[i][0] == x) {
			cout << a[i] << endl;
		}
	}
	return 0;
}