#pragma once
#include <iostream>
using namespace std;

class stack {
public:
	char name;
	stack() {};
	~stack() {};
	struct Node {
		int num;
		Node* next;
		Node* prev;
	};
	Node* Init(int n) {
		Node* anot = new Node;
		anot->num = n;
		anot->prev = nullptr;
		anot->next = nullptr;
		return anot;
	};
	void Add(Node* el, Node* root) {
		el->next = root;
		el->prev = root;
		root = el;
	};
	Node* root = Init(0);
	void pop() {
		root = root->prev;
		findMax(root);
	};
	void push(int n) {
		Add(Init(n), root);
		findMax(root);
	};
	int findMax(Node* root)
	{
		int max = root->num;
		for (Node* node = root; node != nullptr; node = node->prev)
		{
			if (node->num > max)
				max = node->num;
		}
		return max;
	};
	stack(char a) {
		name = a;
		stack name;
	}
};