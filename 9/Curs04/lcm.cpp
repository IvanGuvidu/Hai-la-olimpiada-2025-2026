#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        // cout << a << ' ' << b << '\n';
        int r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}

int gcd_recursive(int a, int b) {
    if (b == 0)
        return a;
    return gcd_recursive(b, a % b);
}

int main() {
    int a, b;

    cin >> a >> b;
    
    cout << "gcd function : " << std::__algo_gcd(18, 24) << '\n';

    cout << "lcm " << a / gcd(a, b) * b;
    return 0;
}