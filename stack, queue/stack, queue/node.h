//make nodes for stack 
#pragma once
#include <iostream>
//#ifindef Node_h
//#define Node_h
//endif
typedef struct Node {
	int num;
	Node* link;
} Box;
typedef Box* Ptr;

Ptr InitBox(int);
void AddBox(Ptr, Ptr&);
void PrintList(Ptr);
void DeleteBox(int, Ptr&);
void SortBox(Ptr, int);
void Pop(Ptr);
