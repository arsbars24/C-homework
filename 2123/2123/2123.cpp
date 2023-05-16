#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using ull = unsigned long long;
ull v[60];

struct ans
{
    ull W; int i;

    size_t operator() (const ans& node) const {
        return hash<ull>()(node.W) ^ hash<int>()(node.i);
    }
    bool operator==(const ans& p) const { return W == p.W && i == p.i; }
};

unordered_map<ans, ull, ans> m; // Memo array

ull dfs(ull W, int i) { // Number of ways to make mass W with weights i and below
    if (m.find({ W, i }) != m.end()) // Already calculated
        return m[{W, i}];
    if (i < 0) // The end of the dfs, return 1 if we exhausted the weights and formed the mass
        return W == 0;
    if (v[i] < W / 4) // No way for two each of all remaining weights to form the mass
        return 0;

    ull sum = 0;
    for (ull k = 0; k <= 2; k++) // Number of weights of type i to use
        if (W >= k * v[i])
            sum += dfs(W - k * v[i], i - 1);
    return m[{ W, i }] = sum;
}

int main() {
    ull W, n, x;
    cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << dfs(W, n - 1);
}