#include <bits/stdc++.h>

using namespace std;

const int max_size = 25;

int v[max_size], pos;

void afis ()
{
    if (pos == 0)
        return;
    for (int i = 1; i <= pos; i++)
        cout << v[i] << ' ';
    cout << '\n';
}

void bkt (int k, int n)
{
    if (k == n + 1)
    {
        afis();
        return;
    }
    pos++;
    v[pos] = k;
    bkt(k + 1, n);
    pos--;
    bkt(k + 1, n);
}

int main ()
{
    int n;
    cin >> n;
    bkt(1, n);
    return 0;
}