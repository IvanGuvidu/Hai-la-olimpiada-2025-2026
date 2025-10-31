#include <bits/stdc++.h>

using namespace std;

struct str{
    int nod, cost;
    bool operator < (const str & aux) const
    {
        return cost > aux.cost;
    }
};

const int max_size = 5e4 + 20, INF = 2e9 + 2;

int d[max_size];
vector <pair <int, int>> mc[max_size];
priority_queue <str> pq;

void djk ()
{
    pq.push({1, 0});
    while (!pq.empty())
    {
        int nod = pq.top().nod, cost = pq.top().cost;
        pq.pop();
        if (cost > d[nod])
        {
            continue;
        }
        for (auto f : mc[nod])
        {
            if (d[nod] + f.second < d[f.first])
            {
                d[f.first] = d[nod] + f.second;
                pq.push({f.first, d[f.first]});
            }
        }
    }
}

void solve ()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int x, y, c;
        cin >> x >> y >> c;
        mc[x].push_back({y, c});
    }
    for (int i = 2; i <= n; i++)
    {
        d[i] = INF;
    }
    djk();
    for (int i = 2; i <= n; i++)
    {
        if (d[i] == INF)
        {
            d[i] = 0;
        }
        cout << d[i] << " ";
    }
    cout << '\n';
}

signed main ()
{
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    freopen("dijkstra.in", "r", stdin);
    freopen("dijkstra.out", "w", stdout);
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
