#include <iostream>
using namespace std;

struct Node {
	int num;
	Node* left; Node* right;
	
	void print_tree(Node* root) {
		if (root != NULL) {
			print_tree(root->left);
			cout << root->num;
			print_tree(root->right);
		}
	}
};
void add_num(int n, Node* root) {
	if (root == NULL) {
		root->left = NULL;
		root->right = NULL;
		root->num = n;
	}
	else if (root->num < n) {
		add_num(n, root->right);
	}
	else {
		add_num(n, root->left);
	}
}

int main()
{
	int m[] = { 1, 8, 9, -9 - 31, 0, 7, 3 };
	Node* tree = NULL; // размер равен размеру адресной строки так как это указатель
	for (int i = 0; i < sizeof(m) / sizeof(int); i++) {
		m[i].add_num(m, tree)
	}


}

