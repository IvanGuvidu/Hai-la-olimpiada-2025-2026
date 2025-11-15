#include <bits/stdc++.h>

using namespace std;

const long long max_size = 2e6 + 20, mod = 1999999973;

int lgput (long long baza, long long ord)
{
    long long ans = 1;
    while (ord > 0)
    {
        if (ord % 2 == 1)
        {
            ans = (ans * baza) % mod;
        }
        baza = (baza * baza) % mod;
        ord /= 2;
    }
    return ans;
}

void solve ()
{
    long long n, p;
    cin >> n >> p;
    cout << lgput(n, p);
    cout << '\n';
}

signed main ()
{
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    freopen("lgput.in", "r", stdin);
    freopen("lgput.out", "w", stdout);
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
