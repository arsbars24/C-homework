#include<iostream>
using namespace std;
int main() {
    int n, f[1100];
    int i, j;
    char c[1100][250], tc[50], nc[5][50] = { "","Slytherin:", "Hufflepuff:", "Gryffindor:", "Ravenclaw:" };
    cin >> n;
    cin.getline(c[i], 1100);
    for (i = 1; i <= n; i++) {
        cin.getline(c[i], 1100);
        cin.getline(tc, 1100);
        if (tc[0] == 'S')f[i] = 1;
        else if (tc[0] == 'H')f[i] = 2;
        else if (tc[0] == 'G')f[i] = 3;
        else f[i] = 4;
    }
    for (i = 1; i <= 4; i++) {
        cout << nc[i] << endl;
        for (j = 1; j <= n; j++) {
            if (f[j] != i)continue;
            cout << c[j] << endl;
        }
        cout << endl;
    }
    system("pause");
}