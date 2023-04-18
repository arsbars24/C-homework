#include <iostream>
using namespace std;


int main()
{
    int num;
    cin >> num; 
    

    int n1, n2, n3, n4, n5, n6;
    n1 = num / 100000;
    n2 = num / 10000 - n1 * 10;
    n3 = num / 1000 - n1 * 100 - n2 * 10;
    n4 = num / 100 - n1 * 1000 - n2 * 100 - n3 * 10;
    n5 = num / 10 - n1 * 10000 - n2 * 1000 - n3 * 100 - n4 * 10;
    n6 = num - n1 * 100000 - n2 * 10000 - n3 * 1000 - n4 * 100 - n5 * 10;
    cout << n1 << endl << n2 << endl << n3 << endl << n4 << endl << n5 << endl << n6 << endl;

    if (n1 + n2 + n3 == n4 + n5 + n6 + 1 && n6 != 9) {
        cout << "Yes" << endl;
    }
    else if ((n1 + n2 + n3 == n4 + n5 + n6 - 1) && n5 != 0 && n6 != 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}

