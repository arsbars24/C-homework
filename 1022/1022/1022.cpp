#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
bool a[100][100];
queue <int> l, s;
int p, u[100], n, fr, o = 0;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        u[i] = 0;
        for (int j = 0; j < n; j++)
            a[i][j] = false;
    }
    for (int i = 0; i < n; i++)
    {
        p = 1;
        while (1 == 1)
        {
            cin >> p;
            if (p == 0)
                break;
            a[i][p - 1] = true;
            u[p - 1]++;
        }
    }
    for (int i = 0; i < n; i++)
        if (u[i] == 0)
            s.push(i);
    while (!s.empty())
    {
        o++;
        fr = s.front();
        s.pop();
        for (int i = 0; i < n; i++)
            if (a[fr][i])
            {
                u[i]--;
                if (u[i] == 0)
                    s.push(i);
            }
       cout << fr + 1;
        if (0 != n)
            cout << ' ';
    }
    /*cout << n;*/
    return 0;
}