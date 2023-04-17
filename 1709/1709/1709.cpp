#include <iostream>
#include <vector>
#include <bitset>
// #include <algorithm>
// #include <stack>
using namespace std;
vector<vector<int> > a(101, vector<int>(101));
vector<vector<char> >  b(101, vector<char>(101, '0'));
int n, d, aa;
long long int cost = 0;
bitset<101> vis;
void dfs(int u, int p) {
    vis[u] = 1;
    for (int i = 1; i <= n; i++)
        if (a[u][i]) {
            if (!vis[i])
                dfs(i, u);
            else if (i > u && i != p)
            {
                b[u][i] = b[i][u] = 'd';
                a[u][i] = a[i][u] = 0;
                cost += d;
            }
        }
}
int main() {
    cin >> n >> d >> aa;
    for (int i = 1; i <= n; i++) {
        ws(cin);
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    dfs(1, 1);
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, i);
            cost += aa;
            b[1][i] = b[i][1] = 'a';
            a[i][1] = a[1][i] = 1;
        }
    }
    cout << cost << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << b[i][j];
        cout << endl;
    }
    return 0;
}