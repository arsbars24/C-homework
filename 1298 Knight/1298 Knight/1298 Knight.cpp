#include <iostream>
using namespace std;
char m[20][20] = { 1 }, o1[400] = { 0 }, o2[400] = { 0 }, dx[8] = { -2,-1,1,2,2,1,-1,-2 },
    dy[8] = { 1,2,2,1,-1,-2,-2,-1 }, n, nn;

void out() {
    int i;
    for (i = 0; i < nn; i++) { //printf("%c%c\n, o1[i] + 'a', o2[i] + '1');
        cout << o1[i] + 'a' << o2[i] + '1';
    }
    exit(0);
}

char Step(char x, char y, char l) {
    char i, j, c[8] = { 0 }, f = 0;
    if (l == nn)out();
    for (i = 0; i < 8; i++) {
        if (x + dx[i]<0 || x + dx[i]>n - 1 || y + dy[i]<0 || y + dy[i]>n - 1)c[i] = -1;
        else if (m[x + dx[i]][y + dy[i]])c[i] = -1;
        else {
            for (j = 0; j < 8; j++)
                if ((x + dx[i] + dx[j] >= 0 && x + dx[i] + dx[j] <= n - 1 && y + dy[i] + dy[j] >= 0
                        && y + dy[i] + dy[j] <= n - 1) && (m[x + dx[i] + dx[j]][y + dy[i] + dy[j]] == 0)) {
                    c[i]++;
                    break;
                }
            f = 1;
        }
    }
    if (f == 0 && l != nn - 1)return -1;
    for (i = 0; i <= 8; i++)
        for (j = 0; j < 8; j++) {
            if (c[j] == i) {
                m[x + dx[j]][y + dy[j]] = 1;
                o1[l] = x + dx[j];
                o2[l] = y + dy[j];
                if (Step(x + dx[j], y + dy[j], l + 1) == -1) {
                    m[x + dx[j]][y + dy[j]] = 0;
                    return 0;
                }
                else m[x + dx[j]][y + dy[j]] = 0;
            }
        }
    return 0;
}
int main() {
    //scanf("%d", &n)
    cin >> n;
    nn = n * n;
    Step(0, 0, 1);
    cout << "Impossible";
}