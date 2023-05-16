#include <iostream>
using namespace std;

void swap(long int* a, long int* b) {
    long long int tmp = *a;
    *a = *b;
    *b = tmp;
}

long int gcd(long int a,long int b) {
    if (a < b) {
        swap(&a, &b);
    }
    while (a % b != 0) {
        a = a % b;
        swap(&a, &b);
    }
    return b;
}

int main() {
	long long int n, k;
    long long int c = 0;
    long long int C = 0;
    long long int a = 0;
	cin >> n;
    for (int i = 1; i < (n / 2) + 1; i++) {
        k = n - i;
        c = gcd(k, n);
        if (c == 1)
            continue;
        else if (c > C)
            C = c;
        a = k;
    }
    cout << a << ' ' << n - a;

}