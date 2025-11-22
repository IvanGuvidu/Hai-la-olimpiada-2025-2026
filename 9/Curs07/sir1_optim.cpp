#include <iostream>
using namespace std;

int n, gauss = 0;

int main() {
    cin >> n;

    int i = 1;
    while (gauss + i < n) {
        gauss += i;
        i++;
    }
    cout << i - n + gauss + 1;
    return 0;
}