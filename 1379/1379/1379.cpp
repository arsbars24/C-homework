#include <vector>
#include <set>
#include <iostream>
using namespace std;
struct node;

struct edge {
    node* n;
    int c;
    int w;
};

struct node {
    vector<edge> v;
    int d;
    bool done;
} nodes[501];

const int inf = ((unsigned int)(~0) >> 1);

int solve(int w, int N) { // Dijkstra
    set<pair<int, int>> Q;

    for (int i = 1; i <= N; i++) {
        nodes[i].d = i == 1 ? 0 : inf;
        nodes[i].done = false;
        Q.insert({ nodes[i].d, i });
    }

    while (!Q.empty()) {
        int i = (*Q.begin()).second;

        auto node = nodes[i];
        node.done = true;
        Q.erase({ node.d, i });
        if (node.d > 1440)
            break;

        for (auto edge : node.v) {
            auto n = edge.n;
            if (n->done || w > edge.w)
                continue;

            if (node.d + edge.c < n->d) {
                Q.erase({ n->d, n - nodes });
                n->d = node.d + edge.c;
                Q.insert({ n->d, n - nodes });
            }
        }
    }

    return nodes[N].d;
}

int search(int l, int r, int N) { // Binary search
    do {
        const int m = (r + l) / 2 + 1;
        if (solve(m, N) > 1440)
            r = m - 1;
        else
            l = m;
    } while (l != r);
    return l;
}

int main() {
    int N, M;
    cin >> N >> M;

    while (M--) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        w = std::max(0, (w - 3000000) / 100); // Convert weight limit to cups limit
        nodes[u].v.push_back({ nodes + v, c, w });
        nodes[v].v.push_back({ nodes + u, c, w });
    }
    cout << search(0, 10000000, N);
}