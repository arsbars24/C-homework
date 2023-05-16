#include <iostream>
#include <string>
using namespace std;


int main()
{
    int N;
    string t;
    cin >> N;
    string* s = new string[N];
    for (int i = 0; i < N; i++) {
        getline(cin, t);
    }
    
    int count = 0;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (s[i] == s[j]) {
                count++;
            }
        } 
    }
    cout << count;
}

