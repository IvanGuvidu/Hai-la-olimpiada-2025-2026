#include <bits/stdc++.h>

using namespace std;

const int max_size = 1e5 + 20, rmax = 22;

int lvl[max_size], t[rmax][max_size], lg[max_size];
vector <int> mc[max_size];

void dfs (int nod, int par)
{
    lvl[nod] = lvl[par] + 1;
    for (auto f : mc[nod])
    {
        t[0][f] = nod;
        dfs(f, nod);
    }
}

int anc (int x, int ord)
{
    int e = 0;
    while (ord > 0)
    {
        if (ord % 2 == 1)
        {
            x = t[e][x];
        }
        ord /= 2;
        e++;
    }
    return x;
}

int lca (int x, int y)
{
    int e = lg[lvl[x]];
    while (e >= 0)
    {
        if (t[e][x] != t[e][y])
        {
            x = t[e][x];
            y = t[e][y];
        }
        e--;
    }
    return t[0][x];
}

void solve ()
{
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        mc[x].push_back(i);
    }
    dfs(1, 0);
    for (int i = 2; i <= n; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }
    for (int e = 1; e < rmax; e++)
    {
        for (int i = 1; i <= n; i++)
        {
            t[e][i] = t[e - 1][t[e - 1][i]];
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (lvl[x] > lvl[y])
        {
            swap(x, y);
        }
        y = anc(y, lvl[y] - lvl[x]);
        if (x == y)
        {
            cout << x << '\n';
        }
        else
        {
            cout << lca(x, y) << '\n';
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
    freopen("lca.in", "r", stdin);
    freopen("lca.out", "w", stdout);
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