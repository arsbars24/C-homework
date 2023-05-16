#include <iostream>
#include "node.h"
using namespace std;

int main() {
	int n = 10;
	int k = 3;
	int r;
	Ptr Root = nullptr;
	for (int i = 0; i < n; i++) {
		cin >> r;
		AddBox(InitBox(r), Root);
	}
	PrintList(Root);
	//SortBox(Root, n);
	//cout << endl;
	//cout << "-------------------------" << endl;
	Pop(Root);
	PrintList(Root);
	DeleteBox(k, Root);
	PrintList(Root);
	return 0;
}