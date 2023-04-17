#include <iostream>
#include <vector>
using namespace std;
int parent[100000];
int ssize[100000];
int n, m, k;

void make_set(int v) {
    parent[v] = v;
    ssize[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ssize[a] < ssize[b])
            swap(a, b);
        parent[b] = a;
        ssize[a] += ssize[b];
        k--;
    }
}

int main()
{
    cin >> n >> m;
    k = n;
    vector <pair <int, int>> edge;
    for (int i = 0; i < m; i++) {
        int a_t, b_t;
        cin >> a_t >> b_t;
        edge.push_back(make_pair(a_t, b_t));
    }
    for (int i = 0; i < n; i++) {
        ssize[i] = 1;
        parent[i] = i;
    }
    int q; cin >> q;
    vector <bool> arr_q(m, false);
    vector <int> num_edge;
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        arr_q[t - 1] = true;
        num_edge.push_back(t - 1);
    }
    for (int i = 0; i < m; i++) {
        if (!arr_q[i]) union_sets(edge[i].first, edge[i].second);
    }
    vector <int> res;
    for(int i = q - 1; i >= 0; i--) {
        res.push_back(k);
        union_sets(edge[num_edge[i]].first, edge[num_edge[i]].second);
    }
    for (int i = q - 1; i >= 0; i--) {
        cout << res[i] << ' ';
    }
}