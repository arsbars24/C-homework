#include <iostream>
#include <fstream>

struct Node {
	int num;
	Node* links[5];
	
};
Node* InitNode(int i) {
	using namespace std;
	Node* another = new Node;
	another->num = i+1;
	cout << another << ' ' << another->num << endl;
	return another;
}

int main() {
	int n = 5;
	using namespace std;
	Node* arr = new Node[n];
	for (int i = 0; i < 5; i++){
		InitNode(i);
	}
	
	ifstream file;
	file.open("matrix.txt");
	while (!file.eof()) {
		char var;
		Node temp, temp2; int i = 0; int k = 0;
		temp = arr[k];
		temp2 = arr[k];
		file >> var;
		if (var == '1') {
			temp.links[i] = &temp2;
			i++;
		}
		if (var == '0') {
			i++;
		}
		if (var == '\n')
			k++;
	}

	Node res = arr[0];
	for (int i = 0; i < n; i++)
		cout << res.links[i] << endl;
	return 0;
}