#include "node.h"

void PrintList(Ptr Root) {
	while (Root != nullptr) {
		std::cout << Root->num << ' ';
		Root = Root->link;

	}
	std::cout << std::endl;
}