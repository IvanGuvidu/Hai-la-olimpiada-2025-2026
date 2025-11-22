#include <iostream>
using namespace std;

int n, x, cnt;

int main() {
    cin >> n;

    int i = 1, j;
    while (cnt != n) {
        for (j = i; j >= 1 && cnt != n; --j) {
            // cout << j << ' ';
            x = j;
            cnt++;
        }
        i++;
    }
    cout << x << '\n';
    return 0;
}