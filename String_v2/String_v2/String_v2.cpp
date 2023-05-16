#include <iostream>
#include <string> 

using namespace std;

int main() {

    int n, m;
    string s, s1, s2;
    cout << "Enter the 1-st string:\n";
    getline(cin, s1);
    cout << "Enter the 2-nd string:\n";
    getline(cin, s2);
    m = s1.size();
    n = s2.size(); // string input
    int** a = new int* [m + 1];
    for (int i = 0; i < m + 1; i++) {
        a[i] = new int[n + 1];
    }
    for (int j = 0; j <= n; j++) {
        a[0][j] = 0;
    }
    for (int i = 0; i <= m; i++) {
        a[i][0] = 0;
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (s1[i - 1] == s2[j - 1])
                a[i][j] = a[i - 1][j - 1] + 1;
            else
                a[i][j] = 0;
        }
    }// matrix of values
   
    for (int j = 0; j <= n; j++) {
        for (int i = 0; i <= m; i++) {
            cout.width(2);
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    s = "";
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] > s.size())
                s = s1.substr((i - a[i][j] + 1) - 1, a[i][j]);
        }
    }
    cout << "\nTarget substring: " << s << "\n\n";
    for (int i = 0; i < m + 1; i++) {
        delete[] a[i];
    }
    delete[] a;
    system("pause");
    return 0;
}