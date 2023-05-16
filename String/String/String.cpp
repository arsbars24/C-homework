#include <iostream>
#include <string>
using namespace std;


int main() {
	int num, k;
	string sc;
	string s1, s2;
	cin >> s1;
	cin >> s2;
	/*for (int i = 0; i < S1.length(); i++) {
		cout << S1[i] << endl;
	}*/
	for (int i = 0; i <= s1.length() - s2.length(); ++i) {
		if (s1.substr(i, s2.length()) == s2){
			sc = s1.substr(i, s2.length());
			return 1;
		}
	}
	cout << "work" << ' ' << sc;
	return 0;
}