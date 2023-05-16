#include <iostream>
#include <string> 
#include <fstream>
using namespace std;


int main()
{
	string s1, s2;
	char c1, c2;
	string in = "Input.txt";
	//string out = "Output.txt";
	fstream fs;
	fs.open(in, fstream::in | fstream::out | fstream::app); //fstream::out;
	if (!fs.is_open()) {
		cout << "It`s not!" << endl;
	}
	else {
		cout << "It`s open" << endl;
	}
	getline(fs, s1);
	getline(fs, s2);
	cout << s1 << endl << s2;
	for (int i = s1.length(); i > 0; i--) {
		int k, l, ost;
		ost = 0;
		c1 = s1[i];
		for (int j = s2.length(); j > 0; j--) {
			c2 = s2[i];
			k = atoi(&c1);
			l = atoi(&c2);
			if (k + l + ost < 10) {
				s1[i] = itoa(k + l + ost, string, 10);
			}
			else {
				s1[i] = (k + l) % 10;
				ost = 1;
			}
		}
	}
	fs << "\n" << s1;
	fs.close();
	cout << s1;
}