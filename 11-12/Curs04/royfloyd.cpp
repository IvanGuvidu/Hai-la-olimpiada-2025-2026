#include <bits/stdc++.h>

using namespace std;

const int max_size = 1e2 + 20, INF = 1e9 + 2;

int a[max_size][max_size];

void solve ()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 0)
            {
                a[i][j] = INF;
            }
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == INF)
            {
                a[i][j] = 0;
            }
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

signed main ()
{
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    freopen("royfloyd.in", "r", stdin);
    freopen("royfloyd.out", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long tt;
    //cin >> tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }
    return 0;
}