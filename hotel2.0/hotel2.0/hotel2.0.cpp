#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int** a = new int* [n]; 
    for (int i = 0; i < n; i++) { //array size of n consisting of 0
        a[i] = new int[n]; 
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    
    int cur = 0; // currency
    for (int c = 0; c < n * 2 - 1; ++c) {
        for (int i = 0; i < n; ++i) {
            int j = c - i;
            if (0 <= j && j < n)
                a[i][n - 1 - j] = ++cur;
           // cout << '_' << c << '_' << i << '_' << j << '_' << n - 1 - j << endl;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
        
    }
    return 0;
}