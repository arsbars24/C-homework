#include <iostream>
#include <vector>
#include <bitset>
#include <cstdio>

using namespace std;
vector<int> a;

struct node {
    int num;
    struct node* parent, * left, * right;
};
vector<node> b(3001);

void find(node* root, int l, int r, int& s) {
    if (l > r)return;
    if (l == r) {
        if (root->num > a[l])
            root->left = NULL, root->right = &b[s];
        else root->left = &b[s], root->right = NULL;
        b[s].parent = root;
        b[s].left = b[s].right = NULL;
        b[s].num = a[l];
        s++;
        return;
    }
    int i = l;
    for (; i <= r; i++)
        if (a[i] > root->num)
            break;
    if (i == l) {
        root->left = NULL;
        root->right = &b[s];
        b[s].parent = root;
        b[s].num = a[r];
        s++;
        find(&b[s - 1], l, r - 1, s);
    }
    else if (i > r) {
        root->right = NULL;
        root->left = &b[s];
        b[s].parent = root;
        b[s].num = a[r];
        s++;
        find(&b[s - 1], l, r - 1, s);
    }
    else {
        i--;
        b[s].num = a[i];
        b[s].parent = root;
        root->left = &b[s];
        s++;
        find(&b[s - 1], l, i - 1, s);
        b[s].num = a[r];
        b[s].parent = root;
        root->right = &b[s];
        s++;
        find(&b[s - 1], i + 1, r - 1, s);
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    node* root = new node();
    root->num = a[n - 1];
    int k = 0;
    find(root, 0, n - 2, k);
    for (int i = k - 1; i >= 0; i--)
        cout << b[i].num << endl;
    cout << root->num << endl;
}