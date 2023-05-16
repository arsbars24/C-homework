#include "node.h"

void DeleteBox(int k, Ptr& Root) {
	Ptr cur, pr;
	cur = pr = Root;
	if (k == cur->num) {
		Root = Root->link;
	}
	else {
		cur = Root->link;
		while (cur!=nullptr) {
			if (k == cur->num) {
				pr->link = cur->link;
				break;
			}
			else {
				pr = cur;
				cur = cur->link;
			}
		}

	}
	delete cur;
}
void Pop(Ptr) {
	Ptr Root;
	
	Ptr temp = Root->link;
	delete Root;
	Root = temp;
}