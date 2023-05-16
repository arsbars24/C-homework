#include "Node.h"

Node* InitNode(std::string s) {
	Node* ptr = new Node;
	ptr->next = nullptr;
	ptr->fio = s;
	return ptr;
}
void CreateNode(std:: ifstream& fi, Node*& root) {
	while (!fi.eof()) {
		Node* cur = new Node;
		fi >> cur->fio;
		cur->next = root;
		root =
	}
}
void Print(Node* root) {
	
}