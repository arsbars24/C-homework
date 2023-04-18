#include <iostream>

typedef struct Box {
	int num;
	Box* mlink;   //main link
	Box* alink;   // adverse link
} Node;
typedef Node* Ptr;

Ptr InitBox(int i) {
	Ptr part = new Box;
	part->num = i;
	part->alink = nullptr;
	part->mlink = nullptr;
	return part;
}

void AddBox(Ptr el, Ptr& root, int a) {
	if (a == 1) {
		el->alink = root;
		root = el;
	}
	if (a == 2) {
		el->mlink = root;
		root = el;
	}
}
void PrintList(Ptr Root) {
	while (Root != nullptr) {
		while (Root != nullptr) {
			std::cout << Root->num << ' ';
			Root = Root->alink;
		}
		std::cout << '\n' << Root->num << ' ';
		Root = Root->mlink;

	}
	std::cout << std::endl;
}

int main() {
	using namespace std;
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	Ptr root = nullptr;
	for (int i = 0; i < n; i++) {
		AddBox(InitBox(i), root, 1);
		AddBox(InitBox(arr[i]), root, 2);
	}

	return 0; 
}