#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, k, i, j, s, l, a[1000];
    cin >> n >> k;
    for (i = 1; i <= n; i++){
        if ((n + i - 1) / i == k)
            break;
    }
    for (j = 0; j < n; j++)
        cin >> a[j];
    for (s = 0; s < i; s++) {
        l = s;
        cout << std::setw(4) << a[l];
        l += i;
        while (l < n) {
            cout << std::setw(4) << a[l];
            l += i;
        }
        cout << "\n";
    }
}