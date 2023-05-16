#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node {
	std:: string fio;
	Node* next;
};
CreateNode(ifstream&, Node*&);
Print(Node*);