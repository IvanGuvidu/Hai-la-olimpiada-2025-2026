#include <iostream>
using namespace std;

// Algoritmul lui Euclid

int main() {
    int a, b;

    cin >> a >> b;

    while (b != 0) {
        // cout << a << ' ' << b << '\n';
        int r = a % b;
        a = b;
        b = r;
    }
    
    cout << "\n" << a << '\n';
    return 0;
}