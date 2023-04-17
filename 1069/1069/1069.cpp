#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> >qt;
const int N = 10005;
int a[N];
int num[N];
vector<int>tree[N];
int main()
{
    int n = 1;
    memset(num, 0, sizeof(num));
    while (cin >> a[n])
    {
        ++num[a[n]];
        ++n;
    }
    for (int i = 1; i <= n; ++i)
        tree[i].clear();
    for (int i = 1; i <= n; ++i)
        if (num[i] == 0)
            qt.push(i);
    for (int i = 1; i < n; ++i)
    {
        int k = qt.top(); qt.pop();
        tree[a[i]].push_back(k);
        tree[k].push_back(a[i]);
        --num[a[i]];
        if (num[a[i]] == 0)
            qt.push(a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << i << ":";
        sort(tree[i].begin(), tree[i].end());
        for (unsigned int j = 0; j < tree[i].size(); ++j)
        {
            cout << " " << tree[i][j];
        }
        cout << endl;
    }
    return 0;
}