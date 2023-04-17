#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int a[10][10], n, i, j, h[99];
	int f[] = { 1,-1,1,-1,1,-1,1,-1,1,-1 };
	cin >> n;

	for (i = 1; i <= n * n; i++) cin >> h[i];
	sort(h + 1, h + n * n + 1);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			a[(n + 1) / 2 + f[i] * (i / 2)][(n + 1) / 2 + f[j] * (j / 2)] = h[n * n - (i * n + j - n) + 1];
		}
	}
		
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}
