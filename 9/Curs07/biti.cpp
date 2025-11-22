#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

/*
operatii pe biti :
& (si)
| (sau)
^ (xor) 
~ (not)

<< (shift la stanga)
>> (shift la dreapta)
*/

int n;

int main() {
    cin >> n;

    cout << "N inainte = " << n << '\n';
    for (int i = 1; i <= 33; ++i) {
        cout << (n << i) << "\n";
    }

    cout << "N dupa shift = " << (n << 32) << '\n';
    return 0;
}