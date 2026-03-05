#include <bits/stdc++.h>

using namespace std;

const int max_size = 2e6 + 20, INF = 1e9 + 20;

int p[max_size];
string a, b;

void kmp ()
{
    int q = 0;
    for (int i = 2; i < a.size(); i++)
    {
        while (q > 0 && a[q + 1] != a[i])
        {
            q = p[q];
        }
        if (a[q + 1] == a[i])
        {
            q++;
        }
        p[i] = q;
    }
}

void solve ()
{
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = '$' + a;
    b = '$' + b;
    kmp();
    int q = 0;
    int ans = 0;
    vector <int> poz;
    for (int i = 1; i <= m; i++)
    {
        while (q > 0 && a[q + 1] != b[i])
        {
            q = p[q];
        }
        if (a[q + 1] == b[i])
        {
            q++;
        }
        if (q == n)
        {
            ans++;
            if (ans <= 1000)
            {
                poz.push_back(i - n);
            }
        }
    }
    cout << ans << '\n';
    for (auto f : poz)
    {
        cout << f << " ";
    }
    cout << '\n';
}

signed main ()
{
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    freopen("strmatch.in", "r", stdin);
    freopen("strmatch.out", "w", stdout);
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
