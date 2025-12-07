#include <bits/stdc++.h>

using namespace std;

const int max_size = 5e4 + 20, INF = 2e9 + 1;

vector <pair <int, int>> mc[max_size];
queue <int> q;
int viz[max_size], n, dist[max_size];

bool bf ()
{
    for (int i = 2; i <= n; i++)
    {
        dist[i] = INF;
    }
    q.push(1);
    while (!q.empty())
    {
        int nod = q.front();
        q.pop();
        viz[nod]++;
        if (viz[nod] == n + 1)
        {
            return false;
        }
        for (auto f : mc[nod])
        {
            if (dist[nod] + f.second < dist[f.first])
            {
                dist[f.first] = dist[nod] + f.second;
                q.push(f.first);
            }
        }
    }
    return true;
}

void solve ()
{
    int m;
    cin >> n >> m;
    while (m--)
    {
        int x, y, c;
        cin >> x >> y >> c;
        mc[x].push_back({y, c});
    }
    if (!bf())
    {
        cout << "Ciclu negativ!";
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            cout << dist[i] << " ";
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
    freopen("bellmanford.in", "r", stdin);
    freopen("bellmanford.out", "w", stdout);
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