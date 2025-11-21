#include <bits/stdc++.h>

using namespace std;

const long long max_size = 2e5 + 20;

struct str{
    int x, y, c;
    bool operator < (const str & aux) const
    {
        return c < aux.c;
    }
};

vector <pair <int, int>> apm;
vector <str> mc;
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
    while (m--)
    {
        int x, y, c;
        cin >> x >> y >> c;
        mc.push_back({x, y, c});
    }
    for (int i = 1; i <= n; i++)
    {
        t[i] = i;
    }
    int ans = 0;
    sort(mc.begin(), mc.end());
    for (auto f : mc)
    {
        int rx = rad(f.x), ry = rad(f.y);
        if (rx != ry)
        {
            t[rx] = ry;
            apm.push_back({f.x, f.y});
            ans += f.c;
        }
    }
    cout << ans << '\n' << n - 1 << '\n';
    for (auto f : apm)
    {
        cout << f.first << " " << f.second << '\n';
    }
    cout << '\n';
}

signed main ()
{
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    freopen("apm.in", "r", stdin);
    freopen("apm.out", "w", stdout);
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