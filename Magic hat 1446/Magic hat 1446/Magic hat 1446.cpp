#include <iostream>
#include <string>
using namespace std;

int main() {
	int k; 
	cin >> k;
	int n = k * 2 + 1;
	string* input = new string[n]();
	string* sl = new string[n]();
	string* huf = new string[n]();
	string* gr = new string[n]();
	string* rav = new string[n]();
	for (int i = 0; i < n; i++) {
		getline(cin, input[i]);
		if (input[i] == "Slytherin") sl[i] = input[i - 1];
		if (input[i] == "Hufflepuff") huf[i] = input[i - 1];
		if (input[i] == "Gryffindor") gr[i] = input[i - 1];
		if (input[i] == "Ravenclaw") rav[i] = input[i - 1];
		//вывод строкового массива без мусора
	}
	cout << "Slytherin:" << endl;
	for (int i = 0; i < n; i++) {
		if (sl[i].empty()) continue;
		cout << sl[i] << endl;
		
	}

	cout << endl;

	cout << "Hufflepuff:" << endl;
	for (int i = 0; i < n; i++) {
		if (huf[i].empty()) continue;
		cout << huf[i] << endl;

	}

	cout << endl;

	cout << "Gryffindor:" << endl;
	for (int i = 0; i < n; i++) {
		if (gr[i].empty()) continue;
		cout << gr[i] << endl;

	}

	cout << endl;

	cout << "Ravenclaw:" << endl;
	for (int i = 0; i < n; i++) {
		if (rav[i].empty()) continue;
		cout << rav[i] << endl;

	}

	cout << endl;
	return 0;
}