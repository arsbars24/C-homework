#include <iostream>
#include <string>
using namespace std;

#define N 5
bool Ok(int, int);
int direct[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int table[N][N];
char alph[N][N];
bool isword;

void SrchWord(string w, int i, int j, int k) {
	if (!isword) {
		k++;
		table[i][j] = k;
		if (k == w.length()) isword = true;
		for (int l = 0; l < 4; l++) {
			int x = i + direct[l][0];
			int y = j + direct[l][1];
			if (Ok(x, y) && (alph[x][y] == w[k])) SrchWord(w, x, y, k);
		}
		k--; table[i][j] = 0;
	}
}
bool Ok(int i, int j) {
	return (i >= 1) && (i < N) && (j >= 1) && (j < N) && (!table[i][j]);
}

int** Srch(char a, int& k) {
	int** symb = new int* [2];
	symb[0] = new int[16];
	symb[1] = new int[16];
	k = 0;
	for (int i = 1; i < N; i++)
		for (int j = 1; j < N; j++) 
			if (alph[i][j] == a) {
				symb[0][k] = i;
				symb[1][k] = j;
				k++;
			}
	return symb;
}

int main() {
	for (int i = 1; i < N; i++)
		for (int j = 1; j < N; j++)
			cin >> alph[i][j];
	string w;
	int n;
	cin >> n;
	string* words = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> w;
		words[i] = w;
	}
	int** symb;
	int count; 
	for (int i = 0; i < n; i++) {
		w = words[i];
		cout << w << ": ";
		for (int i = 1; i < N; i++)
			for (int j = 1; j < N; j++)
				table[i][j] = 0;
		symb = Srch(w[0], count);
		isword = false;
		while (count > 0 && !isword) {
			int x = symb[0][count - 1];
			int y = symb[0][count - 1];
			count--;

		}
	}
}