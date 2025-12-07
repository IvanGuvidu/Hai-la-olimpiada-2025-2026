#include <bits/stdc++.h>

using namespace std;

const long long max_size = 1e5 + 20, INF = 2e9 + 1;

vector <int> mc[max_size], invmc[max_size], topsort;
vector <vector <int>> ctc;
int viz[max_size];

void dfs (int nod)
{
    viz[nod] = 1;
    for (auto f : mc[nod])
    {
        if (viz[f] == 0)
        {
            dfs(f);
        }
    }
    topsort.push_back(nod);
}

void kos (int nod)
{
    viz[nod] = 0;
    ctc.back().push_back(nod);
    for (auto f : invmc[nod])
    {
        if (viz[f] == 1)
        {
            kos(f);
        }
    }
}

void solve ()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        mc[x].push_back(y);
        invmc[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (viz[i] == 0)
        {
            dfs(i);
        }
    }
    reverse(topsort.begin(), topsort.end());
    vector <int> aux;
    for (auto f : topsort)
    {
        if (viz[f] == 1)
        {
            ctc.push_back(aux);
            kos(f);
        }
    }
    cout << ctc.size() << '\n';
    for (auto f : ctc)
    {
        for (auto ff : f)
        {
            cout << ff << " ";
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
    freopen("ctc.in", "r", stdin);
    freopen("ctc.out", "w", stdout);
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