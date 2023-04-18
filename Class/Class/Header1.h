#pragma once
#include <iostream>
using namespace std;

class Stack
{
    Node* arr;
    int top;
    int capacity;

public:
    Stack(int size);         // конструктор
    ~Stack();                       // деструктор

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
    ptr prev;             // предыдуший элемент
    ptr next;             // следующий элемент

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
// Конструктор для инициализации stack
Stack::Stack(int size)
{
    Node* arr = new Node[size];
    capacity = size;
    top = -1;
}

// Деструктор для освобождения памяти, выделенной для stack
Stack::~Stack() {
    delete[] arr;
}

// Вспомогательная функция для добавления элемента `x` в stack
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

// Вспомогательная функция для извлечения верхнего элемента из stack
int Stack::pop()
{
    // проверка на опустошение stack
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << peek() << endl;

    // уменьшаем размер stack на 1 и (необязательно) возвращаем извлеченный элемент
    return &arr[top--];
}

// Вспомогательная функция для возврата верхнего элемента stack
int Stack::peek()
{
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}

// Вспомогательная функция для возврата размера stack
int Stack::size() {
    return top + 1;
}

// Вспомогательная функция для проверки, пуст stack или нет
bool Stack::isEmpty() {
    return top == -1;               // или return size() == 0;
}

// Вспомогательная функция для проверки, заполнен ли stack или нет
bool Stack::isFull() {
    return top == capacity - 1;     // или return size() == capacity;
}

