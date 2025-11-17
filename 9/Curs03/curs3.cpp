#include <iostream>
using namespace std;

bool e_prim(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    int d;
    for (d = 5; d * d <= n; d += 6) {
        if (n % d == 0 && n % (d + 2) == 0)
            return false;
    }
    // 5 7 11 13 17 19 23 25
    return true;
}

void descompunere_prime(int n) {
    int exp = 0, div = 3;

    while (n % 2 == 0) {
       exp += 1;
        n /= 2;
    }

    if (exp > 0) {
        std::cout << 2 << ' ' << exp << '\n';
    }

    while (div * div <= n) {
        exp = 0;
        while (n % div == 0) {
            exp += 1, n /= div;
        }

        if (exp > 0) {
            std::cout << div << ' ' << exp << '\n';
        }

        div += 2;
    }

    if (n > 1) {
        std::cout << n << ' ' << 1 << '\n';
    }
}


int n;
int main() {
    cin >> n; 
    descompunere_prime(n);
    return 0;
}