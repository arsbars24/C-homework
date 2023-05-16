#include <iostream>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

int main() {
    string s;

    cin >> s;

    set<string> SET;      

    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j <= s.length() - i; j++) {
            SET.insert(s.substr(i, j));
            cout << s.substr(i, j) << " ";
        }
    }

    cout << SET.size() << endl;
    return 0;
}