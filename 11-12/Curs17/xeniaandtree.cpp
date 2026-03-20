#include <bits/stdc++.h>

using namespace std;

const long long max_size = 1e5 + 20, INF = 2e9 + 2, mod = 1e9 + 7, rmax = 20;

int t[max_size], viz[max_size], sz[max_size], lvl[max_size], rmq[rmax][2 * max_size], lg[2 * max_size], timp, dp[max_size], poz[max_size];
vector <int> mc[max_size];

void dfslca (int nod, int par)
{
    ++timp;
    poz[nod] = timp;
    rmq[0][timp] = nod;
    dp[nod] = lvl[nod];
    for (auto f : mc[nod])
    {
        if (f == par)
        {
            continue;
        }
        lvl[f] = lvl[nod] + 1;
        dfslca(f, nod);
        rmq[0][++timp] = nod;
    }
}

bool cmp (int x, int y)
{
    return lvl[x] < lvl[y];
}

void dfssz (int nod, int par)
{
    sz[nod] = 0;
    for (auto f : mc[nod])
    {
        if (f == par || viz[f])
        {
            continue;
        }
        dfssz(f, nod);
        sz[nod] += sz[f];
    }
    sz[nod]++;
}

int centroid (int nod, int par, int total)
{
    for (auto f : mc[nod])
    {
        if (viz[f] == 1 || f == par)
        {
            continue;
        }
        if (2 * sz[f] > total)
        {
            return centroid(f, nod, total);
        }
    }
    return nod;
}

void dfsc (int nod, int par)
{
    dfssz(nod, 0);
    int c = centroid(nod, 0, sz[nod]);
    viz[c] = 1;
    t[c] = par;
    for (auto f : mc[c])
    {
        if (viz[f] == 1)
        {
            continue;
        }
        dfsc(f, c);
    }
}

int dist (int x, int y)
{

    int xx = poz[x];
    int yy = poz[y];
    if (xx > yy)
    {
        swap(xx, yy);
    }
    int diff = yy - xx + 1, e = lg[diff], lca = min(rmq[e][xx], rmq[e][yy - (1 << e) + 1], cmp);
    return lvl[x] + lvl[y] - 2 * lvl[lca];
}

void solve ()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        mc[x].push_back(y);
        mc[y].push_back(x);
    }
    dfslca(1, 0);
    for (int i = 2; i <= timp; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }
    for (int e = 1; e < rmax; e++)
    {
        for (int i = 1; i + (1 << e) - 1 <= timp; i++)
        {
            rmq[e][i] = min(rmq[e - 1][i], rmq[e - 1][i + (1 << (e - 1))], cmp);
        }
    }
    dfsc(1, 0);
    while (q--)
    {
        int op, x;
        cin >> op >> x;
        if (op == 1)
        {
            int nod = x;
            while (nod != 0)
            {
                dp[nod] = min(dp[nod], dist(nod, x));
                nod = t[nod];
            }
        }
        else
        {
            int nod = x, ans = INF;
            while (nod != 0)
            {
                ans = min(ans, dp[nod] + dist(nod, x));
                nod = t[nod];
            }
            cout << ans << '\n';
        }
    }
    cout << '\n';
}

signed main ()
{
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
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