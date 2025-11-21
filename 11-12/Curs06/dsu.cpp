#include <bits/stdc++.h>

using namespace std;

const int max_size = 1e5 + 20, rmax = 20;

int t[max_size];

int rad (int x)
{
    if (x == t[x])
    {
        return x;
    }
    return t[x] = rad(t[x]);
}

void solve ()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        t[i] = i;
    }
    while (m--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        int rx = rad(x), ry = rad(y);
        if (op == 1)
        {
            t[rx] = ry;
        }
        else
        {
            if (rx == ry)
            {
                cout << "DA";
            }
            else
            {
                cout << "NU";
            }
            cout << '\n';
        }
    }
    cout << '\n';
}

signed main ()
{
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    freopen("disjoint.in", "r", stdin);
    freopen("disjoint.out", "w", stdout);
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