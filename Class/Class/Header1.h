#pragma once
#include <iostream>
using namespace std;

class Stack
{
    Node* arr;
    int top;
    int capacity;

public:
    Stack(int size);         // �����������
    ~Stack();                       // ����������

    void push(int);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();
};
struct Node {
    int num;
    typedef Node* ptr;
    ptr prev;             // ���������� �������
    ptr next;             // ��������� �������

    ptr InitBox(int i) {
        ptr Root = new Node;
        Root->next = nullptr;
        Root->prev = nullptr;
        Root->num = i;
        return Root;
    }
    void Add(ptr el, ptr& root) {
        el->next = root;
        el->prev = root;
        root = el;
    }
}; 
Node* max;
Node* root;
// ����������� ��� ������������� stack
Stack::Stack(int size)
{
    Node* arr = new Node[size];
    capacity = size;
    top = -1;
}

// ���������� ��� ������������ ������, ���������� ��� stack
Stack::~Stack() {
    delete[] arr;
}

// ��������������� ������� ��� ���������� �������� `x` � stack
void Stack::push(int x)
{
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << x << endl;
    arr[++top] = root;
}

// ��������������� ������� ��� ���������� �������� �������� �� stack
int Stack::pop()
{
    // �������� �� ����������� stack
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << peek() << endl;

    // ��������� ������ stack �� 1 � (�������������) ���������� ����������� �������
    return &arr[top--];
}

// ��������������� ������� ��� �������� �������� �������� stack
int Stack::peek()
{
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}

// ��������������� ������� ��� �������� ������� stack
int Stack::size() {
    return top + 1;
}

// ��������������� ������� ��� ��������, ���� stack ��� ���
bool Stack::isEmpty() {
    return top == -1;               // ��� return size() == 0;
}

// ��������������� ������� ��� ��������, �������� �� stack ��� ���
bool Stack::isFull() {
    return top == capacity - 1;     // ��� return size() == capacity;
}

