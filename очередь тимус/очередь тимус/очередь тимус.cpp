#include <iostream>
using namespace std;

// сортировка индексов
// перестановка адресов
//структура

void bubbleSort(int** a, int* b, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; ++j) {
            if (a[b[i]][0] > a[b[i + 1]][0]) {
                int t = b[i];
                b[i] = b[i + 1];
                b[i + 1] = t;
            }
        }
    }

}

int main()
{
    int n;
    cin >> n;
    int* a = new int[n];
    int** s = new int*[n];
    for (int i = 0; i < n; ++i) {
        int* s = new int[3];
        a[i] = i;
        
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> s[i][j];
        }
    }
    bubbleSort(s, a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

