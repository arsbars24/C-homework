#include "node.h"
Ptr InitBox(int i) {
	Ptr Root = new Box;
	Root->link = nullptr;
	Root->num = i;
	return Root;
}