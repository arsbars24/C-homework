#include "node.h"

void SortBox(Ptr Root, int n) {
	int c = 0;
	Ptr temp = Root;
	Ptr fnode = Root;
	Ptr snode = Root->link;  //first and second nodes
	while (c != n * n) {                 //
		if (fnode->num > snode->num) {
			temp->link= snode->link;
			snode->link = fnode->link;
			fnode->link = temp->link;
		}
		fnode = fnode->link;
		snode = snode->link;
		c++;
	}
}
