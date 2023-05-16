#include "iostream"
#include "cmath"
using namespace std;
bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}
void ArrPN(int* arr1, int maxnum) {
    int number = 2, primeCounter = 0;
    while (primeCounter != maxnum) {
        if (isPrime(number)) {
            arr1[primeCounter] = number;
            primeCounter++;
        }
        number++;
    }
}
int main() {
    int n;
    cin >> n;
    int* input = new int[n];
    int maxnum = 0;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        if (input[i] > maxnum) maxnum = input[i];
    }
    int* arr1 = new int[maxnum];
    ArrPN(arr1, maxnum);
    for (int i = 0; i < n; i++) {
        cout << arr1[input[i] - 1] << endl;
    }
    return 0;
}




