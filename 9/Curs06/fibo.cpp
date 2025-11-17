#include <iostream>
using namespace std;

// Sirul lui Fibonacci recursiv - fara memoizare

int n;
int a[100001];

int fibo(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int main() {
    cin >> n;

    // fibo iterativ
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; ++i)
        a[i] = a[i - 1] + a[i - 2];

    for (int i = 0; i <= n; ++i)
        cout << i << ' ' << a[i] << '\n';

    cout << "recursiv\n";

    // fibo recursiv
    cout << fibo(n);
    return 0;
}