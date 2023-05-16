#include "node.h"
void AddBox(Ptr el, Ptr& root) {
	el->link = root;
	root = el;
}