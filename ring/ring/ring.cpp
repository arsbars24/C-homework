#include "Node.h"
#include <fstream>

int main() {
	ifstream fi ("surnames.txt");
	Node* root = nullptr;
	CreateNode(&fi, &root);
	Print(root);

	return 0;
}