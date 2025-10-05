#include <bits/stdc++.h>

using namespace std;

const int max_size = 11;

int v[max_size], uz[max_size], n;

void afis ()
{
    for (int i = 1; i <= n; i++)
        cout << v[i] << ' ';
    cout << '\n';
}

void bkt (int k)
{
    if (k == n + 1)
    {
        afis();
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (uz[i] == 0)
        {
            v[k] = i;
            uz[i] = 1;
            bkt(k + 1);
            uz[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    bkt(1);
    return 0;
}