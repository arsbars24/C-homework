#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	string Input = "input.txt";
	string Integ = "int.txt";
	string Doubl = "double.txt";

	int n;
	cin >> n;
	string* buff = new string[n];
	string* forint = new string[n];
	string* fordoubl = new string[n];

	ifstream fin{ Input };
	ofstream fint{ Integ };
	ofstream fdoub{ Doubl }; 
	if (!fin && !fint && !fdoub) {
		cout << "Files opened incorrectly";
	}
	for (int i = 0; i < n; i++) {
		fin >> buff[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < buff[i].length(); j++) {
			if (buff[i].find('.') != buff[i].npos) {
				fordoubl[i] = buff[i];
			}
			else {
				forint[i] = buff[i];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		fint << forint[i] << " ";
	}
	for (int i = 0; i < n; i++) {
		fdoub << fordoubl[i] << " ";
	}
	fin.close();
	fint.close();
	fdoub.close();
	cout << "Check files";
}