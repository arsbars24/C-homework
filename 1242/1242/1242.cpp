#include <iostream> 
#include <vector> 
#include <stdio.h>

using namespace std;
char c[1010][1010] = { 0 }, m[1010] = { 0 };
int n;
void dfs(int p) {
    int i;
    if (m[p] == 1)return;
    m[p] = 1;
    for (i = 1; i <= n; i++) if (c[i][p] == 1) dfs(i);
}
void ufs(int p) {
    int i;
    if (m[p] == 1)return;
    m[p] = 1;
    for (i = 1; i <= n; i++) if (c[i][p] == -1) ufs(i);
}
int main() {
    char in[20];
    int i, a, b;
    cin >> n;
    while (1) {
        cin >> in;
        if (in[0] == 'B')break;
        a = atoi(in);
        cin >> b;
        c[a][b] = 1;
        c[b][a] = -1;
    }
    do {
        cin >> a;
        dfs(a);
        m[a] = 0;
        ufs(a);
    } while (a != EOF);
    a = -1;
    for (i = 1; i <= n; i++) if (m[i] == 0) cout << a;
    if (a == -1) cout << "0";
}