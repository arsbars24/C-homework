#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
typedef long long LL;
const int maxn = 900;  
char LMap[maxn][maxn];  // map of labirinth 
bool vis[maxn][maxn];   // bool map 
int s[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }; // 4 ways to move
struct Node {
	int x, y, step;
};
queue<Node>Q;
bool Find(int i, int j) {
	Node st;
	int ret = 0;
	if (LMap[i - 1][j] == '#') {
		ret++;
	}
	if (LMap[i][j - 1] == '#') {
		ret++;
	}
	if (LMap[i + 1][j] == '#') {
		ret++;
	}
	if (LMap[i][j + 1] == '#') {
		ret++;
	}
	if (ret >= 3) {
		st.x = i; st.y = j; st.step = 0;
		Q.push(st);
		return true;
	}
	return false;
};
int n, m;
Node BFS() {  // breath-first search
	Node st, temp, en;
	en = Q.front();
	vis[en.x][en.y] = 1;
	while (!Q.empty()) {
		st = Q.front();
		Q.pop();
		if (st.step > en.step) {
			en = st;
		}
		int tmpx, tmpy;
		for (int i = 0; i < 4; i++) {
			temp.x = st.x + s[i][0];
			temp.y = st.y + s[i][1];
			if (temp.x <= 0 || temp.x > m ||
				temp.y <= 0 || temp.y > n ||
				LMap[temp.x][temp.y] == '#')
				continue;
			vis[temp.x][temp.y] = 1;
			temp.step = st.step + 1;
			Q.push(temp);
		}
	}
	return en;
}

int main() {
	cin >> n; cin >> m;
	while (!Q.empty()) Q.pop();
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> LMap[i][j];
		}
	};
	int flag = 0;
	for (int i = 1; i <= m; i++) {
		if (flag) break;
		for (int j = 1; j <= n; j++) {
			if (LMap[i][j] == '.' && flag == 0) {
				flag = Find(i, j);
			}
			if (flag) break;
		}
	}
	Node st = BFS();
	memset(vis, 0, sizeof(vis));
	st.step = 0;
	Q.push(st);
	Node en = BFS();
	cout << en.step;
	return 0;
};