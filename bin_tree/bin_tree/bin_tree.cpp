//#include <iostream>;
//using namespace std;
//
//int Isempty();
//void Create(int item);
//void Out();
//
//struct Node {
//	int num;
//	Node* left;
//	Node* right;
//    Node* root;
//
//};
//
//
//// &lt скобочка в лево <
//// &gt скобочка в право >
//int main() {
//	int n;
//	cin >> n;
//	int* a = new int(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//
//	return 0;
//}
//
//void Create(int item) {
//    Node* p = new Node;
//    Node* parent;
//    p->num = item;
//    p->left = NULL;
//    p->right = NULL;
//    parent = NULL;
//    if (Isempty())
//        root = p;
//    else {
//        Node* ptr;
//        ptr = root;
//        while (ptr != NULL) {
//            parent = ptr;
//            if (item>ptr->num)
//                ptr = ptr->right;
//            else
//                ptr = ptr->left;
//        }
//        if (item <parent->num)
//            parent->left = p;
//        else
//            parent->right = p;
//    }
//}
// надо сделать функцию заполнения\создания дерева, функцию отображения

#include<iostream>
#include<cstdio>

using namespace std;

const int N = 3005;
int a[N];
void dfs(int l, int r)
{
    if (l > r)
        return;
    int i;
    for (i = l; i < r; i++)
        if (a[i] > a[r])
            break;
    dfs(i, r - 1);
    dfs(l, i - 1);
    cout << a[r] << endl;
}

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            scanf_s("%d", &a[i]);
        dfs(0, n - 1);
    }
    return 0;
}